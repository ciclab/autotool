#include "pipeline.h"
void Pipeline::read(ifstream &fin)
{
  fin>>name>>width;
}
void Pipeline::output(ofstream &fout)
{
  fout<<name<<' '<<width<<endl;
}
int Pipeline::get_width()
{
  return width;
}
string Pipeline::get_name()
{
  return name;
}
