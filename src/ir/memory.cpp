#include "memory.h"
void Memory::read(ifstream &fin)
{
  fin >> name >> size >> width;
}

void Memory::output(ofstream &fout)
{
  fout << name << ' ' << size << ' ' << width <<endl;
}
int Memory::get_size()
{
  return size;
}
int Memory::get_width()
{
  return width;
}
string Memory::get_name()
{
  return name;
}
