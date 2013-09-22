#include "pipeline.h"
void Pipeline::read(ifstream &fin)
{
  fin>>name>>width;
}
void Pipeline::output(ofstream &fout)
{
  fout<<name<<' '<<width<<endl;
}
