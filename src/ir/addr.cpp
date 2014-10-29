#include "addr.h"
#include "def.h"
void Addr::set_width(int w)
{
  assert(w<=32 && w>0);
  width=w;
}
void Addr::set_pcrel(bool p)
{
  pcrel=p;
}
void Addr::set_right_shift(int r)
{
  assert(r>0 && r<32);
  right_shift=r;
}
void Addr::set(int w,bool p,int r,string n)
{
  set_width(w);
  set_pcrel(p);
  set_right_shift(r);
  set_name(n);
}
int Addr::get_width()
{
  return width;
};
bool Addr::get_pcrel()
{
  return pcrel;
}
int Addr::get_right_shift()
{
  return right_shift;
}
void Addr::read(ifstream & fin)
{
  fin>>name>>width>>pcrel>>right_shift;
}
void Addr::output(ofstream & fout)
{
  fout<<name<<' '<<width<<' '<<pcrel<<' '<<right_shift<<endl;
}
void Addr::set_name(string n)
{
  name=n;
}
string Addr::get_name()
{
  return name;
}
