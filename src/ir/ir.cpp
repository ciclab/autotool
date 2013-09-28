#include "ir.h"
#include <iostream>
#include "def.h"
using namespace std;
Type Ir::get_type(int i)
{
  return type[i];
}
int Ir::type_size()
{
  return type.size();
}
void Ir::get_enum(int i,Enum &e)
{
  e=enumm[i];
}
int Ir::get_num_enum()
{
  return enumm.size();
}
void Ir::get_instr_off(int i,vector<ppi> &roff)
{
  instruction_set[i].get_off(roff);
}
string Ir::get_instr_binary(int i)
{
  return instruction_set[i].get_binary();
}
string Ir::get_instr_code(int i)
{
  return instruction_set[i].get_code();
}
string Ir::get_instr_name(int i)
{
  return instruction_set[i].get_name();
}
int Ir::get_instr_size()
{
  return instruction_set.size();
}
string Ir::get_top_rule_name()
{
  return top_rule_name;
}
void Ir::read_all(ifstream &fin)
{
  fin>>top_rule_name;
  read_wire(fin);
  read_type(fin);
  read_stage(fin);
  read_enum(fin);
  read_memory(fin);
  read_register(fin);
  read_pipeline(fin);
  read_instr(fin);
}
void Ir::add_top_name(string n)
{
  top_rule_name=n;
}
void Ir::output_all(ofstream &fout)
{
  fout<<top_rule_name<<endl;
  output_wire(fout);
  output_type(fout);
  output_stage(fout);
  output_enum(fout);
  output_memory(fout);
  output_register(fout);
  output_pipeline(fout);
  output_instruction_set(fout);
}
void Ir::read_pipeline(ifstream &fin)
{
  int num;
  fin>>num;
  pipeline.resize(num);
  for(int i=0;i<num;++i)
    pipeline[i].read(fin);
}
void Ir::output_pipeline(ofstream &fout)
{
  //fout<<"pipeline"<<endl;
  fout<<pipeline.size()<<endl;
  FR(i,pipeline)
    i->output(fout);
  // for(size_t i=0;i<pipeline.size();++i)
  //   pipeline[i].output(fout);
}
void Ir::add_pipeline(Pipeline p)
{
  pipeline.push_back(p);
}
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
  //fout<<"register"<<endl;
  fout<<registers.size()<<endl;
  FR(i,registers)
    i->output(fout);
  // for(int i=0;i<registers.size();++i)
  //   registers[i].output(fout);
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
  //fout<<"memory"<<endl;
  fout<<memory.size()<<endl;
  FR(i,memory)
    i->output(fout);
  // for(int i=0;i<memory.size();++i)
  //   memory[i].output(fout);
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
  //fout<<"instr"<<endl;
  fout<<instruction_set.size()<<endl;
  for(vector<Instruction>::iterator ite=instruction_set.begin();
      ite!=instruction_set.end();++ite)
    {
      ite->output(fout);
    }
  fout<<endl;
}
void Ir::read_instr(ifstream &fin)
{
  int num;
  fin>>num;
  instruction_set.resize(num);
  for(int i=0;i<num;++i)
    instruction_set[i].read(fin);
}
void Ir::add_instruction(const string &name,string &c,string &b,do_content &d,vector<pp> &off,vector<string> &enum_var,vector<pair<string,string>  > &al)
{
  int t=instruction_set.size();
  instruction_set.resize(t+1);
  instruction_set[t].set_code(c);
  instruction_set[t].set_binary(b);
  instruction_set[t].set_do(d);
  instruction_set[t].set_off(off);
  instruction_set[t].set_enum_var(enum_var);
  instruction_set[t].set_arglist(al);
  instruction_set[t].set_name(name);
}

void Ir::add_wire(Wire w)
{
  wire.push_back(w);
}
// void Ir::add_wire(string &n,int w)
// {
//   wire.push_back(Wire(n,w));
// }

void Ir::output_wire(ofstream &fout)
{
  //fout<<"wire"<<endl;
  fout<<wire.size()<<endl;
  FR(i,wire)
    i->output(fout);
  // for(int i=0;i<wire.size();++i)
  //   wire[i].output(fout);
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
  //fout<<"type"<<endl;
  fout<<type.size()<<endl;
  FR(i,type)
    i->output(fout);
  // for(int i=0;i<type.size();++i)
  //   type[i].output(fout);
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
  //fout<<"stage"<<endl;
  fout<<stage.size()<<endl;
  FR(i,stage)
    i->output(fout);
  // for(int i=0;i<stage.size();++i)
  //   stage[i].output(fout);
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
  //fout<<"enum"<<endl;
  fout<<enumm.size()<<endl;
  FR(i,enumm)
    i->output(fout);
  // for(int i=0;i<enumm.size();++i)
  //   enumm[i].output(fout);
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
