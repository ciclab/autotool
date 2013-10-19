#include <cassert>
#include "wire.h"
string Wire::get_name()
{
  return name;
}
int Wire::get_width()
{
  return width;
}
Wire::Wire(string &n,int w)
{
  assert(n.length()>0 && w>0 && w<=128);
  name=n,width=w;
}
void Wire::read(ifstream &fin)
{
  fin>>name>>width;
}
void Wire::output(ofstream &fout)
{
  fout<<name<<' '<<width<<endl;
}
