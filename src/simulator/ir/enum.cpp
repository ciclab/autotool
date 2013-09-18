#include "enum.h"
void Enum::add(string name,string code)
{
  list.push_back(make_pair(name,code));
}
void Enum::output(ofstream & fout)
{
  fout<<name<<' '<<list.size()<<endl;
  for(int i=0;i<list.size();++i)
    fout<<list[i].first<<' '<<list[i].second<<' ';
  fout<<endl;
}
void Enum::read(ifstream & fin)
{
  int num;
  fin>>name>>num;
  for(string t1,t2;num--;)
    {
      fin>>t1>>t2;
      list.push_back(make_pair(t1,t2));
    }
}
void Enum::set_name(string n)
{
  name=n;
}
