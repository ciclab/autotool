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
void Instruction::set_type(string t)
{
  type=t;
}
void Instruction::set_varname( vector<string> &vn)
{
  var_name = vn;
}
void Instruction::set_varlen( vector<int> &vl)
{
  var_len = vl;
}
void Instruction::set_reloc_info(vector<int> & ri)
{
  reloc_info=ri;
}
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
void Instruction::get_reloc_info(vector<int> &ri)
{
  ri=reloc_info;
}
void Instruction::get_off(vector<ppi> &roff)
{
  roff=off;
}
void Instruction::set_arglist(vector<pair<string,string>  > &al)
{
  arglist=al;
}
string Instruction::get_name()
{
  return name;
}
void Instruction::output_arglist(ofstream &fout)
{
  fout<<arglist.size()<<endl;
  FR(i,arglist)
    fout << i.first << ' ' << i.second <<endl;
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
void Instruction::read_varname(ifstream &fin)
{
  int num;
  fin >> num;
  for( int i = 0; i < num; ++i )
    {
      string name;
      fin >> name;
      var_name.push_back( name );
    }
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
string Instruction::get_type()
{
  return type;
}
void Instruction::get_arglist(vector<pair<string,string> > &r)
{
  r=arglist;
}
void Instruction::read(ifstream &fin)
{
  fin>>name;
  fin>>type;
#if INSTR_COUT==1
  cout<<name<<endl;
#endif
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
  read_reloc_info(fin);
  read_varname(fin);
  read_varlen(fin);
  read_do_list(fin);
}
void Instruction::read_varlen(ifstream &fin)
{
  int num;
  fin >> num;
  for( int i = 0 ; i < num; ++i )
    {
      int v;
      fin >> v;
      var_len.push_back(v);
    }
}
void Instruction::output_varlen(ofstream &fout)
{
  fout << var_len.size() << endl;
  for( auto i : var_len )
    fout << i << ' ';
  fout << endl;
}
void Instruction::output(ofstream &fout)
{
  fout<<name<<endl;
  fout<<type<<endl;
  fout<<"\""<<code<<"\""<<endl;
  fout<<"\""<<binary<<"\""<<endl;
  fout<<off.size()<<endl;
  FR(i,off)
    fout<<i.first<<' '<<i.second<<' ';
  // for(int i=0;i<off.size();++i)
  //   fout<<off[i].first<<' '<<off[i].second<<' ';
  fout<<endl;
  fout<<enum_var.size()<<endl;
  FR(i,enum_var)
    fout << '"' << i << '"' << ' ';
  // for(int i=0;i<enum_var.size();++i)
  //   fout<<'"'<<enum_var[i]<<'"'<<' ';
  fout<<endl;
  output_arglist(fout);
  //fout<<"!!do_beg"<<endl;
  output_do(fout);
  //fout<<"!!do_end"<<endl;
  output_reloc_info(fout);
  
  output_varname(fout);
  
  output_varlen(fout);

  output_do_list(fout);
}
void Instruction::output_varname(ofstream &fout)
{
  fout << var_name.size() << endl;;
  for( auto i : var_name )
    fout << i << ' ';
  fout << endl;
}
void Instruction::set_do_list( vector<int> &dl)
{
  do_list = dl;
}
void Instruction::get_do_list( vector<int> &dl)
{
  dl = do_list;
}
void Instruction::read_reloc_info(ifstream &fin)
{
  int num;
  fin>>num;
  reloc_info.resize(num);
  for(int i=0;i<num;++i)
    fin>>reloc_info[i];
}
void Instruction::output_reloc_info(ofstream &fout)
{
  fout<<reloc_info.size()<<endl;
  FR(i,reloc_info)
    fout << i << ' ';
  fout<<endl;
}
void Instruction::output_do_list( ofstream &fout)
{
  fout << do_list.size() << endl;
  for( auto i : do_list )
    fout << i << ' ';
  fout << endl;
}
void Instruction::read_do_list( ifstream &fin )
{
  int num;
  fin >> num;
  for( int i = 0; i < num; ++i )
    {
      int do_seq;
      fin >> do_seq;
      do_list.push_back( do_seq );
    }
}
void Instruction::get_var_name(vector<string> &vn)
{
  vn = var_name;
}
void Instruction::get_var_len(vector<int> &vl)
{
  vl = var_len;
}

void Instruction::GetDoContent(do_content& doContent)
{
	doContent = doo;
}
