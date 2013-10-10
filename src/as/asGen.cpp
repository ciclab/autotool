#include "hash.h"
#include "ir.h"
#include "def.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
static string int2string(int v)
{
  if(v==0)
    return "0";
  string r;
  for(;v;v/=10)
    r=(char)('0'+(v%10))+r;
  return r;
}
static string int2binary(int w,int v)
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
static bool check_is_int(string c)
{
  FR(i,c)
    if(*i<'0' || *i>'9')
      return false;
  return true;
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
  lout<<"#include \"y.h\""<<endl;
  lout<<"#include \"strstack.h\"\n";
  lout<<"extern struct strstack strsta;\n";
  lout<<"#define YY_NO_INPUT\n";
  lout<<"%}\n";
  lout<<"BLANK [ \\t]+\n";
  lout<<"%option nounput\n";//to suppress yyunput defined but not used warning
  lout<<"%%\n";// get rid of ‘input’ defined but not used warning
  lout<<"{BLANK} {return TOK_BLANK;}\n";
  //yacc file head
  tokout<<"%{\n";
  tokout<<"#include \"strstack.h\"\n";
  tokout<<"#include <stdio.h>\n";
  tokout<<"#include <string.h>\n";
  tokout<<"extern char * yyret;"<<endl;
  tokout<<"extern int dummy_lineno;\n";
  tokout<<"extern void dummy_error(const char *s);\n";
  tokout<<"extern struct strstack strsta;\n";
  tokout<<"extern int dummy_lex(void);\n";
  tokout<<"extern void dummy_getExpression(const char * str);\n";
  tokout<<"%}\n";
  tokout<<"%union{\n";
  tokout<<"int integer;\n";
  tokout<<"char ch;\n";
  tokout<<"char * chp;\n";
  tokout<<"}\n";
  tokout<<"%locations;\n";
  //lex rule name should be unique
  hash_control hc;
  // hash_control hc_len;
  char * cnt(NULL);
  tokout<<"%type<integer> rule_int"<<endl;
  tokout<<"%token<integer> TOK_INT"<<endl;
  tokout<<"%token<chp> TOK_LABEL"<<endl;
  tokout<<"%token TOK_BLANK"<<endl;
  yout<<"%%\n";

  //
  vector<pair<ll,ll> > int_list;
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
	      if(check_is_int(ent_code))
		int_list.push_back(make_pair((ll)en,strtoll(ent_code.c_str(),NULL,10)));
	      lout<<"\""<<ent_code<<"\""<<" return TOK_"<<(ll)en<<";"<<endl;
	    }
	  yout<<"TOK_"<<(ll)en<<" {$$=(char*)\""<<int2binary(width,j)<<"\";}";
	}
      yout<<";"<<endl;
    }
  
  tokout<<"%start "<<top_rule_name<<endl;
  tokout<<"%type<chp> "<<top_rule_name<<endl;
  yout<<top_rule_name<<": "<<endl;
  for(int i=0,j=0;i<instr_size;++i)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
	  if(j)
	    yout<<"|"<<endl;
	  yout<<n<<"{yyret=$1;}"<<endl;
	  ++j;
	}
    }
  yout<<";\n";

  //output rules for instructions
  FOR(i,0,instr_size)
    {
      string n=ir.get_instr_name(i);
      vector<int> len;
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
	  int seg(0);
	  // if(n=="tctcore_0")
	  //   {
	  //     FR(i,off)
	  //   	cout<<i->first<<' '<<i->second<<endl;
	  //     FR(j,code)
	  //   	if(*j==c_enum_beg)
	  //   	  cout<<"E";
	  //   	else if(*j==c_type_beg)
	  //   	  cout<<"T";
	  //   	else if(*j==c_sep)
	  //   	  cout<<"S";
	  //   	else cout<<*j;
	  //     cout<<endl;
	  //   }
	  for(typeof(code.begin()) j=code.begin();j!=code.end();)
	    {
	      ++seg;
	      switch(*j)
		{
		case ' ':
		  for(;j!=code.end() && *j==' ';++j,++off_in_code)
		    ;
		  yout<<"TOK_BLANK ";
		  break;
		case c_sep:
		  ++j,++off_in_code;
		default:
		  string token;
		  for(;offi<(int)off.size() && off[offi].first<off_in_code-1;++offi)
		    ;
		  bool is_string=true;
		  if(offi<(int)off.size() && off[offi].first==off_in_code-1)
		    {
		      //may be a type or enum;
		      off[offi].first=seg;
		      ++offi;
		      is_string=false;
		    }
		  if(!is_string)
		    {
		      // //cout<<*j<<endl;
		      // if(!(*j==c_type_beg || *j==c_enum_beg))
		      // 	{
		      // 	  cout<<code<<endl;
		      // 	  yout<<offi<<' '<<off.size()<<' '<<seg<<endl;
		      // 	  FR(i,off)
		      // 	    yout<<i->first<<' '<<i->second<<endl;
		      // 	}
		      assert(*j==c_type_beg || *j==c_enum_beg);
		      ++off_in_code;
		      ++j;
		    }
		  else {
		      //cout<<*j<<endl;
		      // if((*j==c_type_beg || *j==c_enum_beg))
		      // 	{
		      // 	  cout<<code<<endl;
		      // 	  cout<<offi<<' '<<off.size()<<' '<<seg<<endl;
		      // 	  FR(i,off)
		      // 	    cout<<i->first<<' '<<i->second<<endl;
		      // 	  cout<<binary<<endl;
		      // 	}
		      assert(!(*j==c_type_beg || *j==c_enum_beg));
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
			  if(check_is_int(token))
			    int_list.push_back(make_pair((ll)tmp,strtoll(token.c_str(),NULL,10)));
			  lout<<"\""<<token<<"\""<<" return TOK_"<<(ll)tmp<<";"<<endl;
			}
		      yout<<"TOK_"<<(ll)tmp<<" ";
		    }
		  else
		    {
		      yout<<token<<' ';
		      if(token.compare(0,5,"type_")==0)
			{
			  for(typeof(token.rbegin()) i=token.rbegin();;++i)
			    if(*i=='_')
			      {
				++i;
				int num(0);
				for(int j=1;*i!='_';++i,j*=10)
				  num=num+j*(*i-'0');
				len.push_back(num);
				break;
			      }
			}
		      else len.push_back(-1);
		    }
		  break;
		}
	    }
	  assert(offi==(int)off.size());
	  yout<<endl<<"{static char tmp[]=\""<<binary<<"\";"<<endl;
	  // if(n=="tctcore_0")
	  //   {
	  //     cout<<code<<endl;
	  //     yout<<offi<<' '<<off.size()<<' '<<seg<<endl;
	  //     FR(i,off)
	  // 	yout<<i->first<<' '<<i->second<<endl;
	  //   }
	  yout<<"int i;\ni^=i;\n";
	  FR(i,off)
	    {
	      yout<<"for(i=0"<<";$"<<(i->first)<<"[i];"<<"++i)"<<endl;
	      yout<<"tmp[i+"<<i->second<<"]=$"<<(i->first)<<"[i];"<<endl;
	    }
	  yout<<"$$=tmp;";
	  yout<<"}"<<endl;
	  yout<<";"<<endl;
	}
    }
  
  //output rules for type

  int type_size=(int)ir.type_size();
  FOR(i,0,type_size)
    {
      Type ty=ir.get_type(i);
      string name=ty.get_name();
      int len=ty.get_len();
      name="type_"+name+"_"+int2string(ty.len)+"_"+ty.get_type();
      tokout<<"%type<chp> "<<name<<endl;
      yout<<name<<": ";
      yout<<"rule_int" ;
      yout<<"{\n";
      yout<<"static char tmp["<<len<<"];"<<endl;
      yout<<"i2bs(tmp,$1,"<<len<<");"<<endl;
      yout<<"$$=tmp;}"<<endl;
      yout<<"|"<<" TOK_LABEL{"<<endl;
      yout<<"static char tmp["<<len<<"];"<<endl;
      yout<<"int i;\ni^=i;\n";
      yout<<"for(i=0;i<"<<len<<";++i)"<<endl;
      yout<<"tmp[i]='L';"<<endl;
      yout<<"$$=tmp;}"<<endl;
      yout<<";"<<endl;
    }
  
  yout<<"rule_int: TOK_INT {$$=$1;}";
  FR(i,int_list)
    yout<<"| TOK_"<<i->first<<" {$$="<<i->second<<";};"<<endl;
  yout<<";\n";

  lout<<"[_a-zA-Z][_a-zA-Z0-9]*	{\n\
        dummy_lval.chp=newstr1(&strsta,yytext);/*TODO*/return TOK_LABEL;}"<<endl;
  lout<<"[0-9]+	{dummy_lval.integer=atoi(dummy_text);return TOK_INT;}"<<endl;

  //lout<<"[\"0\"|\"1\"] dummy_lval=(*dummytext)=='1'?1:0;return C01;\n";


  lout<<"%%\n\
int yywrap()\n\
{\n\
        return 1;\n\
}\n";
  yout<<"%%\nvoid yyerror(const char *s)\n{";
  yout<<"fprintf (stderr, \"L%d: %s \\n\",dummy_lineno,s);\n}\n";

  yout.close();
  tokout.close();
  string cmd="cat "+token_file_name+" "+y_file_name+" > "+"_"+y_file_name;
  system(cmd.c_str());
  return 0;
}
