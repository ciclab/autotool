#include "do_content.h"
#include <cassert>
#include <iostream>
#include "def.h"
using namespace std;
void do_content::output(ofstream &fout)
{
  fout<<type<<endl;
  switch(type)
    {
    case do_type_is_vector:
      fout<<ivec.size()<<endl;
      FR(i,ivec)
	i->output(fout);
      // for(int i=0;i<ivec.size();++i)
      // 	ivec[i].output(fout);
      break;
    case do_type_is_string1:
    case do_type_is_string2:
      fout<<"\""<<str<<"\""<<endl;
      break;
    default:
      assert(0);
    }
}
void do_content::output_empty(ofstream &fout)
{
  fout<<do_type_is_vector<<endl;
  fout<<1<<endl;
  fout<<do_type_is_string1<<endl;
  fout<<"\"do\""<<endl;
}
bool do_content::is_empty()
{
  return ivec.size()==0;
}
void do_content::read(ifstream &fin)
{
  fin>>type;
  switch(type)
    {
    case do_type_is_vector:
      int num;
      fin>>num;
      ivec.resize(num);
      for(int i=0;i<num;++i)
	ivec[i].read(fin);
      break;
    case do_type_is_string1:
    case do_type_is_string2:
      for(int c;;)
	{
	  c=fin.get();
	  if(c==EOF)
	    assert(0);
	  if(c=='"')
	    break;
	}
      for(int c;;)
	{
	  c=fin.get();
	  if(c==EOF || c=='"')
	    break;
	  str+=c;
	}
      break;
    default:
      assert(0);
    }
}
