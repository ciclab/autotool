#include "hash.h"
#include "ir.h"
#include "def.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
static string int2string(int w,int v)
{
  string r;
  r.resize(w);
  FOR(i,0,w)
    {
      r[i]=(v&1)?'1':'0';
      v>>=1;
    }
  return r;
}
int main(int argc,char *argv[])
{
  assert(argc==4);
  ifstream fin;
  fin.open(argv[1],ofstream::in);
  Ir ir;
  ir.read_all(fin);
  
  int instr_size=ir.get_instr_size();
  string top_rule_name=ir.get_top_rule_name();
  ofstream lout,yout,tokout;
  string l_file_name=argv[2];
  string y_file_name=argv[3];
  lout.open(l_file_name.c_str(),ofstream::out);
  yout.open(y_file_name.c_str(),ofstream::out);
  string token_file_name=y_file_name;
  token_file_name+=".tok";
  tokout.open(token_file_name.c_str(),ofstream::out);
  //lex file head
  lout<<"%{\n";
  lout<<"#include \""<<argv[2]<<".tab.h\""<<endl;
  lout<<"#include \"strstack.h\"\n";
  lout<<"extern struct strstack strsta;\n";
  lout<<"%}\n";
  lout<<"BLANK [ \\t]+\n";
  lout<<"%%\n";
  lout<<"{BLANK} {}\n";
  //yacc file head
  tokout<<"%{\n";
  tokout<<"%}\n";
  
  tokout<<"%union{\n";
  tokout<<"int integer\n";
  tokout<<"char ch;\n";
  tokout<<"char * chp\n";
  tokout<<"}\n";

  //lex rule name should be unique
  hash_control hc;
  // hash_control hc_len;
  char * cnt(NULL);

  tokout<<"%token TOK_INT"<<endl;

  yout<<"%%\n";

  //output rules for enum
  int enum_size=ir.get_num_enum();
  FOR(i,0,enum_size)
    {
      Enum enu;
      ir.get_enum(i,enu);
      int enum_ent_size=enu.size();
      int width=0;
      for(;(1<<width)<enum_ent_size;++width)
	;
      string enum_name=enu.enum_name();
      tokout<<"%type <chp>"<<enum_name<<endl;
      yout<<enum_name<<": ";
      // hc_len.insert(enum_name,(void*)width);
      FOR(j,0,enum_ent_size)
	{
	  if(j)
	    yout<<"|"<<endl;
	  string ent_code=enu.ent_code(j);
	  char *en=(char*)hc.find(ent_code);
	  if(en==NULL)
	    {
	      //token generated from enum
	      en=++cnt;
	      hc.insert(ent_code,en);
	      tokout<<"%token TOK_"<<(ll)en<<endl;
	      lout<<"\""<<ent_code<<"\""<<" return TOK_"<<(ll)en<<";"<<endl;
	    }
	  yout<<"TOK_"<<(ll)en<<" {return (char*)\""<<int2string(width,j)<<"\";}";
	}
      yout<<";"<<endl;
    }
  
  tokout<<"%start "<<top_rule_name<<endl;
  yout<<top_rule_name<<": "<<endl;
  for(int i=0,j=0;i<instr_size;++i)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
	  if(j)
	    yout<<"|"<<endl;
	  yout<<n<<"{return $1;}"<<endl;
	  ++j;
	}
    }
	
  //output rules for instructions
  FOR(i,0,instr_size)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
#if ASGEN_COUT==1
	  FR(j,off)
	    cout<<j->first<<' '<<j->second<<endl;
	  cout<<endl<<endl;
#endif
	  tokout<<"%type<chp> "<<n<<endl;
	  vector<ppi> off;
	  ir.get_instr_off(i,off);
	  string code=ir.get_instr_code(i);
	  string binary=ir.get_instr_binary(i);
	  int off_in_code=0,offi=0;
	  sort(off.begin(),off.end());
	  yout<<n<<": ";
	  for(typeof(code.begin()) j=code.begin();j!=code.end();)
	    {
	      switch(*j)
		{
		case ' ':
		  for(;j!=code.end() && *j==' ';++j,++off_in_code)
		    ;
		  //fout<<"BLANK";
		  break;
		case c_sep:
		  ++j,++off_in_code;
		default:
		  string token;
		  for(;offi<(int)off.size() && off[offi].first<off_in_code;++offi)
		    ;
		  bool is_string=true;
		  if(offi<(int)off.size() && off[offi].first==off_in_code)
		    {
		      //may be a type or enum;
		      is_string=false;
		    }
		  if(!is_string)
		    {
		      assert(*j==c_type_beg || *j==c_enum_beg);
		      ++off_in_code;
		      ++j;
		    }
		  for(;j!=code.end() && *j!=' ' && *j!='\1';++j,++off_in_code)
		    token+=*j;
		  if(is_string)
		    {
		      char *tmp=(char*)hc.find(token);
		      if(tmp==NULL)
			{
			  //output token from instruction
			  tmp=++cnt;
			  hc.insert(token,tmp);
			  tokout<<"%token TOK_"<<(ll)tmp<<endl;
			  lout<<"\""<<token<<"\""<<" return TOK_"<<(ll)tmp<<";"<<endl;
			}
		      yout<<"TOK_"<<(ll)tmp<<" ";
		    }
		  else
		    {
		      yout<<token<<' ';
		    }
		  break;
		}
	    }
	  yout<<endl<<"{static char tmp[]=\""<<binary<<"\";"<<endl;
	  FR(i,off)
	    {
	      yout<<"for(int i=0"<<";$"<<(1+i-off.begin())<<"[i];"<<"++i)"<<endl;
	      yout<<"tmp[i+"<<i->second<<"]=$"<<(1+i-off.begin())<<"[i];"<<endl;
	    }
	  yout<<"return tmp;";
	  yout<<"}"<<endl;
	}
    }
  
  //output rules for type

  int type_size=(int)ir.type_size();
  FOR(i,0,type_size)
    {
      Type ty=ir.get_type(i);
      string name=ty.get_name();
      tokout<<"%type<chp> "<<name<<endl;
      yout<<name<<": ";
      int len=ty.get_len();
      yout<<"TOK_INT" ;
      yout<<"{\n";
      yout<<"static char tmp["<<len<<"];"<<endl;
      yout<<"i2s(tmp,$1,"<<len<<");"<<endl;
      yout<<"return tmp;}"<<endl;
      yout<<"|"<<" TOK_LABEL{"<<endl;
      yout<<"for(int i=0;i<"<<len<<";++i)"<<endl;
      yout<<"tmp[i]='L';"<<endl;
      yout<<"return tmp;}"<<endl;
      
    }

  lout<<"[_a-zA-Z][_a-zA-Z0-9]*	{\n\
        dummy_lval.chp=newstr1(&strsta,yytext);/*TODO*/return TOK_LABEL;}"<<endl;
  lout<<"[0-9]+	{dummy_lval.integer=atoi(dummy_text);return TOK_INT;}"<<endl;

  lout<<"[\"0\"|\"1\"] dummy_lval=(*dummytext)=='1'?1:0;return C01\n";


  lout<<"%%\n\
int yywrap()\n\
{\n\
        return 1;\n\
}\n";
  yout.close();
  tokout.close();
  string cmd="cat "+token_file_name+" "+y_file_name+" > "+"_"+y_file_name;
  system(cmd.c_str());
  return 0;
}
