#include "enum.h"
#include "def.h"
int Enum::ent_value(int i)
{
  return value_list[i];
}
string Enum::ent_name(int i)
{
  return list[i].first;
}
string Enum::ent_code(int i)
{
  return list[i].second;
}
string Enum::enum_name()
{
  return name;
}
int Enum::width()
{
  int m=0;
  for( auto i : value_list )
    if( m < i )
      m = i;
  int w=0;
  for(int i=1;i<=m;i<<=1,++w)
    ;
  return w;
}
int Enum::size()
{
  return list.size();
}
void Enum::add(string name,string code,int value)
{
  list.push_back(make_pair(name,code));
  value_list.push_back(value);
}
void Enum::output(ofstream & fout)
{
  fout<<name<<' '<<list.size()<<endl;
  for( auto i : list )
    fout << i.first << ' ' << i.second << ' ';
  fout<<endl;
  for( auto i : value_list )
    fout << i << ' ';
  // for(int i=0;i<list.size();++i)
  //   fout<<list[i].first<<' '<<list[i].second<<' ';
  fout<<endl;
}
void Enum::read(ifstream & fin)
{
  int num;
  fin>>name>>num;
  int i=num;
  for(string t1,t2;i--;)
    {
      fin>>t1>>t2;
      list.push_back(make_pair(t1,t2));
    }
  value_list.resize(num);
  for(i=0;i<num;++i)
    fin>>value_list[i];
}
void Enum::set_name(string n)
{
  name=n;
}
