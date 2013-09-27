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
  lout<<"{BLANK} {}\n";
  //yacc file head
  yout<<"%{\n";
  yout<<"%}\n";

  //lex rule name should be unique
  hash_control hc;
  // hash_control hc_len;
  char * cnt(NULL);

  //output token info TODO: info about token can be colectd from ir, instead of traversing all possible places
  yout<<"%token\n";
  //token generated from enum
  int enum_size=ir.get_num_enum();
  FOR(i,0,enum_size)
    {
      Enum enu;
      ir.get_enum(i,enu);
      int enum_ent_size=enu.size();
      FOR(j,0,enum_ent_size)
	{
	  string ent_code=enu.ent_code(j);
	  if(hc.find(ent_code)==NULL)
	    {
	      ++cnt;
	      hc.insert(ent_code,cnt);
	      yout<<"TOK_"<<(ll)cnt<<endl;
	    }
	}
    }
  //output token from instruction
  FOR(i,0,instr_size)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
	  vector<ppi> off;
	  ir.get_instr_off(i,off);
	  string code=ir.get_instr_code(i);
	  int off_in_code=0,offi=0;
	  sort(off.begin(),off.end());
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
			  yout<<"TOK_"<<(ll)cnt<<endl;
			}
		    }
		  else
		    {
		    }
		  break;
		}
	    }
	}
    }

  yout<<"%%\n";

  //output rules for enum
  FOR(i,0,enum_size)
    {
      Enum enu;
      ir.get_enum(i,enu);
      int enum_ent_size=enu.size();
      int width=0;
      for(;(1<<width)<enum_ent_size;++width)
	;
      string enum_name=enu.enum_name();
      yout<<enum_name<<": ";
      // hc_len.insert(enum_name,(void*)width);
      FOR(j,0,enum_ent_size)
	{
	  if(j)
	    yout<<"|"<<endl;
	  string ent_code=enu.ent_code(j);
	  char *en=(char*)hc.find(ent_code);
	  assert(en!=NULL);
	  lout<<"\""<<ent_code<<"\""<<" return TOK_"<<(ll)en<<";"<<endl;
	  yout<<"TOK_"<<(ll)en<<" {return (char*)"<<int2string(width,j)<<";}";
	}
      yout<<";"<<endl;
    }

  
  //output rules for type



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
			  tmp=++cnt;
			  hc.insert(token,tmp);
			  lout<<"\""<<token<<"\""<<" return TOK_"<<(ll)tmp<<";"<<endl;
			}
		      yout<<"TOK_"<<(ll)tmp<<" ";
		    }
		  else
		    {
		      yout<<'{'<<token<<'}';
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
  return 0;
}
