#include "type.h"
#include <fstream>
using namespace std;
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
