#include "instruction.h"
// class doo
// {
// private:
//   Asem arglist;
//   Asem ent;
// public:
//   void set_arglist(Asem &al);
//   void set_ent(Asem &et);
// };
// void doo::set_arglist(Asem &al)
// {
//   arglist=al;
// }
// void doo::set_ent(Asem &et)
// {
//   ent=et;
// }

void Instruction::output_do(ofstream & fout)
{
  doo.output(fout);
}
void Instruction::read_do(ifstream &fin)
{
  doo.read(fin);
}
void Instruction::set_enum_var(vector<string> &ev)
{
  enum_var=ev;
}
int Instruction::get_enum_var_size()
{
  return enum_var.size();
}
string Instruction::get_enum_var(int id)
{
  return enum_var[id];
}
void Instruction::set_code(string &c)
{
  code=c;
}
void Instruction::set_binary(string &b)
{
  binary=b;
}
void Instruction::set_off(vector<pp> &o)
{
  off=o;
}
void Instruction::set_do(do_content &d)
{
  doo=d;
}
// int Instruction::get_do_size()
// {
//   return doo.size();
// }
// int Instruction::get_do(int id)
// {
//   return doo[id];
// }
string Instruction::get_code()
{
  return code;
}

string Instruction::get_binary()
{
  return binary;
}

int Instruction::get_off_size()
{
  return off.size();
}

pp Instruction::get_off(int id)
{
  assert(id<get_off_size());
  return off[id];
}

void Instruction::set_arglist(vector<pair<string,string>  > &al)
{
  arglist=al;
}

void Instruction::output_arglist(ofstream &fout)
{
  fout<<arglist.size()<<endl;
  for(int i=0;i<arglist.size();++i)
    fout<<arglist[i].first<<' '<<arglist[i].second<<endl;
}
void Instruction::read_arglist(ifstream &fin)
{
  int num;
  fin>>num;
  arglist.resize(num);
  for(int i=0;i<num;++i)
    fin>>arglist[i].first>>arglist[i].second;
}
void Instruction::read(ifstream &fin)
{
}
void Instruction::output(ofstream &fout)
{
  fout<<"\""<<code<<"\""<<endl;
  fout<<"\""<<binary<<"\""<<endl;
  fout<<off.size()<<endl;
  for(int i=0;i<off.size();++i)
    fout<<off[i].first<<' '<<off[i].second<<' ';
  fout<<endl;
  fout<<enum_var.size()<<endl;
  for(int i=0;i<enum_var.size();++i)
    fout<<enum_var[i]<<' ';
  fout<<endl;
  output_arglist(fout);
  output_do(fout);
}
