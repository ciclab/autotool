#include <iostream>
#include <fstream>
#include "wire.h"
#include "instruction.h"
#include <vector>
#include <typeinfo>
#include "../do_content.h"
#include "type.h"
#include "stages.h"
#include "enum.h"
#include "memory.h"
#include "register.h"
using namespace std;
class Ir
{
private:
  vector<Wire> wire;
  vector<Type> type;
  vector<Stage> stage;
  vector<Instruction> instruction_set;
  vector<Enum> enumm;
  vector<Memory> memory;
  vector<Register> registers;
public:
  void add_stage(Stage s);
  void read_stage(ifstream &fin);
  void output_stage(ofstream &fout);
  void add_type(Type t);
  void add_wire(Wire w);
  void output_wire(ofstream &fout);
  void read_wire(ifstream &fin);
  void add_instruction(string &c,string &b,do_content &d,vector<pp> &off,vector<string> &enum_var,vector<pair<string,string>  > &al);
  void output_instruction_set(ofstream &fout);
  void output_type(ofstream &fout);
  void read_type(ifstream &fin);
  void add_enum(string name);
  void add_enum_entry(string name,string code);
  void read_enum(ifstream & fin);
  void output_enum(ofstream & fout);
  void add_memory(Memory m);
  void output_memory(ofstream &);
  void read_memory(ifstream &);
  void add_register(Register r);
  void read_register(ifstream &);
  void output_register(ofstream &);
};

void Ir::read_register(ifstream & fin)
{
  int num;
  fin>>num;
  registers.resize(num);
  for(int i=0;i<num;++i)
    registers[i].read(fin);
}
void Ir::output_register(ofstream & fout)
{
  fout<<"register"<<endl;
  fout<<registers.size()<<endl;
  for(int i=0;i<registers.size();++i)
    registers[i].output(fout);
  fout<<endl;
}
void Ir::add_register(Register r)
{
  registers.push_back(r);
}
void Ir::read_memory(ifstream &fin)
{
  int num;
  fin>>num;
  memory.resize(num);
  for(int i=0;i<num;++i)
    memory[i].read(fin);
}
void Ir::output_memory(ofstream &fout)
{
  fout<<"memory"<<endl;
  fout<<memory.size()<<endl;
  for(int i=0;i<memory.size();++i)
    memory[i].output(fout);
  fout<<endl;
}
void Ir::add_memory(Memory m)
{
  memory.push_back(m);
}
void Ir::add_type(Type t)
{
  type.push_back(t);
}
void Ir::output_instruction_set(ofstream &fout)
{
  fout<<"instr"<<endl;
  fout<<instruction_set.size()<<endl;
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
  fout<<endl;
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
  fout<<"wire"<<endl;
  fout<<wire.size()<<endl;
  for(int i=0;i<wire.size();++i)
    wire[i].output(fout);
  fout<<endl;
}
void Ir::read_wire(ifstream &fin)
{
  int num;
  fin>>num;
  for(Wire tmp;num--;)
    {
      tmp.read(fin);
      add_wire(tmp);
    }
}
void Ir::output_type(ofstream &fout)
{
  fout<<"type"<<endl;
  fout<<type.size()<<endl;
  for(int i=0;i<type.size();++i)
    type[i].output(fout);
  fout<<endl;
}
void Ir::read_type(ifstream & fin)
{
  int num;
  fin>>num;
  type.resize(num);
  for(int i=0;i<num;++i)
    type[i].read(fin);
}
void Ir::add_stage(Stage s)
{
  stage.push_back(s);
}
void Ir::read_stage(ifstream &fin)
{
  int num;
  fin>>num;
  stage.resize(num);
  for(int i=0;i<num;++i)
    stage[i].read(fin);
}
void Ir::output_stage(ofstream &fout)
{
  fout<<"stage"<<endl;
  fout<<stage.size()<<endl;
  for(int i=0;i<stage.size();++i)
    stage[i].output(fout);
  fout<<endl;
}
void Ir::add_enum(string name)
{
  int t=enumm.size();
  enumm.resize(t+1);
  enumm[t].set_name(name);
}
void Ir::add_enum_entry(string name,string code)
{
  int t=enumm.size();
  enumm[t-1].add(name,code);
}
void Ir::output_enum(ofstream & fout)
{
  fout<<"enum"<<' '<<enumm.size()<<endl;
  for(int i=0;i<enumm.size();++i)
    enumm[i].output(fout);
  fout<<endl;
}
void Ir::read_enum(ifstream & fin)
{
  int num;
  fin>>num;
  enumm.resize(num);
  for(int i=0;i<num;++i)
    enumm[i].read(fin);
}
