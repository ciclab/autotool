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
class bfd_info
{
public:
  string name;
  int off;
  int off_len;
  int instr_len;
  int right_shift;
  bool pcrel;
  bfd_info(string n,int o,int ol,int il,int rs,bool p):
    name(n),off(o),off_len(ol),instr_len(il),right_shift(rs),pcrel(p){};
};

// check if a token name is type or addr 
static bool isTypeAddr(const string s)
{
  // TODO this may confuse other name definition
  return (s.compare(0,5,"type_")==0 || s.compare(0,5,"addr_")==0);
}
string funcName2ClassName( string funcName)
{
  // assert( funcName.compare( 0, 5, "FUNC_" ) == 0 );
  string className = "class_";
  // className.append( funcName.begin() + 5, funcName.end() );
  className.append( funcName.begin(), funcName.end() );
  return className;
}
// now every addr type name is translated to addr_name_true/false_width_rightshift
static int getRightShiftByName(const string s)
{
  assert(isTypeAddr(s));
  if(s.compare(0,5,"type_")==0)
    return 0;
  // is addr
  int r=0;
  int i=s.length()-1,j=1;
  for(;s[i]!='_';--i)
    r=r+j*(int)(s[i]-'0');
  return r;
}
static bool AddrIsPcrel(const string s)
{
  int i=s.length()-1;
  for(;s[i]!='_';--i)
    ;
  for(--i;s[i]!='_';--i)
    ;
  --i;
  return s[i-1]=='u';
}
static vector<bfd_info> bfd_list;
static void dfs_gen(ofstream & out,vector<pps> &binary_func,vector<int> &in,int depth)
{
  if(in.size()==0)
    return;
  if(in.size()==1)
    {
      out<<"return "<<binary_func[in[0]].second<<"(info,c,"<<binary_func[in[0]].first.length()<<",pc);\n";
      return;
    }
  //test if all depth bit in existing binary is '-'
  FRA(i,in)
    if((int)binary_func[*i].first.length()<=depth)
      {
	cerr<<"binary ambitious definition\n";
	FRA(j,in)
	  cerr<<binary_func[*j].first<<' '<<binary_func[*j].second<<endl;
	assert(0);
      }
  vector<int> tmp0,tmp1;
  FRA(i,in)
    {
      char z=(binary_func[*i].first)[depth];
      if(z=='0' || z=='-')
	tmp0.push_back(*i);
      if(z=='1' || z=='-')
	tmp1.push_back(*i);
    }
  if(tmp0.size()==in.size() || tmp1.size()==in.size())
    dfs_gen(out,binary_func,in,depth+1);
  else
    {
      out<<"if(c["<<depth<<"]=='0')\n{";
      dfs_gen(out,binary_func,tmp0,depth+1);
      out<<"}\n";
      out<<"else\n{";
      dfs_gen(out,binary_func,tmp1,depth+1);
      out<<"}\n";
    }
}
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
      r[w-i-1]=(v&1)?'1':'0';
      v>>=1;
    }
  return r;
}
static bool check_is_int(string c)
{
  FRA(i,c)
    if(*i<'0' || *i>'9')
      return false;
  return (int)c.length()>0;
}
static hash_control binaryHash,rule2func;
struct binary_info
{
  vector<string> toks;
  vector<int> toks_in_binary;
  vector<ppi> off;
  string func_name;
};

// check if binary and its corresponding info has been used.
// check if there is different instructino using same binary,
// if so, printf err info
bool emp_tag;
static binary_info emp; // no use, just idenify empty binary rule
static const binary_info*  checkBinary(const string rbinary,
			const vector<string> &toks,
			const vector<int> &toks_in_binary,
			const vector<ppi> &off,
			const string name)
{
  // allow empty binary 
  if(rbinary=="")
    {
      emp_tag=true;
      rule2func.insert(name,&emp);
      return &emp;
    }
  binary_info *a=(binary_info*)binaryHash.find(rbinary);
  if(a==NULL)
    {
      a=new(binary_info);
      a->toks=toks,a->toks_in_binary=toks_in_binary;
      a->off=off;
      a->func_name=name;
      binaryHash.insert(rbinary,a);
      rule2func.insert(name,a);
      return NULL;
    }
  bool err=false;
  if(a->toks.size()!=toks.size() || a->toks_in_binary.size()!=toks_in_binary.size() ||
     a->off.size()!=off.size())
    {
      err=true;
    }
  for(int i=0;!err && i<(int)toks.size();++i)
    {
      if(a->toks[i]!=toks[i])
	err=true;
      if(toks_in_binary[i]<0)
	{

	}
      else
	{
	  //if(toks[i].compare(0,5,"type_")!=0 && toks[i].compare(0,5,"addr_")!=0)
	  if(a->off[a->toks_in_binary[i]].second!=off[toks_in_binary[i]].second)
	    err=true;
	}
    }
  if(err)
    cerr<<"ERR: same bianry with deferent instruction"<<endl;
  else rule2func.insert(name,a);
  return a;
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
  tokout<<"#include \"config.h\"\n";
  tokout<<"#include \"bfd.h\"\n";
  tokout<<"#include \"strstack.h\"\n";
  tokout<<"#include <stdio.h>\n";
  tokout<<"#include <string.h>\n";
  tokout<<"extern char * yyret[];\n";
  tokout<<"extern int instr_cnt;\n";
  tokout<<"extern int offset_cnt[];\n"; 
  tokout<<"extern int dummy_lineno;\n";
  tokout<<"extern void dummy_error(const char *s);\n";
  tokout<<"extern struct strstack strsta;\n";
  tokout<<"extern int dummy_lex(void);\n";
  tokout<<"extern int get_expr(char * str,int bfd_type);\n";
  tokout<<"%}\n";
  tokout<<"%union{\n";
  tokout<<"int integer;\n";
  tokout<<"char ch;\n";
  tokout<<"char * chp;\n";
  tokout<<"}\n";
  tokout<<"%locations;\n";
  //lex rule name should be unique
  hash_control hc;
  // name for generated for bfd should be unique
  hash_control hc_bfd;
  // hash_control hc_len;
  char * cnt(NULL);
  ++cnt;
  // '|' <- used for seperator in vliw instruction
  hc.insert("|",cnt);
  lout<<"\"|\" return TOK_"<<(ll)cnt<<";\n";
  tokout<<"%token TOK_"<<(ll)cnt<<endl;

  tokout<<"%type<integer> rule_int"<<endl;
  tokout<<"%token<integer> TOK_INT"<<endl;
  tokout<<"%token<chp> TOK_LABEL"<<endl;
  tokout<<"%token TOK_BLANK"<<endl;
  yout<<"%%\n";



  // disassembler file
  // ofstream dlout;
  ofstream dcout,dhout,dlout,dyout,dytokout;
  // string dl_file_name=argv[2];
  // dl_file_name="dis_"+dl_file_name;
  string dy_file_name=argv[3];
  dy_file_name="dis_"+dy_file_name+".y";
  string dc_file_name=argv[3];
  dc_file_name="dis_"+dc_file_name+".c";
  string dh_file_name=argv[3];
  dh_file_name="dis_"+dh_file_name+".h";
  string dl_file_name=argv[3];
  dl_file_name="dis_"+dl_file_name+".lex";
  string dytok_file_name=argv[3];
  dytok_file_name="dis_"+dytok_file_name+".tok";
  
  dhout.open(dh_file_name.c_str(),ofstream::out);
  dcout.open(dc_file_name.c_str(),ofstream::out);
  dlout.open(dl_file_name.c_str(),ofstream::out);
  dyout.open(dy_file_name.c_str(),ofstream::out);
  // out bison file for disassembler of simulator
  ofstream syout, sytokout, shout, slout;
  // TODO configurable name
  string sy_file_name = "sim_dis.y";
  syout.open(sy_file_name, ofstream::out);
  string sytok_file_name = "sim.tok";
  sytokout.open( sytok_file_name, ofstream::out);
  string sh_file_name = "sim_dis.h";
  shout.open( sh_file_name, ofstream::out);
  string sl_file_name = "sim_dis.lex";

  dytokout.open(dytok_file_name.c_str(),ofstream::out);
  dlout<<"%{\n";
  dlout<<"#include \"opcode/dis_as.h\"\n";// TODO file name should be configurable
  dlout<<"#define YY_NO_INPUT\n";// suppress warning: input defined but not used
  dlout<<"%}\n";
  dlout<<"%option nounput\n";// suppress warning: yyunput defined but not used
  dlout<<"%%\n";
  dytokout<<"%{\n";
  sytokout<<"%{\n";
  // TODO function name should be configurable
  dytokout<<"extern void dis_error(const char *s);\n";
  dytokout<<"extern int dis_lex(void);\n";
  dytokout<<"#include \"opcode/dis_as.y.h\"\n";
  dytokout<<"%}\n";
  sytokout<<"extern void dis_error(const char *s);\n";
  sytokout<<"extern int dis_lex(void);\n";
  sytokout<<"#include \"class.h\"\n";
  // TODO configurable file name
  sytokout<<"#include \"sim_dis.h\"\n";
  // TODO a configurable number instead of 100 
  sytokout << " int sim_dis_list_len[100];\n";
  sytokout << " int sim_dis_list_cnt;\n";
  sytokout << " _class_instr_ * sim_dis_list[100];\n";
  sytokout<<"%}\n";

  dhout<<"#ifndef DH_H"<<endl;
  dhout<<"#define DH_H"<<endl;
  shout << "#ifndef SH_H " << endl;
  shout << "#define SH_H " << endl;
  dhout<<"extern int (*dis_list[100])(char *);\nint dis_list_len[100],dis_list_cnt;\n";

  // dtokout<<"%{\n";
  // dtokout<<"#include <stdio.h>\n";
  // dtokout<<"#include <string.h>\n";
  // dtokout<<"#include \"strstack.h\"\n";
  // dtokout<<"extern void output(const char *,const char *);\n";
  // dtokout<<"char dyyret[1000]/*TODO*/;\n";
  // dtokout<<"extern int ddummy_lineno;\n";
  // dtokout<<"extern void ddummy_error(const char *s);\n";
  // dtokout<<"extern int ddummy_lex(void);\n";
  // dtokout<<"#include \""<<dh_file_name<<"\""<<endl;
  // dtokout<<"%}\n";
  // dtokout<<"%union{\n";
  // dtokout<<"int integer;\n";
  // dtokout<<"char ch;\n";
  // dtokout<<"char * chp;\n";
  // dtokout<<"}\n";
  // dtokout<<"%locations;\n";
  

  //
  vector<pair<ll,ll> > int_list;
  //output rules for enum
  int enum_size=ir.get_num_enum();
  FOR(i,0,enum_size)
    {
      Enum enu;
      ir.get_enum(i,enu);
      int enum_ent_size=enu.size();
      int width=enu.width();
      string enum_name=enu.enum_name();
      tokout<<"%type <chp>"<<enum_name<<endl;
      yout<<enum_name<<": ";
      // hc_len.insert(enum_name,(void*)width);

      dcout<<"const char * FUNC_"<<enum_name<<"(char *c)\n";
      dhout<<"const char * FUNC_"<<enum_name<<"(char *c);\n";
      dcout<<"{\n";
      dcout<<"static const char * tmp[]={";

      FOR(j,0,enum_ent_size)
	{
	  if(j)
	    {
	      yout<<"|"<<endl;
	    }
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
	  yout<<"TOK_"<<(ll)en<<" {$$=(char*)\""<<int2binary(width,enu.ent_value(j))<<"\";}";
	  if(j!=0)
	    dcout<<",";
	  dcout<<'"'<<int2binary(width,enu.ent_value(j))<<'"';
	  dcout<<",";
	  dcout<<'"'<<ent_code<<'"';
	}
      yout<<";"<<endl;
      dcout<<"};\n";

      dcout<<"assert(tmp!=0);\n";// suppress compiler warning:  unused variable ‘tmp’ [-Werror=unused-variable]
      dcout<<"assert(c!=NULL);\n";// suppress compiler warning:  unused variable ‘c’ [-Werror=unused-variable]

      dcout<<"return get_entry(tmp,c,"<<enum_ent_size<<");\n}\n";
    }
  tokout<<"%start "<<top_rule_name<<endl;
  // dtokout<<"%start "<<top_rule_name<<endl;
  // tokout<<"%type<chp> "<<top_rule_name<<endl;
  // dtokout<<"%type<chp> "<<top_rule_name<<endl;
  yout<<top_rule_name<<": "<<endl;
  dyout<<top_rule_name<<": "<<endl;
  syout << top_rule_name << ":" << endl;
  // dyout<<top_rule_name<<": "<<endl;
  for(int i=0,j=0;i<instr_size;++i)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
	  if(j)
	    {
	      yout<<"|"<<endl;
	      dyout<<"|"<<endl;
	      syout << "|" << endl;
	    }
	  yout<<n<<endl;//"{yyret[0]=$1;}"<<endl; no use now
	  dyout<<n<<endl;
	  syout << n << endl;
	  ++j;
	}
    }
  yout<<";\n";
  dyout<<";\n";
  syout<<";\n";

  // record which rule is used
  vector<bool> useful;
  useful.resize(instr_size);
  fill(useful.begin(),useful.end(),false);
  hash_control packSubRuleName;
  for(int i=0;i<instr_size;++i)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
	  useful[i]=true;
	  if(ir.get_instr_type(i)=="e_pack")
	    {
	      vector<pair<string,string> > args;
	      ir.get_instr_arglist(i,args);
	      FRA(i,args)
		packSubRuleName.insert(i->first,(void*)1);
	      FRA(i,args)
		{
		  for(int j=0;j<(int)i->second.size();++j)
		    {
		      string name;
		      for(;j<(int)i->second.size() && i->second[j]!=c_sep;++j)
			name=name+i->second[j];
		      packSubRuleName.insert(name,(void*)1);
		    }
		}
	    }
	}
    }
  for(int i=0;i<instr_size;++i)
    if(!useful[i])
      {
	string n=ir.get_instr_name(i);
	if(packSubRuleName.find(n))
	  useful[i]=true;
      }

  //output rules for instructions
  int max_reloc_num(0);//record max relocation number
  int max_binary_len(0);
  int max_slot_len(1);
  vector<pps> binary_func;
  int vliw_mode_off,vliw_mode_sig;
  bool vliw_mode_set=ir.get_vliw_mode(vliw_mode_sig,vliw_mode_off);
  FOR(i,0,instr_size)
    {
      if(!useful[i])
	continue;
      string n=ir.get_instr_name(i);
      string type=ir.get_instr_type(i);
      // if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
      if(type=="e_notpack")
	{
#if ASGEN_COUT==1
	  FRA(j,off)
	    cout<<j->first<<' '<<j->second<<endl;
	  cout<<endl<<endl;
#endif
	  // tokout<<"%type<chp> "<<n<<endl;
	  // dtokout<<"%type<chp> "<<n<<endl;
	  vector<ppi> off;
	  vector<int> reloc_info;
	  ir.get_instr_reloc_info(i,reloc_info);
	  ir.get_instr_off(i,off);
	  string code=ir.get_instr_code(i);
	  string binary=ir.get_instr_binary(i);
	  int off_in_code=0,offi=0;
	  vector<ppi> tmp=off;
	  // just make sequence of reloc_info the same as off
	  for(int i=0;i<(int)tmp.size();++i)
	    tmp[i].second=reloc_info[i];
	  sort(tmp.begin(),tmp.end());
	  for(int i=0;i<(int)tmp.size();++i)
	    reloc_info[i]=tmp[i].second;

	  sort(off.begin(),off.end());
	  yout<<n<<": ";
	  // dytokout<<"%token "<<n<<endl;
	  int seg(0);
	  vector<int> len;
	  vector<bool> need_bfd;
	  len.resize(off.size());
	  need_bfd.resize(off.size());
	  // vector<int> right_shift;
	  // right_shift.resize(off.size());
 	  vector<string> toks;//record string tokens in code
	  vector<int> toks_in_binary;
	  for(auto j=code.begin();j!=code.end();)
	    {
	      ++seg;
	      switch(*j)
		{
		case c_sep:
		  ++j,++off_in_code;
		  if(*j==' ')
		    {
		      for(;j!=code.end() && *j==' ';++j,++off_in_code)
			;
		      yout<<"TOK_BLANK ";
		      toks.push_back(" ");
		      toks_in_binary.push_back(-1);
		      break;
		    }
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
		      // 	  FRA(i,off)
		      // 	    yout<<i->first<<' '<<i->second<<endl;
		      // 	}
		      assert(*j==c_type_beg || *j==c_enum_beg || *j==c_addr_beg);
		      ++off_in_code;
		      ++j;
		    }
		  else
		    {
		      //cout<<*j<<endl;
		      // if((*j==c_type_beg || *j==c_enum_beg))
		      // 	{
		      // 	  cout<<code<<endl;
		      // 	  cout<<offi<<' '<<off.size()<<' '<<seg<<endl;
		      // 	  FRA(i,off)
		      // 	    cout<<i->first<<' '<<i->second<<endl;
		      // 	  cout<<binary<<endl;
		      // 	}
		      assert(!(*j==c_type_beg || *j==c_enum_beg || *j==c_addr_beg));
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
			  if(token.length()==0)
			    cout<<"!!!!!!!!!!!!!!"<<endl;
			  if(check_is_int(token))
			    int_list.push_back(make_pair((ll)tmp,strtoll(token.c_str(),NULL,10)));
			  lout<<"\""<<token<<"\""<<" return TOK_"<<(ll)tmp<<";"<<endl;
			}
		      yout<<"TOK_"<<(ll)tmp<<" ";
		      toks.push_back(token);
		      toks_in_binary.push_back(-1);
		    }
		  else
		    {
		      yout<<token<<' ';
		      
		      // if(token.compare(0,5,"type_")==0 || token.compare(0,5,"addr_")==0)
		      if(isTypeAddr(token))
			{// is type or addr 
			  for(auto i = token.rbegin();;++i)
			    if(*i=='_')
			      {
				++i;
				int num(0);
				for(int j=1;*i!='_';++i,j*=10)
				  num=num+j*(*i-'0');
				len[offi-1]=num;
				need_bfd[offi-1]=true;
				break;
			      }
			}
		      else
			{//is enum
			  Enum tmp=ir.find_enum(token);
			  //cout<<n<<endl;
			  len[offi-1]=tmp.width();
			}
		      toks.push_back(token);
		      toks_in_binary.push_back(offi-1);
		    }
		  break;
		}
	    }
	  assert(offi==(int)off.size());
	  yout<<endl<<"{static char tmp[]=\""<<binary<<"\";"<<endl;

	  //output disassembler rules
	  // swap binary for little end
	  // for those instruction in vliw, we don't generate decode entry.
	  // we assume it already appeared in solo slot instructions
	  // if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	  string rbinary = binary;
	  // string rbinary_beg=binary;
	  string rbinary_end = binary;
	  // same as simGen.cpp, this control the vliw mode generated
	  if(vliw_mode_set)
	    {
	      assert(vliw_mode_sig==1);
	      if(binary.length())
		{
		  assert(binary.length()>vliw_mode_off);
		  assert(vliw_mode_sig==1);
		  assert(binary[vliw_mode_off] == '0');
		  // rbinary_beg[vliw_mode_off]='1';
		  rbinary_end[ vliw_mode_off ] = '1';
		}
	    }
	  assert((rbinary.length()%8)==0);
#ifdef LITTLE_END
	  for(int i=0,j=rbinary.length()-8;i<j;i+=8,j-=8)
	    for(int k=0;k<8;++k)
	      {
		swap(rbinary[i+k],rbinary[j+k]);
		// swap(rbinary_beg[i+k],rbinary_beg[j+k]);
		swap( rbinary_end[ i + k ], rbinary_end[ j + k ] );
	      }
#endif
	      
	  const binary_info *genDecInfo=checkBinary(rbinary,toks,toks_in_binary,
						    off,n);
	  // cout<<n<<' '<<rbinary.length()<<' '<<genDecInfo<<endl;
	  if(genDecInfo==NULL)
	    {
	      
	      // dhout<<"int "<<n<<"(struct disassemble_info *,char *,int insnLen,bfd_vma pc);\n";
	      dhout<<"int FUNC_"<<n<<"(char *);\n";
	      // dcout<<"int "<<n<<"(struct disassemble_info *info,char *c,int insnLen,bfd_vma pc){\n";
	      dcout<<"int FUNC_"<<n<<"(char *c){\n";
	      dcout<<"WST(c);\n";

	      binary_func.push_back(pps(rbinary,n));

	      if(rbinary.length())
		FRA(i,rbinary)
		  if(*i=='-')
		    dlout<<"[0|1]";
		  else dlout<<'\"'<<*i<<'\"';
	      dlout<<" {return "<<n<<";}\n";
	      if(vliw_mode_set)
		{
		  assert(vliw_mode_sig);
		  // if(rbinary_beg.length())
		  if( rbinary_end.length() )
		    {
		      // FRA(i,rbinary_beg)
		      FRA( i, rbinary_end )
			if(*i=='-')
			  dlout<<"[0|1]";
			else dlout<<'\"'<<*i<<'\"';
		    }
		  // dlout<<" {return "<<n<<"_beg"<<";}\n";
		  dlout << " { return "<< n << "_end" << ";}\n";
		}
	      dcout<<"static char tmp[]="<<'"'<<binary<<"\";"<<endl;
	      
	      dcout<<"assert(tmp!=0);\n";// suppress compiler warning:  unused variable ‘tmp’ [-Werror=unused-variable]
	      dcout<<"assert(c!=NULL);\n";// suppress compiler warning:  unused variable ‘c’ [-Werror=unused-variable]
	      
	      max_binary_len=max(max_binary_len,(int)binary.length());
	      for(int i=0;i<(int)rbinary.length();++i)
		if(rbinary[i]=='-')
		  {
		    dcout<<"tmp[";
		    int z=(rbinary.length()/8-1-i/8)*8+(i%8);
		    dcout<<z;
		    dcout<<"]=c["<<i<<"];\n";
		  }
	      for(int i=0;i<(int)toks.size();++i)
		{
		  if(toks_in_binary[i]<0)
		    {
		      dcout<<"output(\"%s\",\""<<toks[i]<<"\");\n";
		    }
		  else
		    {
		      //if(toks[i].compare(0,5,"type_")!=0 && toks[i].compare(0,5,"addr_")!=0)
		      if(!isTypeAddr(toks[i]))
			dcout<<"output(\"%s\",FUNC_"<<toks[i]<<"(tmp+"<<off[toks_in_binary[i]].second<<"));\n";
		      else // is an addr
			{
			  // (*info->print_address_func) (info->target, info);
			  // info->target = (GET_OP_S (l, DELTA) << 2) + pc + INSNLEN;
			  if(AddrIsPcrel(toks[i]))
			    dcout<<"outputAddr((FUNC_"<<toks[i]<<"(tmp+"
				 <<off[toks_in_binary[i]].second<<")<<"<<getRightShiftByName(toks[i])<<")+dis_pc"<<");\n";
			  else
			    dcout<<"outputAddr((FUNC_"<<toks[i]<<"(tmp+"
				 <<off[toks_in_binary[i]].second<<")<<"<<getRightShiftByName(toks[i])<<"));\n";
			}
		    }
		}
	      dcout<<"return "<<rbinary.length()/8<<";\n";
	      dcout<<"}\n";
	    }
	  else
	    {
	      // TODO
	      // if(rbinary.length())
	      // 	dcout<<"int(*"<<n<<")(char *)="<<genDecInfo->func_name<<";\n";
	    }
	  dhout<<"#define "<<n<<"_LEN "<<rbinary.length()<<endl;
	  shout << "#define " << n << "_LEN " << rbinary.length() << endl;

	  binary_info *bi=(binary_info*)binaryHash.find(rbinary);
	  // allow empty binary 
	  if(bi!=NULL)
	    {
	      if(bi->func_name!=n)
		{
		  dyout<<n<<" : "<<bi->func_name<<"{dis_list_len[dis_list_cnt]="<<rbinary.length()
		       <<";dis_list[dis_list_cnt]=FUNC_"<<bi->func_name<<";++dis_list_cnt;};\n";
		  string className = funcName2ClassName( bi->func_name );
		  syout<<n<<" : "<<bi->func_name<<"{ sim_dis_list_len[sim_dis_list_cnt]="<<rbinary.length()
		       <<";sim_dis_list[sim_dis_list_cnt]= new "<< className <<";++sim_dis_list_cnt;};\n";
		}
	      else
		{
		  dytokout<<"%token "<<n<<endl;
		  dytokout<<"%token "<<n<<"_end"<<endl;
		  sytokout<<"%token "<<n<<endl;
		  sytokout<<"%token "<<n<<"_end"<<endl;
		}
	    }
	  else
	    {
	      // TODO defalut to vliw seperator
	      dyout << n << ":{};\n";
	      syout << n << ":{};\n";
	    }

	  yout<<"int i;\ni^=i;\n";
	  vector<bfd_info> instr_bfd_info;
	  FRA(i,off)
	    {
	      //yout<<"for(i=0"<<";$"<<(i->first)<<"[i];"<<"++i)"<<endl;
	      if(need_bfd[(int)(i-off.begin())])
		{
		  // instr_bfd_info.push_back(ppi(i->second,len[(int)(i-off.begin())]));
		  yout<<"if(isnumber($"<<(i->first)<<"))"<<endl;
		  yout<<"{"<<endl;
		}
	      yout<<"for(i=0"<<";i<"<<len[(int)(i-off.begin())]<<";"<<"++i)"<<endl;
	      yout<<"tmp[i+"<<i->second<<"]=$"<<(i->first)<<"[i];"<<endl;
	      if(need_bfd[(int)(i-off.begin())])
		{
		  int l=len[(int)(i-off.begin())];
		  int o=binary.length()-(i->second+l);
		  yout<<"}"<<endl;
		  yout<<"else"<<endl;
		  yout<<"{\nint t=get_expr($"<<i->first<<",";
		  string bfd_name="BFD_DUMMY_"+int2string(o)+"_"+
		    int2string(l)+"_"+int2string((int)binary.length())+"_"+
		    ((reloc_info[(int)(i-off.begin())]&1)?(string)"true":(string)"false")+"_"+
		    int2string(reloc_info[(int)(i-off.begin())]>>1);
		  yout<<bfd_name<<");"<<endl;
		  yout<<"int j="<<(1<<(l-1))<<";"<<endl;
		  yout<<"for(i=0;i<"<<l<<";++i,j>>=1)//l<31\n";
		  yout<<"tmp["<<i->second<<"+i]=(t&j)?\'1\':\'0\';";
		  yout<<"}"<<endl;
		  //bfd_info(string n,int o,int ol,int il,int rs,bool p):
		  int ri=reloc_info[(int)(i-off.begin())];
		  instr_bfd_info.push_back(bfd_info(bfd_name,o,l,(int)binary.length(),ri>>1,
						    ri&1));
		}
	    }
	  // for those instruction in vliw, we don't gather bfd info.
	  // we assume it already appeared in solo slot instructions
	  if(genDecInfo==NULL )
	    {
	      //gether bfd_info for bfd
	      FRA(i,instr_bfd_info)
		{
		  //bfd_info(string n,int o,int ol,int il,int rs,bool p):
		  // int o=binary.length()-(i->first+i->second);//off set
		  // int l=i->second;// off len
		  // bool pcrel=reloc_info[(int)(i-off.begin())]&1;
		  // int rs=reloc_info[(int)(i-off.begin())]>>1;
		  // string bfd_name="BFD_DUMMY_"+int2string(o)+"_"+int2string(l)+"_"+int2string((int)binary.length())+"_"+
		  // 	(pcrel?"true":"false")+"_"+
		  // 	int2string(rs);
		  if(hc_bfd.find(i->name)==NULL)
		    {
		      hc_bfd.insert(i->name,(void*)(bfd_list.size()+1));
		      bfd_list.push_back(*i);
		    }
		}
	      max_reloc_num=max(max_reloc_num,(int)instr_bfd_info.size());
	    }
	  // yout<<"$$=tmp;\n";	  //  no need to return tmp now;
	  yout<<"yyret[instr_cnt]=tmp;\n";
	  yout<<"offset_cnt[++instr_cnt]=0;\n";
	  yout<<"}"<<endl;
	  yout<<";"<<endl;
	}
      else if(type == "e_pack" && n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
	  vector<pair<string,string> > args;
	  ir.get_instr_arglist(i,args);
	  yout<<n<<" : ";
	  dyout<<n<<" : ";
	  syout << n << " : " ;
	  FRA(i,args)
	    {
	      if(i!=args.begin())
		yout<<" TOK_1 "; // TOK_1 is '|', used as seperator between slots
	      yout<<i->first;
	      // dyout << i->first << ' ';
	    }
	  for( auto i = args.begin(); i != args.end(); ++i )
	    {
	      // dyout << i->first << ' ' ;
	      if( i != args.begin() )
	      	{
		  dyout << " | ";
		  syout << " | ";
		}
	      for( auto j = args.begin(); ; ++j )
	      	{
		  if( j != args.begin() )
		    {
		      dyout << ' ';
		      syout << ' ';
		    }
	      	  dyout<< j->first;
		  syout << j->first;
	      	  if( j == i )
	      	    break;
	      	}
	      dyout << "_end";
	      syout << "_end";
	    }
	  yout<<";"<<endl;
	  dyout<<";"<<endl;
	  syout << ";" << endl;
	  max_slot_len=max(max_slot_len,(int)args.size());
	  for( auto i = args.begin(); i != args.end(); ++i )
	    {
	      yout<<i->first<<" : ";
	      dyout<<i->first<<" : ";
	      syout << i->first << " : ";
	      for(int j=0;j<(int)i->second.size();++j)
		{
		  if(j)
		    {
		      yout<<" | \n";
		      dyout<<" | \n";
		      syout<<" | \n";
		    }
		  string name;
		  for(;j<(int)i->second.size() && i->second[j]!=c_sep;++j)
		    {
		      yout<<i->second[j];
		      name.push_back(i->second[j]);
		    }
		  
		  binary_info *bi=(binary_info*)rule2func.find(name);
		  if(bi!=&emp)
		    {
		      dyout<<name;
		      syout<<name;
		      auto ii = i;
		      ++ii;
		      dyout<<" {dis_list_len[dis_list_cnt]="<<name<<"_LEN "<<" ;dis_list[dis_list_cnt]=FUNC_"<<bi->func_name<<"; ++dis_list_cnt;}\n";
		      syout << " {sim_dis_list_len[sim_dis_list_cnt]="<<name<<"_LEN " <<
			" ;sim_dis_list[sim_dis_list_cnt]= new " << funcName2ClassName(bi->func_name) <<"; ++sim_dis_list_cnt;}\n";
		    }
		  else 
		    {
		      dyout<<"{}"<<endl;
		      syout << "{}" << endl;
		    }
		}
	      yout<<" ; "<<endl;
	      dyout<<" ; "<<endl;
	      syout << " ; " << endl;
	      dyout << i->first << "_end" << " : ";
	      syout << i->first << "_end" << " : ";
	      for( int j = 0, output = 0; j < (int) i->second.size(); ++j )
		{
		  string name;
		  for(;j<(int)i->second.size() && i->second[j]!=c_sep;++j)
		    {
		      name.push_back( i->second[j] );
		    }
		  
		  binary_info *bi=(binary_info*)rule2func.find(name);
		  if( bi != &emp )
		    {
		      if(output)
			{
			  dyout << " | \n";
			  syout << " | \n";
			}
		      dyout << name;
		      syout << name;
		      output = 1;
		    }
		  if(bi!=&emp)
		    {
		      dyout<<"_end";
		      syout << "_end";
		      dyout<<" {dis_list_len[dis_list_cnt]="<<name<<"_LEN "<<" ;dis_list[dis_list_cnt]=FUNC_"<<bi->func_name<<"; ++dis_list_cnt;}\n";
		      syout<<" {sim_dis_list_len[sim_dis_list_cnt]="<< name
			   <<"_LEN "<<" ;sim_dis_list[sim_dis_list_cnt]= new "<<
			funcName2ClassName( bi->func_name ) << "; ++sim_dis_list_cnt;}\n";
		    }
		  else 
		    {
		      // we do not allow end with empty binary
		      // dyout<<"{}"<<endl;
		      // syout << "{}" << endl;
		    }
		}
	      dyout << " ; " << endl;
	      syout << " ; " << endl;
	    }
	}
    }
  dhout<<"#define MAX_BINARY_LEN "<<max_binary_len<<endl;// !!TODO max_binary_len should recalculated with vliw info
  dhout<<"#define MAX_SLOT_LEN "<<max_slot_len<<endl;
  shout<<"#define MAX_BINARY_LEN "<<max_binary_len<<endl;// !!TODO max_binary_len should recalculated with vliw info
  shout<<"#define MAX_SLOT_LEN "<<max_slot_len<<endl;
  // dhout<<"int dis(struct disassemble_info *,char *c,bfd_vma pc);\n";
  // dcout<<"int dis(struct disassemble_info *info,char * c,bfd_vma pc)\n{";
  // dcout<<"void * unusd=(void*)s2hex;WST(unusd);unusd=(void*)s2int;WST(unusd);\n";
  vector<int> tmp;
  // FRA(i,binary_func)
  //   tmp.push_back(i-binary_func.begin());
  // dfs_gen(dcout,binary_func,tmp,0);
  dlout<<"%%\n";
  dlout<<"int yywrap()\n{\nreturn 1;\n}"<<endl;
  dytokout<<"%%\n";
  sytokout<<"%%\n";
  dyout<<"%%\n";
  dyout<<"void dis_error(const char *s){s=s;}"<<endl;
  syout<<"%%\n";
  syout<<"void dis_error(const char *s){s=s;}"<<endl;


  // TODO function name should be configurable
  // dyout<<"%%\nvoid dis_error(const char *s)\n{\n}\n";

  dyout.close();
  syout.close();
  dytokout.close();
  sytokout.close();
  string disy_file_name=argv[3];
  string tmpcmd="cat "+  dy_file_name  + " >> " + dytok_file_name;
  system(tmpcmd.c_str());
  tmpcmd="mv " + dytok_file_name + " " + dy_file_name;
  system(tmpcmd.c_str());

  tmpcmd = "cat " + sy_file_name + " >> " + sytok_file_name;
  system( tmpcmd.c_str() );
  tmpcmd = "mv " + sytok_file_name + " " + sy_file_name;
  system( tmpcmd.c_str() );

  // dcout<<"assert(0);\n";// there may be some problem with assembler
  // dcout<<"return 0;\n";
  // dcout<<"}\n";
  ofstream tout("tc-dummy2");
  // TODO 100 should be replaced by an exact number
  tout<<"static bfd_reloc_code_real_type offset_reloc[100]["<<max_reloc_num<<"];\n";
  tout<<"static expressionS expr_list[100]["<<max_reloc_num<<"];\n";
  tout<<"int instr_cnt;"<<endl;// how many expr_list and offset_reloc used
  tout<<"int offset_cnt[100];"<<endl;// how many entries in expr_list and offset_reloc used
  // TODO 1000 should be replaced by an exact number
  tout<<"char * yyret[1000];"<<endl;
  tout<<"void md_assemble (char *str)\n";
  tout<<"{\n";
  // for debug
  tout<<"printf(\"!%s!\\n\",str);\n";

  tout<<"YY_BUFFER_STATE bs=dummy__scan_string(str);\n";
  tout<<"memset(yyret,0,sizeof(yyret));\n";
  tout<<"instr_cnt=0;\n";
  tout<<"offset_cnt[instr_cnt]=0;\n";
  tout<<"dummy_parse();\n";
  tout<<"dummy__delete_buffer(bs);\n";
  tout<<"int cnt;\n";
  tout<<"int len_left=0;\n";
  tout << "int lastSlotIdx = -1;\n";
  // calculate total length (including vliw)
  tout<<"for(cnt=0;cnt<instr_cnt;++cnt)\n\n";
  tout<<"{int i=0;\n";
  if(vliw_mode_set)
    {
      assert(vliw_mode_sig==1);
      // tout<<"if(cnt==0) yyret[cnt]["<<vliw_mode_off<<"]='1';\n";
      tout<<"if( yyret[cnt][0] ) lastSlotIdx = cnt;\n";
    }
  tout<<"for(;yyret[cnt][i];++len_left,++i)\n;\n";
  tout<<"}\n";
  if( vliw_mode_set )
    {
      tout << " if( lastSlotIdx >= 0 ) \n";
	tout << " assert( yyret[lastSlotIdx][0] == '0' );\n";
      tout << " if( lastSlotIdx >= 0 ) yyret[lastSlotIdx][0] = '1';\n";
    }
  tout<<"len_left/=8;\n";
  tout<<"for(cnt=0;cnt<instr_cnt;++cnt)\n{\n";
  tout<<"int len;\n";
  tout<<"for(len=0;yyret[cnt][len];++len);\nlen/=8;\n";
  tout<<"len_left-=len;\n";
  tout<<"int i;\n";
  tout<<"char * f=frag_more(len);\n";      //TODO should be a variable
  tout<<"for(i=0;i<offset_cnt[cnt];++i)\n";
  tout<<"{\n";
   tout<<"reloc_howto_type *howto;\n";
  tout<<"howto = bfd_reloc_type_lookup(stdoutput, offset_reloc[cnt][i]);\n";
  tout<<"assert(howto);\n";
  tout<<"fixS * tmp=fix_new_exp(/*frag_now*/NULL,/*f-frag_now->fr_literal*/0,len,expr_list[cnt]+i,howto->pc_relative,offset_reloc[cnt][i]);\n";
  tout<<"tmp->fx_frag=frag_now;\n";
  tout<<"tmp->fx_where=f-frag_now->fr_literal;\n";
  tout<<"tmp->fx_addnumber = -len_left;\n";
  tout<<"}\n";
  tout<<"int j,k;\n";
  tout<<"for(j=0;j<len;++j)\n";
  tout<<"{f[j]=0;\n";
  tout<<"for(k=0;k<8;++k)\n";
#ifdef LITTLE_END
  tout<<"f[j]=(f[j]<<1)|('1'==yyret[cnt][(len-1-j)*8+k]?1:0);\n";
#else
  tout<<"f[j]=(f[j]<<1)|('1'==yyret[cnt][j*8+k]?1:0);\n";
#endif
  // for debug
  tout<<"printf(\"%02x\",(unsigned int)(unsigned char)f[j]);\n";
  tout<<"}\n";
  // for debug
  tout<<"printf(\"  \");\n";
  tout<<"}\n";
  // for debug
  if( vliw_mode_set )
    tout << " if( lastSlotIdx >= 0 ) yyret[lastSlotIdx][0] = '0';\n";
  tout<<"printf(\"\\n\");\n";
  tout<<"clear(&strsta);\n";
  tout<<"}\n";
  tout<<"void md_apply_fix(fixS * fixP, valueT * valP, segT seg ATTRIBUTE_UNUSED)\n";
  tout<<"{\n";
  tout<<"*valP += fixP->fx_addnumber;\n";
  /*TODO may be not only long long*/
  tout<<"long long value=(int)(*valP);/*TODO*/\n";
  tout<<"long long v,k,c;\n";
  tout<<"int i;\n";
  //tout<<"bfd_byte *buf;\n";
  tout<<"reloc_howto_type *howto;\n";
  tout<<"howto = bfd_reloc_type_lookup(stdoutput, fixP->fx_r_type);\n";
  tout<<"if (!howto)\n";
  tout<<"return;\n";
  tout<<"bfd_byte * buf = (bfd_byte *) (fixP->fx_frag->fr_literal + fixP->fx_where);\n";
  tout<<"if (fixP->fx_addsy == NULL && !fixP->fx_pcrel && fixP->fx_tcbit == 0)\n";
  tout<<"fixP->fx_done = 1;\n";
  tout<<"switch (fixP->fx_r_type) {\n";
  FRA(i,bfd_list)
    {
      tout<<"case "<<i->name<<":"<<endl;
      tout<<"if(fixP->fx_done)\n{\n";
      int o=i->off,l=i->off_len;
      int binary_len=i->instr_len;
      int rs=i->right_shift;
      /*TODO*/
      //assert((binary_len%8)==0);
      tout<<"v=0;\n";
      int bytes=binary_len/8;
      tout<<"for(i=0;i<"<<bytes<<";++i)\n";
#ifdef LITTLE_END
      tout<<"v=(v<<8)|buf["<<bytes-1<<"-i];\n";
#else
      tout<<"v=(v<<8)|buf[i];\n";
#endif
      tout<<"k=value&((1LL<<"<<l<<")-1);\n";
      tout<<"k>>="<<rs<<';'<<endl;
      // k may be negative, so after left shift, complete leading 1s
      ll msk=0,mm=(1LL<<(l))>>rs;
      for(int i=0;i<rs;++i,mm<<=1)
	msk|=mm;
      tout<<"if(k&((1LL<<"<<(l-1)<<")>>"<<rs<<"))\n";
      tout<<"k|="<<msk<<"LL;\n";

      tout<<"c=((1LL<<"<<l<<")-1)<<"<<o<<";\n";
      tout<<"v=(v&(~c))|(k<<"<<o<<");\n";
      tout<<"for(i=0;i<"<<bytes<<";++i,v>>=8)\n";
#ifdef LITTLE_END
      tout<<"buf[i]=v&((1<<8)-1);\n";
#else
      tout<<"buf["<<bytes-1<<"-i]=v&((1<<8)-1);\n";
#endif
      tout<<"}\n";
      tout<<"break;\n";
    }
  tout<<"default:\n";
  tout<<"printf(\"internal error\");\n";
  tout<<"break;\n";
  tout<<"}";
  tout<<"fixP->fx_addnumber = *valP;\n}\n";
  tout.close();
  system("cat ../src/as/tc-dummy1 ./tc-dummy2 ../src/as/tc-dummy3 > tc-dummy.c;\
indent ./tc-dummy.c");

  // output reloc info 
  ofstream bout("coff-dummy2");
  bout<<"static reloc_howto_type mips_howto_table[] =\n{\n";
  FRA(i,bfd_list)
    {
      if(i!=bfd_list.begin())
	bout<<",\n";
      bout<<"HOWTO ("<<i->name<<",	/* type */\n";
      bout<<i->right_shift<<",			/* TODO rightshift */\n";//TODO my be variable
      bout<<(i->instr_len>=32?2:1)<<",			/* TODO!! size (0 = byte, 1 = short, 2 = long) */\n";
      // bout<<i->instr_len<<",			/* bitsize */\n";
      bout << "0X" << i->off_len << ",			/* bitsize */\n";
      bout<<i->pcrel<<",			/* pc_relative */\n";
      /*TODO output hex default? so i add "ox"*/
      bout<< "0X" <<(i->off)<<",			/* bitpos */\n";
      bout<<"complain_overflow_signed, /*TODO complain_on_overflow */\n";
      bout<<"mips_generic_reloc,			/* special_function */\n";
      bout<<"\""<<i->name<<"\",		/* name */\n";
      bout<<i->pcrel<<",\n"; // TODO this need a new attr in deslanguage
      // bout<<"TRUE,			/* partial_inplace */\n";
      //calculate mask
      int msk(0);//now only 32bit
      for(int j=0;j<i->off_len;++j)
	msk|=(1<<(j+i->off));
      bout<<"0X"<<std::hex<<msk<<",			/* TODO src_mask */\n";
      bout<<"0X"<<std::hex<<msk<<",			/* TODO dst_mask */\n";
      bout<<"TRUE)		/* TODO pcrel_offset */\n";
    }
  bout<<"};\n";


  bout<<"/* Get the howto structure for a generic reloc type.  */\n";
  bout<<"static reloc_howto_type *mips_bfd_reloc_type_lookup\
 (bfd *abfd ATTRIBUTE_UNUSED,\
bfd_reloc_code_real_type code)\n{";
  bout<<"PT\n";
  bout<<"\
  switch (code)\n\
    {\n";
  FRA(i,bfd_list)
    {
      bout<<"case "<<i->name<<":"<<endl;
      bout<<"return "<<"mips_howto_table+"<<(int)(i-bfd_list.begin())<<";\nbreak;"<<endl;
    }
  bout<<"default:\n\
      return (reloc_howto_type *) NULL;\n\
    }\n\
  return NULL;\n}\n";
  
  ofstream rout("reloc2");
  if(bfd_list.size()>0)
    {
      // for content in bfd/doc/reloc.c
      FRA(i,bfd_list)
	{
	  if(i==bfd_list.begin())
	    rout<<"ENUM\n  "<<i->name<<endl;
	  else rout<<"ENUMX\n  "<<i->name<<endl;
	}
      rout<<"ENUMDOC\n  DUMMY\n"<<endl;
    }
  rout.close();
  system("cat ../src/as/reloc1 ./reloc2 ../src/as/reloc3 > reloc.c;\
indent ./reloc.c");

  ofstream rtout("reloct2");
  if(bfd_list.size()>0)
    {
      // for content in bfd/doc/reloc.texi
      FRA(i,bfd_list)
	{
	  if(i==bfd_list.begin())
	    rtout<<"@deffn {} "<<i->name<<endl;
	  else
	    rtout<<"@deffnx {} "<<i->name<<endl;
	  //rout<<"Adapteva EPIPHANY -"<<i->first<<endl;
	}
      rtout<<"@end deffn"<<endl;
      rtout<<"DUMMY\n";
    }
  rtout.close();
  system("cat ../src/as/reloct1 ./reloct2 ../src/as/reloct3 > reloc.texi");


  //output rules for type 
  int type_size=(int)ir.type_size();
  FOR(i,0,type_size)
    {
      Type ty=ir.get_type(i);
      string name=ty.get_name();
      int len=ty.get_len();
      name="type_"+name+"_"+int2string(len)+"_"+ty.get_type();
      tokout<<"%type<chp> "<<name<<endl;
      yout<<name<<": ";
      yout<<"rule_int" ;
      yout<<"{\n";
      yout<<"static char tmp["<<len<<"];"<<endl;
      yout<<"i2bs(tmp,$1,"<<len<<");"<<endl;
      yout<<"$$=tmp;}"<<endl;
      yout<<"|"<<" TOK_LABEL{"<<endl;
      // yout<<"static char tmp["<<len<<"];"<<endl;
      // yout<<"int i;\ni^=i;\n";
      // yout<<"for(i=0;i<"<<len<<";++i)"<<endl;
      // yout<<"tmp[i]=$1[i];"<<endl;
      // yout<<"$$=tmp;}"<<endl;
      yout<<"$$=$1;}\n";
      yout<<";"<<endl;
      
      if(isTypeAddr(name))
	{
	  dcout<<"int FUNC_"<<name<<"(char * c)\n{return s2int(c,"<<len<<");}\n";
	  dhout<<"int FUNC_"<<name<<"(char * c);\n";
	}
      else
	{
	  dcout<<"const char * FUNC_"<<name<<"(char * c)\n{return s2hex(c,"<<len<<");}\n";
	  dhout<<"const char * FUNC_"<<name<<"(char * c);\n";
	}
    }
  //output rules for addr
  int addr_size=(int)ir.addr_size();
  FOR(i,0,addr_size)
    {
      Addr ta;
      ir.get_addr(i,ta);
      string name=ta.get_name();
      int width=ta.get_width();
      int rs=ta.get_right_shift();
      name="addr_"+name+"_"+(ta.get_pcrel()?"true":"false")+"_"+int2string(width)+"_"+int2string(rs);
      tokout<<"%type<chp> "<<name<<endl;
      yout<<name<<": ";
      yout<<"rule_int" ;
      yout<<"{\n";
      yout<<"static char tmp["<<width<<"];"<<endl;
      yout<<"i2bs(tmp,$1,"<<width<<");"<<endl;
      yout<<"$$=tmp;}"<<endl;
      yout<<"|"<<" TOK_LABEL{"<<endl;
      // yout<<"static char tmp["<<width<<"];"<<endl;
      // yout<<"int i;\ni^=i;\n";
      // yout<<"for(i=0;i<"<<width<<";++i)"<<endl;
      // yout<<"tmp[i]=$1[i];"<<endl;
      // yout<<"$$=tmp;}"<<endl;
      yout<<"$$=$1;}\n";
      yout<<";"<<endl;

      if(isTypeAddr(name))
	{
	  dcout<<"int FUNC_"<<name<<"(char * c)\n{return s2int(c,"<<width<<");}\n";
	  dhout<<"int FUNC_"<<name<<"(char * c);\n";
	}
      else
	{
	  dcout<<"const char * FUNC_"<<name<<"(char * c)\n{return s2hex(c,"<<width<<");}\n";
	  dhout<<"const char * FUNC_"<<name<<"(char * c);\n";
	}
    //   dcout<<"const char *"<<name<<"(char * c,int insnLen,bfd_vma pc)\n{WST(insnLen);WST(pc);return s2hex(c,"<<width<<");}\n";
    //   dhout<<"const char *"<<name<<"(char * c,int insnLen,bfd_vma pc);\n";
    }

  bout.close();
  system("cat ../src/as/coff-dummy1 \
./coff-dummy2 \
../src/as/coff-dummy3 \
 ../src/as/coff-dummy4 > coff-dummy.c; indent ./coff-dummy.c");


  yout<<"rule_int: TOK_INT {$$=$1;}";
  FRA(i,int_list)
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
  yout<<"%%\nvoid dummy_error(const char *s)\n{";
  yout<<"fprintf (stderr, \"L%d: %s \\n\",dummy_lineno,s);\n}\n";

  yout.close();
  tokout.close();
  string cmd="cat "+token_file_name+" "+y_file_name+" > "+"_"+y_file_name;
  system(cmd.c_str());

  // dyout<<"%%"<<endl;
  // dyout.close();
  // dtokout<<"%%"<<endl;
  // dtokout.close();
  // dcout<<"void yyerror(const char *s)\n";
  // dcout<<"{fprintf (stderr, \"L%d: %s \\n\",ddummy_lineno,s);\n";
  // dcout<<"}\n";

  dcout.close();
  dhout<<"\n#endif"<<endl;
  shout << "\n#endif" << endl;
  dhout.close();
  shout.close();
  cmd=(string)"cat "+(string)"../src/as/dummy-dis1.c"+(string)" "+dh_file_name+" "+"../src/as/dummy-dis2.c"+" "+dc_file_name+(string)" > dummy-dis.c";
  system(cmd.c_str());

  cmd = (string)"sed  --expression '2i #include \"sim_dis.y.h\"' --expression '2d ' " + dl_file_name + (string)" > " + sl_file_name;
  system( cmd.c_str() );
  return 0;
}
