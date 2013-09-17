#include "stages.h"
void Stage::read(ifstream &fin)
{
  fin>>name;
}
void Stage::output(ofstream &fout)
{
  fout<<name<<endl;
}

