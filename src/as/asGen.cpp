#include "hash.h"
#include "ir.h"
#include "def.h"
#include <iostream>
#include <fstream>
#include <vector>
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
  ofstream lout,yout;
  lout.open(argv[2],ofstream::out);
  yout.open(argv[3],ofstream::out);
  //lex file head
  lout<<"%{\n";
  lout<<"#include \""<<argv[2]<<".tab.h\""<<endl;
  lout<<"%}\n";
  lout<<"BLANK [ \\t]+\n";
  lout<<"%%\n";
  //yacc file head
  yout<<"%{\n";
  yout<<"%}\n";
  yout<<"%%\n";

  //lex rule name should be unique
  hash_control hc;
  char * cnt(NULL);
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
      yout<<enu.enum_name()<<": ";
      FOR(j,0,enum_ent_size)
	{
	  if(j)
	    yout<<"|"<<endl;
	  string ent_name=enu.ent_name(j);
	  char *en=(char*)hc.find(ent_name);
	  if(en==NULL)
	    {
	      en=++cnt;
	      hc.insert(ent_name,cnt);
	      lout<<"\""<<enu.ent_code(j)<<"\""<<" return TOK_"<<(ll)en<<";"<<endl;
	    }
	  yout<<"TOK_"<<(ll)en<<" {return (char*)"<<int2string(width,j)<<";}";
	}
      yout<<";"<<endl;
    }
  //fout<<"\\n return 0;\n";

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
	  vector<ppi> off;
	  ir.get_instr_off(i,off);
	  string code=ir.get_instr_code(i);
	  string binary=ir.get_instr_binary(i);
	  int off_in_code=0,offi=0;
	  sort(off.begin(),off.end());
	  //fout<<off.size()<<' '<<n<<endl;
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
			  tmp=++cnt;
			  hc.insert(token,tmp);
			  lout<<"\""<<token<<"\""<<" return TOK_"<<(ll)tmp<<";"<<endl;
			}
		      yout<<"TOK_"<<(ll)tmp<<" ";
		    }
		  else yout<<'{'<<token<<'}';
		  break;
		}
	    }
	  yout<<"{return (char*)\""<<binary<<"\";}"<<endl;
	  yout<<endl;
	}
    }
  return 0;
}
