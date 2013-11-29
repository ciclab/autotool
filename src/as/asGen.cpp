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
static vector<bfd_info> bfd_list;
static void dfs_gen(ofstream & out,vector<pps> &binary_func,vector<int> &in,int depth)
{
  if(in.size()==0)
    return;
  if(in.size()==1)
    {
      out<<"return "<<binary_func[in[0]].second<<"(info,c);\n";
      return;
    }
  //test if all depth bit in existing binary is '-'
  FR(i,in)
    if((int)binary_func[*i].first.length()<=depth)
      {
	cerr<<"binary ambitious definition\n";
	FR(j,in)
	  cerr<<binary_func[*j].second<<endl;
	assert(0);
      }
  vector<int> tmp;
  FR(i,in)
    {
      char z=(binary_func[*i].first)[depth];
      if(z=='0' || z=='-')
	tmp.push_back(*i);
    }
  out<<"if(buf["<<depth<<"]=='0')\n{";
  dfs_gen(out,binary_func,tmp,depth+1);
  out<<"}\n";
  tmp.resize(0);
  FR(i,in)
    {
      char z=(binary_func[*i].first)[depth];
      if(z=='1' || z=='-')
	tmp.push_back(*i);
    }
  out<<"else\n{";
  dfs_gen(out,binary_func,tmp,depth+1);
  out<<"}\n";
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
  FR(i,c)
    if(*i<'0' || *i>'9')
      return false;
  return (int)c.length()>0;
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
  tokout<<"extern char * yyret;"<<endl;
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
  hash_control hc_bfd;
  // hash_control hc_len;
  char * cnt(NULL);
  tokout<<"%type<integer> rule_int"<<endl;
  tokout<<"%token<integer> TOK_INT"<<endl;
  tokout<<"%token<chp> TOK_LABEL"<<endl;
  tokout<<"%token TOK_BLANK"<<endl;
  yout<<"%%\n";



  //disassembler file
  // ofstream dlout;
  ofstream dcout,dhout;
  // string dl_file_name=argv[2];
  // dl_file_name="dis_"+dl_file_name;
  string dy_file_name=argv[3];
  dy_file_name="dis_"+dy_file_name;
  string dc_file_name=argv[3];
  dc_file_name="dis_"+dc_file_name+".c";
  string dh_file_name=argv[3];
  dh_file_name="dis_"+dh_file_name+".h";
  dhout.open(dh_file_name.c_str(),ofstream::out);
  dcout.open(dc_file_name.c_str(),ofstream::out);
  dhout<<"#ifndef DH_H"<<endl;
  dhout<<"#define DH_H"<<endl;
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

      dcout<<"const char *"<<enum_name<<"(char *c)\n";
      dhout<<"const char *"<<enum_name<<"(char *c);\n";
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
      dcout<<"return get_entry(tmp,c,"<<enum_ent_size<<");\n}\n";
    }
  tokout<<"%start "<<top_rule_name<<endl;
  // dtokout<<"%start "<<top_rule_name<<endl;
  tokout<<"%type<chp> "<<top_rule_name<<endl;
  // dtokout<<"%type<chp> "<<top_rule_name<<endl;
  yout<<top_rule_name<<": "<<endl;
  // dyout<<top_rule_name<<": "<<endl;
  for(int i=0,j=0;i<instr_size;++i)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
	  if(j)
	    {
	      yout<<"|"<<endl;
	      // dyout<<"|"<<endl;
	    }
	  yout<<n<<"{yyret=$1;}"<<endl;
	  // dyout<<n<<"{}"<<endl;
	  ++j;
	}
    }
  yout<<";\n";
  // dyout<<";\n";

  // dtokout<<"%type<ch> TOK_01"<<endl;
  // dtokout<<"%token TOK_0"<<endl;
  // dtokout<<"%token TOK_1"<<endl;
  // dyout<<"TOK_01: TOK_0 {return '1';}|TOK_1 {return '0';};\n";
  //output rules for instructions
  int max_reloc_num(0);//record max relocation number
  int max_binary_len(0);
  vector<pps> binary_func;
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
	  dcout<<"int "<<n<<"(struct disassemble_info *info,char *c){\n";
	  dhout<<"int "<<n<<"(struct disassemble_info *,char *);\n";
	  int seg(0);
	  vector<int> len;
	  vector<bool> need_bfd;
	  len.resize(off.size());
	  need_bfd.resize(off.size());
	  vector<int> right_shift;
	  right_shift.resize(off.size());
 	  vector<string> toks;//record string tokens in code
	  vector<int> toks_in_binary;
	  for(typeof(code.begin()) j=code.begin();j!=code.end();)
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
		      // 	  FR(i,off)
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
		      // 	  FR(i,off)
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
		      if(token.compare(0,5,"type_")==0 || token.compare(0,5,"addr_")==0)
			{// is type
			  for(typeof(token.rbegin()) i=token.rbegin();;++i)
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
	  string rbinary=binary;
	  assert((rbinary.length()%8)==0);
	  for(int i=0,j=rbinary.length()-8;i<j;i+=8,j-=8)
	    for(int k=0;k<8;++k)
	      swap(rbinary[i+k],rbinary[j+k]);
	  // FR(i,rbinary)
	  //   if(*i=='0')
	  //     dyout<<"TOK_0 ";
	  //   else if(*i=='1')
	  //     dyout<<"TOK_1 ";
	  //   else dyout<<"TOK_01 ";
	  // dyout<<"\n{\n";
	  binary_func.push_back(pps(rbinary,n));
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
	  	  dcout<<"output(info,\"%s\",\""<<toks[i]<<"\");\n";
	  	}
	      else
	  	{
	  	  dcout<<"output(info,\"%s\","<<toks[i]<<"(tmp+"<<off[toks_in_binary[i]].second<<"));\n";
	  	}
	    }
	  dcout<<"return "<<rbinary.length()/8<<";\n";
	  dcout<<"}\n";
	  // if(n=="tctcore_0")
	  //   {
	  //     cout<<code<<endl;
	  //     yout<<offi<<' '<<off.size()<<' '<<seg<<endl;
	  //     FR(i,off)
	  // 	yout<<i->first<<' '<<i->second<<endl;
	  //   }
	  yout<<"int i;\ni^=i;\n";
	  vector<bfd_info> instr_bfd_info;
	  FR(i,off)
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
	  yout<<"$$=tmp;";
	  yout<<"}"<<endl;
	  yout<<";"<<endl;
	  //gether bfd_info for bfd
	  FR(i,instr_bfd_info)
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
    }
  dhout<<"#define MAX_BINARY_LEN "<<max_binary_len<<endl;
  dhout<<"int dis(struct disassemble_info *,char *c);\n";
  dcout<<"int dis(struct disassemble_info *info,char * c)\n{";
  vector<int> tmp;
  FR(i,binary_func)
    tmp.push_back(i-binary_func.begin());
  dfs_gen(dcout,binary_func,tmp,0);
  dcout<<"}\n";
  ofstream tout("tc-dummy2");
  tout<<"static bfd_reloc_code_real_type offset_reloc["<<max_reloc_num<<"];\n";
  tout<<"static expressionS expr_list["<<max_reloc_num<<"];\n";
  tout<<"int offset_cnt;"<<endl;
  tout<<"char * yyret;"<<endl;
  tout<<"void md_assemble (char *str)\n";
  tout<<"{\n";
  tout<<"YY_BUFFER_STATE bs=dummy__scan_string(str);\n";
  tout<<"offset_cnt=0;\n";
  tout<<"dummy_parse();\n";
  tout<<"dummy__delete_buffer(bs);\n";
  tout<<"int len;\n";
  tout<<"for(len=0;yyret[len];++len);\nlen/=8;\n";
  tout<<"int i;\n";
  tout<<"char * f=frag_more(len);\n";      //TODO should be a variable
  tout<<"for(i=0;i<offset_cnt;++i)\n";
  tout<<"{\n";
  tout<<"fixS * tmp=fix_new_exp(/*frag_now*/NULL,/*f-frag_now->fr_literal*/0,len,expr_list+i,TRUE,offset_reloc[i]);\n";
  tout<<"tmp->fx_frag=frag_now;\n";
  tout<<"tmp->fx_where=f-frag_now->fr_literal;\n";
  tout<<"}\n";
  tout<<"int j,k;\n";
  tout<<"for(j=0;j<len;++j)\n";
  tout<<"{f[j]=0;\n";
  tout<<"for(k=0;k<8;++k)\n";
  tout<<"f[j]=(f[j]<<1)|('1'==yyret[(len-1-j)*8+k]?1:0);\n";
  tout<<"}\n";
  tout<<"clear(&strsta);\n";
  tout<<"}\n";
  tout<<"void md_apply_fix(fixS * fixP, valueT * valP, segT seg ATTRIBUTE_UNUSED)\n";
  tout<<"{\n";
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
  FR(i,bfd_list)
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
      tout<<"v=(v<<8)|buf["<<bytes-1<<"-i];\n";
      tout<<"k=value&((1LL<<"<<l<<")-1);\n";
      tout<<"k>>="<<rs<<';'<<endl;
      tout<<"c=((1LL<<"<<l<<")-1)<<"<<o<<";\n";
      tout<<"v=(v&(~c))|(k<<"<<o<<");\n";
      tout<<"for(i=0;i<"<<bytes<<";++i,v>>=8)\n";
      tout<<"buf[i]=v&((1<<8)-1);\n";
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
  FR(i,bfd_list)
    {
      if(i!=bfd_list.begin())
	bout<<",\n";
      bout<<"HOWTO ("<<i->name<<",	/* type */\n";
      bout<<i->right_shift<<",			/* TODO rightshift */\n";//TODO my be variable
      bout<<(i->instr_len>=32?2:1)<<",			/* TODO!! size (0 = byte, 1 = short, 2 = long) */\n";
      bout<<i->instr_len<<",			/* bitsize */\n";
      bout<<i->pcrel<<",			/* pc_relative */\n";
      bout<<i->off<<",			/* bitpos */\n";
      bout<<"complain_overflow_signed, /*TODO complain_on_overflow */\n";
      bout<<"mips_generic_reloc,			/* special_function */\n";
      bout<<"\""<<i->name<<"\",		/* name */\n";
      bout<<"TRUE,			/* partial_inplace */\n";
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
  FR(i,bfd_list)
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
      FR(i,bfd_list)
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
      FR(i,bfd_list)
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

      dcout<<"const char *"<<name<<"(char * c)\n{return s2hex(c,"<<len<<");}\n";
      dhout<<"const char *"<<name<<"(char * c);\n";
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

      dcout<<"const char *"<<name<<"(char * c)\n{return s2hex(c,"<<width<<");}\n";
      dhout<<"const char *"<<name<<"(char * c);\n";
    }

  bout.close();
  system("cat ../src/as/coff-dummy1 \
./coff-dummy2 \
../src/as/coff-dummy3 \
 ../src/as/coff-dummy4 > coff-dummy.c; indent ./coff-dummy.c");


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

  // dyout<<"%%"<<endl;
  // dyout.close();
  // dtokout<<"%%"<<endl;
  // dtokout.close();
  // dcout<<"void yyerror(const char *s)\n";
  // dcout<<"{fprintf (stderr, \"L%d: %s \\n\",ddummy_lineno,s);\n";
  // dcout<<"}\n";

  dcout.close();
  dhout<<"\n#endif"<<endl;
  dhout.close();
  cmd=(string)"cat "+(string)"../src/as/dummy-dis1.c"+(string)" "+dh_file_name+" "+"../src/as/dummy-dis2.c"+" "+dc_file_name+(string)" > dummy-dis.c";
  system(cmd.c_str());
  return 0;
}
