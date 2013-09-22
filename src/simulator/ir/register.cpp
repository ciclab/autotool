#include "register.h"
void Register::read(ifstream & fin)
{
  fin>>size;
  for(int i=0;i<N_ELE;++i)
    {
      fin>>ele[i];
      if(ele[i]=="0")
	ele[i]="";
    }
}
void Register::output(ofstream & fout)
{
  fout<<size;
  for(int i=0;i<N_ELE;++i)
    fout<<' '<<ele[i];
  fout<<endl;
}
