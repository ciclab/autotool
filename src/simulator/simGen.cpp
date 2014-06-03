#include <iostream>
#include "ir.h"
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <string>
#include "hash.h"
#include "def.h"
using namespace std;
// record type used, first -> length of type, second -> signed
static unordered_set<string> typeSet;

// generate mem.cpp file 
void memGen(Ir &ir, ofstream &out);

// generate reg.cpp file
void regGen(Ir &ir, ofstream &out);

// generate pipeline data struct
void pipelineGen(Ir &ir, ofstream &out);

// generate class for each instruction
void classGen(Ir &ir, ofstream &out);

// generate C code from do_content 
void dfsGenCCode( do_content & d, ofstream & out );

// generate stage datatype
void stageGen(Ir &ir, ofstream &out);

// // generate functions for enum, called by en;
// void enumFuncGen(Ir &ir, ofstream &out);

string autoType(int width, bool sig);

// generate typedef for each type
void typeDefGen( ofstream &);
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

      ofstream memOut("mem.h");
      memGen(ir, memOut);

      ofstream regOut("reg.h");
      regGen(ir, regOut);
      
      ofstream pipelineOut("pipeline.h");
      pipelineGen(ir, pipelineOut);

      ofstream classOut("class.h");
      classGen(ir, classOut);
      
      ofstream stageOut("stage.h");
      stageGen( ir, stageOut);
      
      // file include typedef
      // used by function autoType()
      // this should be called in the last 
      ofstream typeOut("type.h");
      typeDefGen( typeOut );
    }
  return 0;
}

void memGen(Ir &ir, ofstream & out)
{
  int num = ir.get_num_mem();
  for( int i = 0; i < num; ++i )
    {
      string name = ir.get_mem_name(i);
      int size = ir.get_mem_size(i);
      int width = ir.get_mem_width(i);
      string typeName = autoType(width, 0);
      out << typeName << " " << name << " [ "<< size << " ];" << endl;
    }
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

void regGen(Ir &ir, ofstream &out)
{
  out << "#include \"type.h\"\n";
  int num = ir.get_num_reg();
  for( int i = 0; i < num; ++i )
    {
      string name = ir.get_reg_name(i);
      int size = ir.get_reg_size(i);
      int width = ir.get_reg_width(i);
      string typeName = autoType( width, true);
      out << typeName << ' ' << name << " [ " << size << " ];" << endl;
    }
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
  out << "#include \"simlib.h\"";
  out << "#include <cstdlib>\n#include <cassert>\ntypedef long long ll;\n#include \"stage.h\"\n#define WST(a) ( (a) = (a) )\n\n";
  out << "#include \"reg.h\"\n";
  out << "#include \"pipeline.h\"\n";
  out << "class _class_instr_\
{\
public:\n";
  int stageNum = ir.get_num_stage();
  for( int i = 0; i < stageNum; ++i )
    {
      string stageName = ir.get_stage_name(i);
      out << "int " << stageName << "_active\n;";
    }
  out <<"virtual void init (char *c){};		\
  virtual void Do (){};\
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
	  out << "void Do(){\n" << endl;
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
		  out << " if( " << stageName << "_active" << " ) " << endl;
		  out << "{\n" ;
		  for( int k = 1; k < (int)vec.size(); ++k )
		    {
		      auto t = vec[k];
		      if( t.is_vector() && t.ivec[0].is_str1() &&
			  t.ivec[0].str == "cycle" )
			{
			  // update cycle count 
			}
		      else
			{
			  dfsGenCCode( t, out);
			}
		    }
		  out << "}\n" ;
		}
	    }
	  out << "};\n" << endl;

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

void dfsGenCCode( do_content & d, ofstream & out )
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
	  for( auto i : d.ivec )
	    dfsGenCCode( i, out );
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
	      dfsGenCCode( d.ivec[1], out);
	      out << " ) ";
	      out << " == ";
	      out << " ( ";
	      dfsGenCCode( d.ivec[2], out);
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
	      dfsGenCCode( d.ivec[1], out );
	      out << " ) ";
	      out << " { ";
	      dfsGenCCode( d.ivec[2], out );
	      out << " } ";
	      if( d.ivec.size() > 3 )
		{
		  out << " else \n{ \n";
		  for( int j = 3; j < (int)d.ivec.size(); ++j )
		    {
		      dfsGenCCode( d.ivec[j], out);
		    }
		  out << " }\n";
		}
	    }
	  // assignment expression
	  // ( = to from )
	  // to = from
	  else if( d.ivec[0].str == "=" )
	    {
	      assert( d.ivec.size() == 3 );
	      // TODO we do not check validity of right value
	      // usually right value should be a variable
	      dfsGenCCode( d.ivec[1], out );
	      out << " = ";
	      dfsGenCCode( d.ivec[2], out );
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
	      dfsGenCCode( d.ivec[1], out );
	      out << " ) ";
	      out << " & ";
	      out << " ( ";
	      dfsGenCCode( d.ivec[2], out );
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
	      dfsGenCCode( d.ivec[1], out);
	      out << " [ ";
	      dfsGenCCode( d.ivec[2], out);
	      out << " ] ";
	    }
	}
    }
}

void stageGen(Ir &ir, ofstream &out)
{
  out << "#include \"type.h\"\n";
  out << "class " << " {\n";
  // TODO not only int
  out << "public:\n" << "int state;\n";
  out << "int pc;\n";
  // TODO a more unique name
  out << "}";
  
  int num = ir.get_num_stage();
  for( int i = 0; i < num ; ++i )
    {
      string name = ir.get_stage_name(i);
      if( i > 0 )
	out << ", ";
      out << name;
    }
  out << ";\n";
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
