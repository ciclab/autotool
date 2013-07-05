#include <iostream>
#include <string>
#include <cassert>
using namespace std;
class Wire
{
private:
  string name;
  int width;
  string end[2];
public:
  Wire(string &n,int w);
  void input(istream fin);
  void output(ostream fout);
  string get_name();
  int get_width();
};
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
void Wire::input(istream fin)
{
  fin>>name>>width;
}
void Wire::output(ostream fout)
{
  fout<<name<<' '<<width;
}
