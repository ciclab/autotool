#include "do_content.h"
void do_content::output(ofstream &fout)
{
  for(int i=0;i<ivec.size();++i){
    if(ivec[i].type==do_type_is_vector)
      {
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
void do_content::read(ifstream &fin)
{
  //get from asem.cpp/Asem::gen(FILE *&input)
  int c1;
  while((c1=fin.get())!=EOF){
    if(c1==')') return;
    int i=ivec.size();
    ivec.resize(i+1);
    //一个vector开始
    if(c1=='('){
      ivec[i].type=do_type_is_vector;
      ivec[i].read(fin);
    }
    //带单引号的string
    else if(c1=='\''){
      ivec[i].type=do_type_is_string2;
      int c2;
      while((c2=fin.get())!=EOF && c2!='\'')
	ivec[i].str+=c2;
    }
    //普通string
    else if(isgraph(c1)){
      ivec[i].type=do_type_is_string1;
      ivec[i].str=c1;
      int c3;
      while((c3=fin.get())!=EOF && 
	    (c3==(int)']' || 
	     isalnum(c3) || 
	     c3=='_' || c3=='[' || c3=='.'
	     /*TODO 这里应该也用isgraph,但是会出现奇怪的效果，暂时列举]*/))
	ivec[i].str+=c3;
      if(c3==')' || c3==EOF)
	return ;
    }
  }
}
