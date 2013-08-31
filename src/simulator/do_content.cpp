#include "do_content.h"
void do_content::output(fstream &fout)
{
  for(int i=0;i<ivec.size();++i){
    if(ivec[i].type==do_type_is_vector){
      if(i)
	{
	  fout<<endl;
	  // for(int j=0;j<lev;++j)
	  //   cout<<"  ";
	}
      fout<<'(';
      ivec[i].output(fout);
      fout<<')';
    }
    else
      {
	if(i && ivec[i-1].type==do_type_is_vector)
	  {
	    fout<<endl;
	    // for(int j=0;j<lev;++j)
	    //   cout<<"  ";
	  }
	if(ivec[i].type==do_type_is_string1)
	  fout<<ivec[i].str<<' ';
	else fout<<'\''<<ivec[i].str<<'\''<<' ';
      }
  }
}
