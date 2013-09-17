#include <iostream>
#include <fstream>
#include "wire.h"
#include "instruction.h"
#include <vector>
#include <typeinfo>
#include "../do_content.h"
#include "type.h"
using namespace std;
class Ir
{
private:
  vector<Wire> wire;
  vector<Type> type;
  vector<Instruction> instruction_set;
public:
  void add_type(Type t);
  void add_wire(Wire w);
  void output_wire(ofstream &fout);
  void add_instruction(string &c,string &b,do_content &d,vector<pp> &off,vector<string> &enum_var,vector<pair<string,string>  > &al);
  void output_instruction_set(ofstream &fout);
};
void Ir::add_type(Type t)
{
  type.push_back(t);
}
void Ir::output_instruction_set(ofstream &fout)
{
  fout<<"("<<endl;
  for(vector<Instruction>::iterator ite=instruction_set.begin();
      ite!=instruction_set.end();++ite)
    {
      fout<<"(\""<<ite->get_code()<<"\""<<endl<<"\""<<ite->get_binary()<<"\""<<endl;
      fout<<ite->get_off_size()<<endl;
      for(int i=0;i<ite->get_off_size();++i)
	fout<<ite->get_off(i).first<<' '<<ite->get_off(i).second<<' ';
      fout<<endl;
      fout<<ite->get_enum_var_size()<<endl;
      for(int i=0;i<ite->get_enum_var_size();++i)
	fout<<ite->get_enum_var(i)<<' ';
      fout<<endl;
      ite->output_arglist(fout);
      // for(int i=0;i<ite->get_do_size();++i)
      // 	fout<<ite->get_do(i)<<' ';
      fout<<"("<<endl;
      ite->output_do(fout);
      fout<<")"<<")"<<endl;
    }
  fout<<")"<<endl;
}

void Ir::add_instruction(string &c,string &b,do_content &d,vector<pp> &off,vector<string> &enum_var,vector<pair<string,string>  > &al)
{
  int t=instruction_set.size();
  instruction_set.resize(t+1);
  instruction_set[t].set_code(c);
  instruction_set[t].set_binary(b);
  instruction_set[t].set_do(d);
  instruction_set[t].set_off(off);
  instruction_set[t].set_enum_var(enum_var);
  instruction_set[t].set_arglist(al);
}

void Ir::add_wire(Wire w)
{
  wire.push_back(w);
}

void Ir::output_wire(ofstream &fout)
{
  fout<<"(wire"<<endl;
  for(int i=0;i<wire.size();++i)
    fout<<"("<<wire[i].get_name()<<' '<<wire[i].get_width()<<")"<<endl;
  fout<<")"<<endl;
}

