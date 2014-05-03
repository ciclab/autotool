#include "register.h"
void Register::read(ifstream & fin)
{
  fin >> name >> size >> width ;
  // for(int i=0;i<N_ELE;++i)
  //   {
  //     fin>>ele[i];
  //     if(ele[i]=="0")
  //     	ele[i]="";
  //     cout << 
  //   }
}
void Register::output(ofstream & fout)
{
  // fout<<size;
  // for(int i=0;i<N_ELE;++i)
  //   if(ele[i].size())
  //     fout<<' '<<ele[i];
  //   else fout<<" 0";
  fout << name << ' ' << size << ' ' << width;
  fout<<endl;
}

string Register::get_name()
{
  return name;
}
int Register::get_size()
{
  return size;
}
int Register::get_width()
{
  return width;
}
