#include <iostream>
#include "ir.h"
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <string>
using namespace std;
// record type used, first -> length of type, second -> signed
static unordered_set<string> typeSet;

// generate mem.cpp file 
void memGen(Ir &ir, ofstream &out);

// generate reg.cpp file
void regGen(Ir &ir, ofstream &out);

// generate pipeline data struct
void pipelineGen(Ir &ir, ofstream &out);

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
