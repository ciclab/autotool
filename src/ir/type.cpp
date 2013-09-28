#include "type.h"
#include <fstream>
using namespace std;
string Type::get_name()
{
  return name;
}
int Type::get_len()
{
  return len;
}
Type::Type(string n,int l,string t)
{
  name=n,len=l,type=t;
}
void Type::output(ofstream &fout)
{
  fout<<name<<' '<<len<<' '<<type<<endl;
}
void Type::read(ifstream &fin)
{
  fin>>name>>len>>type;
}
