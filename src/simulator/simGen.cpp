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

// // generate functions for enum, called by classGen;
// void enumFuncGen(Ir &ir, ofstream &out);

string autoType(int width, bool sig);


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

      ofstream memOut("mem");
      memGen(ir, memOut);

      ofstream regOut("reg");
      regGen(ir, regOut);
      
      ofstream pipelineOut("pipeline");
      pipelineGen(ir, pipelineOut);

      ofstream classOut("class");
      classGen(ir, classOut);
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
  int num = ir.get_num_pipeline();
  out << " struct pl \n{";
  for( int i = 0; i < num; ++i )
    {
      string name = ir.get_pipeline_name(i);
      int width = ir.get_pipeline_width(i);
      string typeName = autoType( width, true);
      out << typeName << ' ' << name << ';' << endl; 
    }
  out << "};" << endl;
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
  // output class for each instruction
  for( int i = 0 ; i < instrSize; ++i )
    {
      if( !used[i] )
	continue;
      string ruleName = ir.get_instr_name(i);
      string ruleType = ir.get_instr_type(i);
      if( ruleType == "e_notpack" )
	{
	  out << "class class_" << ruleName << "{\n ";
	  vector<string> varName;
	  ir.get_instr_var_name( i, varName);
	  // for every class define its own variable
	  for( auto i : 
	  out << "init( char *c)\n{\n";
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
	  out << " assert( tmp != NULL );\n " << endl;
	  out << " assert( c != NULL );\n" << endl;

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
	  for( int j = 0; j < varOff.size(); ++j )
	    {
	      out << "set_val( " << varName[j] << ", tmp + " << varOff[j].second << ", " << varLen[j] << ");\n";
	    }
	  out << "};\n};\n";
	}
      // here we don't check for binary invalidity
      // see asGen.cpp/checkBianry(5) for detail
      
    }
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
