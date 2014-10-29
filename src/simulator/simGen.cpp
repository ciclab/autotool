#include <iostream>
#include "ir.h"
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <string>
#include "hash.h"
#include <queue>

#include "def.h"
#include "common/utility.h"

using namespace std;

// record type used, first -> length of type, second -> signed
static unordered_set<string> typeSet;
static unordered_map<string,int> stageMap;
static unordered_map<string,string> varTypeMap;
// generate mem.cpp file 
void memGen(Ir &ir, ofstream &outh, ofstream &outc);

// generate reg.cpp file
void regGen(Ir &ir, ofstream &outh, ofstream &outC);

// generate pipeline data struct
void pipelineGen(Ir &ir, ofstream &out);

// generate class for each instruction
void classGen(Ir &ir, ofstream &out);

// generate C code from do_content 
void dfsGenCCode( do_content & d, ofstream & out, int lev );
// record clock info in each do
vector< pair<string,int> > timCnt;
// for example
// ( do
//  ( stage_1
//   ( clock 1 )
//   ( call read .. 2 )
//   ... )
//  ( stage_1
//   ( clock 1 )
//   ... )
//  ( stage_2
//   ( clock 1 )
//   ... )
//  ...)
// stage_1 and stage_2 uses 3 and 1 clock respectively.
// if there are other function call cost clocks, there are sumed.
// however clock for same name with different entry are parallely counted


// suppose d is an right-value, 
// return typename of it
string getTypeName( do_content &d );

// generate stage datatype
void stageGen(Ir &ir, ofstream &outh, ofstream &outc);

// // generate functions for enum, called by en;
// void enumFuncGen(Ir &ir, ofstream &out);

string autoType(int width, bool sig);

// generate typedef for each type
void typeDefGen( ofstream &);

// generate variable used by simulator
void varGen( ofstream &outh, ofstream & outc );

// hash_control hc_unfold_sim;
// vector<vector<triple > > unfolded_list_sim;
// vector<instr_type> u_l_t;
// vector<string> unfolded_list_name_sim;// name of rule of corresponding unfolded_list
// class hash_control hc_sim;
// vector<Asem> do_content_sim;

// class hash_control & Asem::hc_unfold=hc_unfold_sim;
// vector<Asem> & Asem::do_content = do_content_sim;
// vector<vector<triple > > & Asem::unfolded_list=unfolded_list_sim;
// vector<instr_type> &Asem::unfolded_list_type=u_l_t;
// vector<string> & Asem::unfolded_list_name=unfolded_list_name_sim;// name of rule of corresponding unfolded_list
// class hash_control & Asem::hc=hc_sim;


int main(int argc, char *argv[])
{
  if( argc != 3 )
    {
      cerr << " usage: " << argv[0] << " inputFile outputFile" << endl;
    }
  else
    {
      Ir ir;
      ifstream fin;

      fin.open(argv[1]);
      ir.read_all(fin);

      ofstream memOutH("mem.h");
      ofstream memOutC("mem.c");
      memGen(ir, memOutH, memOutC);

      ofstream regOutH("reg.h");
      ofstream regOutC("reg.c");
      regGen(ir, regOutH, regOutC);
      
      ofstream pipelineOut("pipeline.h");
      pipelineGen(ir, pipelineOut);

      // called before classGen
      ofstream stageOutC("stage.c");
      ofstream stageOutH("stage.h");
      stageGen( ir, stageOutH, stageOutC);
      
      ofstream classOut("class.h");
      classGen(ir, classOut);
      
      // file include typedef
      // used by function autoType()
      // this should be called in the last 
      ofstream typeOut("type.h");
      typeDefGen( typeOut );

      ofstream varOutC("vars.cpp");
      ofstream varOutH("vars.h");
      varGen( varOutH, varOutC);
    }
  return 0;
}

void varGen( ofstream &outh, ofstream &outc )
{
  // reg, mem, pipeline should be processed first
  // generate container for assign expression 
  outh << "#ifndef VAR_H\n";
  outh << "#define VAR_H\n";
  outh << "#include <queue>\n";
  outh << "#include <utility>\n";
  outh << "#include \"type.h\"\n";
  outh << "using namespace std;\n";
  outh << "void varUpdate();\n";
  outc << "#include \"vars.h\"\n";
  for( auto i : typeSet )
    {
      outh << "extern queue < pair< " << i << "*, " << i 
	   << " > >" << i << "Que;\n" ;
      outc << " queue < pair< " << i << "*, " << i << 
	" > >" << i << "Que;\n";
    }
  outh << "#endif\n";
  outc << "void varUpdate()\n";
  outc << "{\n";
  for( auto i : typeSet )
    {
      string queName = i + (string)"Que";
      outc << "for( ; !" << queName << ".empty(); )\n";
      outc << "{\n";
      outc << " auto i = " << queName << ".front();\n";
      outc << queName << ".pop();\n";
      outc << " *(i.first) = i.second;\n";
      outc << "}\n";
    }
  outc << "}";
}

void memGen(Ir &ir, ofstream & outh, ofstream & outc)
{
  outh << "#ifndef MEM_H\n";
  outh << "#define MEM_H\n";
  outh << "#include \"type.h\"\n";
  outc << "#include \"mem.h\"\n";
  int num = ir.get_num_mem();
  for( int i = 0; i < num; ++i )
    {
      string name = ir.get_mem_name(i);
      int size = ir.get_mem_size(i);
      int width = ir.get_mem_width(i);
      string typeName = autoType(width, 0);
      // associate name of mem to type name
      varTypeMap[name] = typeName;

      // // TODO size information
      // outh << "extern " << typeName << "*" << name << ';' << endl;
      // outc << typeName << "*" << name << ';' << endl;
      outh << "extern " << typeName << " " << name << " [ "<< size << " ];" << endl;
      outc << typeName << " " << name << " [ "<< size << " ];" << endl;
    }
  outh << "#endif\n";
}
string autoType(int width, bool sig)
{
  // typeSet.insert( make_pair( width, sig ? 1 : 0 ) );
  string r;
  for( ; width; width /= 10)
    r += (char)(width % 10 + '0');
  reverse( r.begin(), r.end() );
  if( sig )
    r = "sint" + r;
  else r = "uint" + r;
  typeSet.insert(r);
  return r;
}

void regGen(Ir &ir, ofstream &outh, ofstream &outc)
{
  outh << "#ifndef REG_H\n";
  outh << "#define REG_H\n";
  outh << "#include \"type.h\"\n";
  outc << "#include \"reg.h\"\n";
  int num = ir.get_num_reg();
  for( int i = 0; i < num; ++i )
    {
      string name = ir.get_reg_name(i);
      int size = ir.get_reg_size(i);
      int width = ir.get_reg_width(i);
      string typeName = autoType( width, true);

      varTypeMap[name] = typeName;

      if( size > 1 )
	{
	  outh << "extern " << typeName << ' ' << name << " [ " << size << " ];" << endl;
	  outc << typeName << ' ' << name << " [ " << size << " ];" << endl;
	}
      else
	{
	  outh << "extern " << typeName << ' ' << name << ";" << endl;
	  outc << typeName << ' ' << name << ";" << endl;
	}
    }
  outh << "#endif\n";
}

void pipelineGen(Ir &ir, ofstream &out)
{
  out << "#include \"type.h\"\n";
  int num = ir.get_num_pipeline();
  for( int i = 0; i < num; ++i )
    {
      string name = ir.get_name_pipeline(i);
      out << " struct " << " \n{";
      int m = ir.get_ele_num_pipeline(i);
      for( int j = 0; j < m; ++j )
	{
	  string tName = ir.get_ele_name_pipeline( i, j);
	  int width = ir.get_ele_width_pipeline( i, j);
	  string typeName = autoType( width, true);

	  varTypeMap[ name + (string)"." + tName ] = typeName;
	  out << typeName << ' ' << tName << ';' << endl;
	}
      out << "}" << name << ";" << endl;
    }
}

// someting like asGen.cpp/main()
void classGen(Ir &ir, ofstream &out)
{
  int instrSize = ir.get_instr_size();
  string topRuleName = ir.get_top_rule_name();
  
  string topRule = ir.get_top_rule_name();
  vector<bool> used;
  used.resize(instrSize);
  fill( used.begin(), used.end(), false);
  unordered_set<string> packSubRuleName;
  for( int i = 0; i < instrSize; ++i )
    {
      string name = ir.get_instr_name(i);
      if( name.compare( 0, topRuleName.length(), topRuleName) == 0 )
	{
	  used[i] = true;
	  if( ir.get_instr_type(i) == "e_pack" )
	    {
	      vector< pair< string, string > > args;
	      ir.get_instr_arglist( i, args);
	      for( auto i : args )
		{
		  for( auto j = i.second.begin(); j != i.second.end(); ++j )
		    {
		      string subRuleName;
		      for( ; j != i.second.end() && *j != c_sep; ++j )
		      	subRuleName += *j;
		      packSubRuleName.insert( subRuleName );
		      if( j == i.second.end() )
			break;
		    }
		}
	    }
	}
    }
  for( int i = 0; i < instrSize; ++i )
    if( !used[i] )
      {
	string name = ir.get_instr_name(i);
	if( packSubRuleName.find(name) != packSubRuleName.end() )
	  used[i] = true;
      }
  int vliwModeOff, vliwModeSig;
  bool vliwModeSet = ir.get_vliw_mode( vliwModeSig, vliwModeOff );
  out << "#ifndef CLASS_H\n";
  out << "#define CLASS_H\n";
  out << "#include \"type.h\"\n";
  // TODO include cstdio for debugging
  out << "#include <cstdio>\n";
  out << "#include \"simlib.h\"\n";
  out << "#include <cstdlib>\n#include <cassert>\ntypedef long long ll;\n#include \"stage.h\"\n#define WST(a) ( (a) = (a) )\n\n";
  out << "#include \"reg.h\"\n";
  out << "#include \"pipeline.h\"\n";
  out << "#include \"vars.h\"\n";
  out << "class _class_instr_\
{\
public:\n";
  out << " int slotId;\n";
  out << " bool doOk;\n";
  out << " enum stage stg;\n";
  // int stageNum = ir.get_num_stage();
  // for( int i = 0; i < stageNum; ++i )
  //   {
  //     string stageName = ir.get_stage_name(i);
  //     out << "int " << stageName << "_active\n;";
  //   }
  out <<"virtual void init (char *c){};		\
  virtual bool Do (){};\
};\n" ;

  // out << "pipe
  // output class for each instruction
  for( int i = 0 ; i < instrSize; ++i )
    {
      if( !used[i] )
	continue;
      string ruleName = ir.get_instr_name(i);
      string ruleType = ir.get_instr_type(i);
      if( ruleType == "e_notpack" )
	{
	  out << "class class_" << ruleName << " : public _class_instr_ {\n ";
	  out << " public : \n ";
	  
	  vector<string> varName;
	  ir.get_instr_var_name( i, varName);
	  // for every class define its own variable
	  for( auto i : varName)
	    {
	      // TODO long long should be an adhoc type
	      out << "long long " << i << ";" << endl;
	    }
	  out << " void init( char *c)\n{\n";
	  out << "WST(c);\n";
	  string ruleBinary = ir.get_instr_binary(i);
	  string ruleRevBinary = ruleBinary;
	  string ruleRevBinaryBeg = ruleBinary;
	  // same as asGen.cpp
	  if( vliwModeSet )
	    {
	      assert( vliwModeSig == 1 );
	      if( ruleBinary.length() )
		{
		  assert( (int)ruleBinary.length() > vliwModeOff );
		  assert( vliwModeSig == 1 );
		  assert( ruleBinary[ vliwModeOff ] == '0' );
		  ruleRevBinaryBeg[ vliwModeOff ] = '1';
		}
	    }
#ifdef LITTLE_END
	  for( int i = 0, j = ruleRevBinary.length() - 8; i < j; 
	       i +=8, j -= 8 )
	    {
	      for( int k = 0 ; k < 8; ++k )
		{
		  swap( ruleRevBinary[ i + k ], ruleRevBinary[ j + k ] );
		  swap( ruleRevBinaryBeg[ i + k ], ruleRevBinaryBeg[ j + k ] );
		}
	    }
#endif
	  assert( ( ruleRevBinary.length() % 8 ) == 0 );
	  out << "char tmp[ " << ruleBinary.length() << " ];" << endl;
	  // out << " assert(tmp);\n ";
	  // out << " WST(c);\n ";
	  // out << " assert( !tmp );\n " << endl;
	  // out << " assert( !c );\n" << endl;

	  for( int j = 0; j < (int)ruleRevBinary.length(); ++j )
	    {
	      if( ruleRevBinary[j] == '-' )
		{
		  out << "tmp[";
		  int pos = ( ruleRevBinary.length() / 8 - 1 - j / 8 ) * 8
		    + ( j % 8 );
		  out << pos << "] = c[ " << j << " ];\n";
		}
	    }
	  vector<int> varLen;
	  ir.get_instr_var_len( i, varLen);
	  vector<pair<int,int> > varOff;
	  ir.get_instr_off( i, varOff);
	  assert( varOff.size() == varLen.size() && 
		  varOff.size() == varName.size() );
	  out << "//// " << ruleBinary << endl;
	  for( int j = 0; j < (int)varOff.size(); ++j )
	    {
	      out << "set_val( " << varName[j] << ", tmp + " << varOff[j].second << ", " << varLen[j] << ");\n";
	    }
	  out << "};\n";

	  // generate do function for each instruction
	  vector<do_content> doCnt;
	  ir.get_do_content(i, doCnt);
	  out << "bool Do(){\n" << endl;
	  out << " doOk = true;\n ";
	  for( auto i : doCnt )
	    {
	      // iterator over all content in do_content
	      // index start from 1, 0 -> "do" 
	      for( int j = 1; j < (int)i.ivec.size(); ++j )
		{
		  // stage name, without quote
		  assert( i.ivec[j].is_vector() &&
			  i.ivec[j].ivec.size() > 0 );
		  auto vec = i.ivec[j].ivec;
		  assert( vec[0].is_str1() );
		  string stageName = vec[0].str;
		  // ._active is generated for each class
		  // out << " if( " << stageName << "_active" << " ) " << endl;
		  out << " for ( ;" << stageName << " == stg; )\n ";
		  out << "{\n" ;
		  for( int k = 1; k < (int)vec.size(); ++k )
		    {
		      auto t = vec[k];
		      if( t.is_vector() && t.ivec[0].is_str1() &&
			  t.ivec[0].str == "clock" )
			{
			  // // update cycle count 
			  out << " if( -- " << stageName << "_clock > 0 ) {";
			  out << " doOk = false;\n";
			  out << " break;\n} ";
			  timCnt.push_back( make_pair( stageName +
						       (string)"_clock",
						       str2int(t.ivec[1].str) ) );
			}
		      else
			{
			  dfsGenCCode( t, out, 0 );
			}
		    }
		  out << " break;\n ";
		  out << "}\n" ;
		}
	    }
	  out << "return doOk;\n";
	  out << "};\n" << endl;

	  for( auto i : timCnt )
	    {
	      string clockName = i.first;
	      out << "int " << clockName << ";\n";
	    }

	  out << "class_" << ruleName << "(){\n";
	  for( auto i : timCnt )
	    {
	      string clockName = i.first;
	      int clockNum = i.second;
	      out << clockName << " = " << clockNum << ";\n" << endl;
	    }
	  timCnt.resize(0);
	  out << "};\n";
	  // end of class definition
	  out << "};\n";
	}
      // here we don't check for binary invalidity
      // see asGen.cpp/checkBianry(5) for detail
      
    }
  out << "#endif" << endl;
}

// void enumFuncGen(Ir &ir, ofstream &out)
// {
//   int enumSize = ir.get_num_enum();
//   for( int i = 0; i < enumSize; ++i)
//     {
//       Enum enu;
//       ir.get_enum(i, enu);
//       int entrySize = enu.size();
//       int width = enu.width();
//       string name = enu.enum.name();
//       out << " int FUNC_" << name << "(int)\n{";
//       out << " 
//     }
// }

void dfsGenCCode( do_content & d, ofstream & out, int lev )
{
  if( d.is_str1() )
    {
      out << d.str ;
    }
  else if( d.is_vector() )
    {
      assert( d.ivec.size() > 0 );
      if( d.ivec[0].is_vector() )
	{
	  out << "{\nbool __ok" << lev + 1 << " = true;\n";
	  for( auto i : d.ivec )
	    {
	      out << " for( ;__ok" << lev + 1 << "; ){\n";
	      dfsGenCCode( i, out, lev + 1 );
	      out << "break;\n";
	      out << "}\n";
	    }
	  out << " doOk = ( doOk && __ok" << lev + 1 << ") ;\n";
	  out << "}\n";
	}
      else
	{
	  // equal test expression
	  // ( eq A B )
	  // ( ( A ) == ( B ) )
	  if( d.ivec[0].str == "eq" )
	    {
	      assert( d.ivec.size() == 3 );
	      out << " ( ";
	      out << " ( ";
	      dfsGenCCode( d.ivec[1], out, lev + 1);
	      out << " ) ";
	      out << " == ";
	      out << " ( ";
	      dfsGenCCode( d.ivec[2], out, lev + 1);
	      out << " ) ";
	      out << " ) ";
	      out << endl;
	    }
	  // condition expression
	  // ( if ( cond ) ( true_action ) ( false_ action ) )
	  // if ( cond ) { treu_action } else { false_action }
	  else if( d.ivec[0].str == "if" )
	    {
	      assert( d.ivec.size() > 2 );
	      out << " if ( " ;
	      dfsGenCCode( d.ivec[1], out, lev + 1 );
	      out << " ) ";
	      out << " { ";
	      dfsGenCCode( d.ivec[2], out, lev + 1 );
	      out << " } ";
	      if( d.ivec.size() > 3 )
		{
		  out << " else \n{ \n";
		  for( int j = 3; j < (int)d.ivec.size(); ++j )
		    {
		      dfsGenCCode( d.ivec[j], out, lev + 1);
		    }
		  out << " }\n";
		}
	    }
	  // assignment expression
	  // assignment is fullfilled at commit ( compared with assign )
	  // ( = to from )
	  // to = from
	  else if( d.ivec[0].str == "=" )
	    {
	      assert( d.ivec.size() == 3 );
	      // TODO we do not check validity of right value
	      // usually right value should be a variable

	      // get type name of right value
	      string typeName = getTypeName( d.ivec[1] );
	      // TODO see varGen
	      // name of que should be formalized
	      string queName = typeName + (string)"Que";
	      out << queName << ".push( make_pair ( &";
	      dfsGenCCode( d.ivec[1], out, lev + 1 );
	      out << " , ";
	      dfsGenCCode( d.ivec[2], out, lev + 1 );
	      out << " ) );\n";
	    }
	  else if( d.ivec[0].str == "assign" )
	    {
	      // assign expression
	      // ( assign to from )

	      dfsGenCCode( d.ivec[1], out, lev + 1 );
	      out << " = ";
	      dfsGenCCode( d.ivec[2], out, lev + 1 );
	      out << ";\n";
	    }
	  // bit/alu operation 
	  // ( op a b )
	  // ( ( a ) op ( b ) )
	  else if( d.ivec[0].str == "&" ||
		   d.ivec[0].str == "|" ||
		   d.ivec[0].str == "<<" ||
		   d.ivec[0].str == ">>" ||
		   d.ivec[0].str == "-" ||
		   d.ivec[0].str == "+" )
	    {
	      // TODO 
	      // we do not check validity of data type
	      assert( d.ivec.size() == 3 );
	      out << " ( ";
	      out << " ( ";
	      dfsGenCCode( d.ivec[1], out, lev + 1 );
	      out << " ) ";
	      out << " & ";
	      out << " ( ";
	      dfsGenCCode( d.ivec[2], out, lev + 1 );
	      out << " ) ";
	      out << " ) ";
	    }
	  // index operation
	  // ( [] a b )
	  // a[b]
	  // only one dimention allowed
	  else if( d.ivec[0].str == "[]" )
	    {
	      assert( d.ivec.size() == 3 );
	      // TODO no validity check at present
	      dfsGenCCode( d.ivec[1], out, lev + 1);
	      out << " [ ";
	      dfsGenCCode( d.ivec[2], out, lev + 1);
	      out << " ] ";
	    }
	  else if( d.ivec[0].str == "call" )
	    {
	      // function call
	      //( call funcName param.. )
	      assert( d.ivec.size() > 1 );
	      string funcName = d.ivec[1].str;
	      out << funcName << "( ";
	      for( int i = 2; i < d.ivec.size(); ++i )
		{
		  if( i > 2 )
		    out << ", ";
		  out << d.ivec[i].str;
		}
	      out << ");\n";
	    }
	  else if( d.ivec[0].str == "clock" )
	    {
	      assert( d.ivec.size() == 2 &&
		      d.ivec[1].is_str1() );
	      int num = str2int( d.ivec[1].str );
	      string clockName = (string)"clock" +
		int2str(timCnt.size());
	      timCnt.push_back( make_pair( clockName
					   , num ) );
	      out << " if( --" << clockName << " > 0 ){\n ";
	      out << " __ok" << lev <<  " = false;\n";
	      out  << " doOk = false; \n";
	      out << "break;}\n";
	    }
	  else if( d.ivec[0].str == "not" )
	    {
	      assert( d.ivec.size() == 2 );
	      out << " ! ( " ;
	      dfsGenCCode( d.ivec[1], out, lev + 1 );
	      out << " ) ";
	    }
	}
    }
}

void stageGen(Ir &ir, ofstream &outh, ofstream &outc)
{
  outh << "#ifndef STATE_H\n";
  outh << "#define STATE_H\n";
  outh << "#include \"type.h\"\n";
  // out << "class " << " {\n";
  // // TODO not only int
  // out << "public:\n" << "int state;\n";
  // out << "int pc;\n";
  // // TODO a more unique name
  // out << "}";
  
  // int num = ir.get_num_stage();
  // for( int i = 0; i < num ; ++i )
  //   {
  //     string name = ir.get_stage_name(i);
  //     if( i > 0 )
  // 	out << ", ";
  //     out << name;
  //   }
  // out << ";\n";
  int num = ir.get_num_stage();
  outh << " enum stage{ " ;
  outc << "#include \"stage.h\"\n";
  outc << "enum stage _stages[" << num << "] = {";
  for( int i = 0; i < num ; ++i )
    {
      string name = ir.get_stage_name(i);
      stageMap[ name ] = i;
      if( i > 0 )
  	{
	  outh << ", ";
	  outc << ", ";
	}
      outh << name;
      outc << name;
    }
  outh << " };\n";
  outc << "};\n";
  outh << "#endif";
}

void typeDefGen( ofstream & out )
{
  out << "#ifndef TYPE_H\n";
  out << "#define TYPE_H\n";
  for( auto i : typeSet )
    {
      // TODO use gmp here
      out << "typedef long long " << i << ";\n";
    }
  out << "#endif\n";
}

string getTypeName( do_content & d )
{
  if( d.is_vector() )
    {
      if( d.ivec[0].is_vector() )
	return getTypeName( d.ivec[0] );
      if( d.ivec[0].str == "[]" )
	return getTypeName( d.ivec[1] );
      assert(0);
    }
  // is str
  cout << d.str << endl;
  assert( varTypeMap.find( d.str ) != varTypeMap.end() );
  return varTypeMap[ d.str ];
}

