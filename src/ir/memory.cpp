#include "memory.h"
void Memory::read(ifstream &fin)
{
  fin>>name>>size>>type>>idx;
}

void Memory::output(ofstream &fout)
{
  fout<<name<<' '<<size<<' '<<type<<' '<<idx<<endl;
}
