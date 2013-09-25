#include "instruction.h"
#include "def.h"
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
  if(!doo.is_empty())
    doo.output(fout);
  else doo.output_empty(fout);
}
void Instruction::set_name(const string &n)
{
  name=n;
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
  FR(i,arglist)
    fout<<i->first<<' '<<i->second<<endl;
  // for(int i=0;i<arglist.size();++i)
  //   fout<<arglist[i].first<<' '<<arglist[i].second<<endl;
}
void Instruction::read_arglist(ifstream &fin)
{
  int num;
  fin>>num;
  arglist.resize(num);
  for(int i=0;i<num;++i)
    fin>>arglist[i].first>>arglist[i].second;
}
string read_quoted_str(ifstream &fin)
{
  string r;
  int c;
  for(;;)
    {
      c=fin.get();
      if(c==EOF)
	assert(0);
      if(c=='"')
	break;
    }
  for(;;)
    {
      c=fin.get();
      if(c=='"')
	break;
      if(c==EOF)
	assert(0);
      r+=c;
    }
  return r;
}
void Instruction::read(ifstream &fin)
{
  fin>>name;
  cout<<name<<endl;
  code=read_quoted_str(fin);
  binary=read_quoted_str(fin);
  int c;
  fin>>c;
  off.resize(c);
  for(int i=0;i<c;++i)
    fin>>off[i].first>>off[i].second;
  fin>>c;
  enum_var.resize(c);
  for(int i=0;i<c;++i)
    enum_var[i]=read_quoted_str(fin);
  read_arglist(fin);
  read_do(fin);
}
void Instruction::output(ofstream &fout)
{
  fout<<name<<endl;
  fout<<"\""<<code<<"\""<<endl;
  fout<<"\""<<binary<<"\""<<endl;
  fout<<off.size()<<endl;
  FR(i,off)
    fout<<i->first<<' '<<i->second<<' ';
  // for(int i=0;i<off.size();++i)
  //   fout<<off[i].first<<' '<<off[i].second<<' ';
  fout<<endl;
  fout<<enum_var.size()<<endl;
  FR(i,enum_var)
    fout<<'"'<<*i<<'"'<<' ';
  // for(int i=0;i<enum_var.size();++i)
  //   fout<<'"'<<enum_var[i]<<'"'<<' ';
  fout<<endl;
  output_arglist(fout);
  //fout<<"!!do_beg"<<endl;
  output_do(fout);
  //fout<<"!!do_end"<<endl;
}
