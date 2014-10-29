#include "asem.h"
#include <cstdlib>
#include "def.h"
#include <unordered_map>
#include "do_content.h"
using namespace std;

hash_control hc_unfold_read;
vector<vector<triple > > unfolded_list_read;
vector<instr_type> u_l_t;
vector<string> unfolded_list_name_read;// name of rule of corresponding unfolded_list
class hash_control hc_read;
vector<Asem> do_content_read;

class hash_control & Asem::hc_unfold=hc_unfold_read;
vector<Asem> & Asem::do_content = do_content_read;
vector<vector<triple > > & Asem::unfolded_list=unfolded_list_read;
vector<instr_type> &Asem::unfolded_list_type=u_l_t;
vector<string> & Asem::unfolded_list_name=unfolded_list_name_read;// name of rule of corresponding unfolded_list
class hash_control & Asem::hc=hc_read;


//#define DOT_Y
// 返回v的二进制，宽度能表示w项（从0开始）
// static string num2string(int v,int w)
// {
//   string r;
//   for(int i=1;i<w;i<<=1)
//     {
//       if(i&v)
// 	r=(string)"1"+r;
//       else r=(string)"0"+r;
//     }
//   return r;
// }

// v should be positive
bool isNumber(const string s)
{
  FRA(i,s)
    if(*i<'0' || *i>'9')
      return false;
  return true;
}

static string int2string(int v)
{
  char tmp[330];
  assert(v<(int)(sizeof(tmp)/sizeof(tmp[0])));
  sprintf(tmp,"%d",v);
  return (string)tmp;
}
// 把string转成int
static int string2num(string s)
{
  int v(0);
  // 没考虑溢出情况
  for(int i=0;i<(int)s.length();++i)
    v=(int)(s[i]-'0')+v*10;
  return v;
}

// 查找当前vector中名字是的name那一项
Asem * Asem::find(const string &name)
{
  if(this->type==type_is_vector)
    for(int i=0;i<(int)ivec.size();++i)
      if(ivec[i].type==type_is_vector &&
	 ivec[i].ivec[0].type==type_is_string1 &&
	 name==ivec[i].ivec[0].name)
	return &(ivec[i]);
  // cout<<"Cannot find "<<name<<endl;
  // assert(0);
  return NULL;
}

void Asem::display(int lev){
  for(int i=0;i<(int)ivec.size();++i){
    if(ivec[i].type==type_is_vector){
      if(i)
	{
	  cout<<endl;
	  for(int j=0;j<lev;++j)
	    cout<<"  ";
	}
      cout<<'(';
      ivec[i].display(lev+1);
      cout<<')';
    }
    else
      {
	if(i && ivec[i-1].type==type_is_vector)
	  {
	    cout<<endl;
	    for(int j=0;j<lev;++j)
	      cout<<"  ";
	  }
	if(ivec[i].type==type_is_string1)
	  cout<<ivec[i].name<<' ';
	else cout<<'\''<<ivec[i].name<<'\''<<' ';
      }
  }
}
static void toDownCase( string & s )
{
  for( auto &i : s )
    if( i <= 'Z' && i >= 'A' )
      i += ( 'z' - 'Z' );
}
void Asem::gen(FILE * & input){
  int c1;
  while((c1=fgetc(input))!=EOF){
    if(c1==')') return;
    //一个vector开始
    else if(c1=='('){
      Asem asem_1;
      asem_1.type=type_is_vector;
      ivec.push_back(asem_1);
      ivec[ivec.size()-1].gen(input);
    }
    //带单引号的string
    else if(c1=='\''){
      Asem asem_2;
      asem_2.type=type_is_string2;
      int c2;
      while((c2=fgetc(input))!=EOF && c2!='\'')
	asem_2.name+=c2;
      // ruoYuan said that it is more convenient to ignore the case
      #ifdef IGNORE_CASE
      toDownCase(asem_2.name);
      #endif
      ivec.push_back(asem_2);
    }
    //普通string
    else if(isgraph(c1)){
      Asem asem_3;
      asem_3.type=type_is_string1;
      asem_3.name=c1;
      int c3;
      while((c3=fgetc(input))!=EOF && (c3==(int)']' || isalnum(c3) || c3=='_' || c3=='[' || c3=='.' || c3 == '<' 
				       || c3 == '>' || c3 == '=' 
				    /*TODO 这里应该也用isgraph,但是会出现奇怪的效果，暂时列举]*/))
	asem_3.name+=c3;
      ivec.push_back(asem_3);
      if(c3==')' || c3==EOF)
	return ;
    }
  }
}

// unfold a description, including enum, instruction, type and addr
// 展开一个描述，包括枚举，指令，类型
int Asem::unfold(ofstream &yout,ofstream & dot_c_out,ofstream & dot_h_out)
{
  string & name=ivec[0].name;
  // 如果已经展开过
  // if done
  if(hc_unfold.find(name)!=0)
    {
      return (long long)hc_unfold.find(name)-1; // 由于加入hash表的时候加过1
    }

#if ASEM_COUT==1
  cout<<"unfolding:"<<name<<endl;
#endif
  int r;
  // 对不同的类型分别展开
  if(is_instr(name))
    r=unfold_instr(yout,dot_c_out,dot_h_out);
  else if(is_enum(name))
    r=unfold_enum(yout,dot_c_out);
  else if(is_type(name))
    r=unfold_type(yout,dot_c_out);
  else if(is_addr(name))
    r=unfold_addr(yout,dot_c_out);
  else assert(0);
  if((int)unfolded_list_name.size()<=r)
    unfolded_list_name.resize(r+1);
  unfolded_list_name[r]=name;
#if ASEM_COUT==1
  cout<<"done:"<<name<<endl;
#endif
  // 加入hash表，由于r可能是0，而hash.find返回0表示没有找到
  hc_unfold.insert(name,(void*)(r+1));
  return r;
}

void Asem::dfs_unfold_instr(const string &rule_name,
			    vector<string> &var_name, // 变量名字
			    vector<string> &var_uni_name, // 为变量取的唯一的名字，用来替换do里的变量
			    vector<vector<string> > &var_choose_name, // 变量可选的值的名字
			    vector<vector<int> > &var_val,		// 变量可选值对应unfolded_list的索引
			    vector<pair<int,int> > &var_choosed_val,	// 变量取值的情况
			    Asem &code,				// 待展开的code对应asem
			    Asem &binary,				// 待展开的binary对应asem
			    // Asem *doo,				// 待展开do对应的asem
			    int lev,					// 当前枚举到第lev个变量
			    vector<triple> &r,			// 保存展开结果
			    int do_seq)
{
  if(lev>=(int)var_name.size())
    {
      eval_unfold(rule_name,var_name,var_uni_name, var_choose_name,var_val,var_choosed_val,
		  code,binary,// doo,
		  r, do_seq);
    }
  else
    for(int i=0;i<(int)var_val[lev].size();++i)
      {
	// 第lev个变量选择第i个值
	var_choosed_val[lev].first=i;
	for(int j=0;j<(int)unfolded_list[var_val[lev][i]].size();++j)
	  {
	    // 第i个值中第j个展开项
	    var_choosed_val[lev].second=j;
	    dfs_unfold_instr(rule_name,var_name, var_uni_name,var_choose_name,var_val,var_choosed_val,
			     code,binary,// doo,
			     lev+1,r, do_seq);
	  }
      }
}

// 每个变量已经定好取值后计算code，binary，do并保存到r中
void Asem::eval_unfold(const string &rule_name,
		       vector<string> &var_name,
		       vector<string> &var_uni_name, 
		       vector<vector<string> >&var_choose_name,
		       vector<vector<int> >&var_val,
		       vector<pair<int,int> > &var_choosed_val,
		       Asem &code,
		       Asem &binary,
		       // Asem *doo,
		       vector<triple> &r,
		       int do_seq
		       )
{
  // 记录变量在code中出现的位置，目前认为一个变量在code中只出现一次
  vector<int> var_off_in_code;
  // 记录变量在binary中出现的位置，目前认为一个变量在binary中只出现一次
  vector<int> var_off_in_bin;
  vector<int> var_reloc_info;
  var_off_in_code.resize(var_name.size());
  var_off_in_bin.resize(var_name.size());

  // r中新增一项保留结果
  int k=r.size();
  r.resize(k+1);
  r[k].rulename=rule_name+"_"+int2string(k);
  // store name of argments and their values
  string type;
  for(int i=0;i<(int)var_name.size();++i)
    {
      r[k].arg_list.push_back(make_pair(var_name[i],var_choose_name[i][var_choosed_val[i].first]+"_"+int2string(var_choosed_val[i].second)));
      string t=unfolded_list[var_val[i][var_choosed_val[i].first]][var_choosed_val[i].second].type;
      if(type.size())
	{
	  assert(type==t || t!="e_pack");
	}
      else type=t;
    }
  if(type != "e_pack")
    r[k].type = "e_notpack";
  else r[k].type = "e_pack";

  if(type == "e_pack")
    {
      assert(var_name.size()==1);
      triple & t = unfolded_list[var_val[0][var_choosed_val[0].first]][var_choosed_val[0].second];
      r[k].code = t.code;
      r[k].arg_list = t.arg_list;
      r[k].do_list.push_back( do_seq );
    }
  
  // 对code和binary的求值应该可以写成函数
  // 求出code
  assert(code.ivec[0].name==(string)"code");
  for(int i=1;i<(int)code.ivec.size();++i)
    {
      if(code.ivec[i].type==type_is_string2)
	{// 是带引号的string
	  if(code.ivec[i].name.length() && code.ivec[i].name[0]!=c_sep)
	    r[k].code=r[k].code+c_sep+code.ivec[i].name;
	  else
	    r[k].code+=code.ivec[i].name;
	}
      else if(code.ivec[i].type==type_is_string1)
	{
	  // string1的内容目前只能是临时变量的名字
	  int j=0;
	  // 找到对应的变量在var_list的索引，目前是顺序查找
	  for(;j<(int)var_name.size() && var_name[j]!=code.ivec[i].name;++j)
	    ;
	  assert(j<(int)var_name.size());
	  string tmp=unfolded_list[var_val[j][var_choosed_val[j].first]][var_choosed_val[j].second].code;
	  // 记录找到的变量在code中的偏移
	  if(tmp.length() && tmp[0]!=c_sep)
	    {
	      var_off_in_code[j]=r[k].code.length();
	      r[k].code=r[k].code+s_sep+tmp;
	    }
	  else
	    {
	      var_off_in_code[j]=r[k].code.length();
	      r[k].code+=tmp;
	    }
	}
      else assert(0);
    }
  // 求出binary
  for(int i=1;i<(int)binary.ivec.size();++i)
    {
      if(binary.ivec[i].type==type_is_string2)
	{
	  r[k].binary+=binary.ivec[i].name;
	}
      else if(binary.ivec[i].type==type_is_string1)
	{
	  int j=0;
	  for(;j<(int)var_name.size() && var_name[j]!=binary.ivec[i].name;++j)
	    ;
	  assert(j<(int)var_name.size());

	  var_off_in_bin[j]=r[k].binary.length();
	  r[k].binary+=unfolded_list[var_val[j][var_choosed_val[j].first]][var_choosed_val[j].second].binary;
	}
      else if(binary.ivec[i].type==type_is_vector)
	{
	  // 目前只可能是switch语句
	  assert(binary.ivec[i].ivec[0].name==(string)"switch");
	  // 暂时不支持
	  assert(0);
	  // 找到switch中指定的变量在var_name中的序号
	  int j=0;
	  for(;j<(int)var_name.size() && var_name[j]!=binary.ivec[i].ivec[1].name;++j)
	    ;
	  assert(j<(int)var_name.size());

	  int z=2;
	  // 遍历switch中每一个选项，找到当前匹配的那一项
	  for(;z<(int)binary.ivec[i].ivec.size() &&
		var_choose_name[j][var_choosed_val[j].first]!=binary.ivec[i].ivec[z].name;z+=2)
	    assert(binary.ivec[i].ivec[z].type==type_is_string1);
	  assert(z+1<(int)binary.ivec[i].ivec.size());

	  // 现在认为switch后面的值只是常量string，以后应该处理其他情况
	  assert(binary.ivec[i].ivec[z+1].type==type_is_string2);
	  r[k].binary+=binary.ivec[i].ivec[z+1].name;
	}
    }
  // 计算新生成的code offset和binary offset 信息
  // 还有do的信息, and adjust variable name
  r[k].do_list.push_back( do_seq );
  for(int i=0;i<(int)var_val.size();++i)
    {
      int a=var_val[i][var_choosed_val[i].first];
      int b=var_choosed_val[i].second;
      int oc=var_off_in_code[i];
      int ob=var_off_in_bin[i];
      r[k].do_list.insert( r[k].do_list.end(), unfolded_list[a][b].do_list.begin(), unfolded_list[a][b].do_list.end() );
      for(int j=0;j<(int)unfolded_list[a][b].off_in_code.size();++j)
	{
	  r[k].off_in_code.push_back(unfolded_list[a][b].off_in_code[j]+oc);
	  r[k].off_in_binary.push_back(unfolded_list[a][b].off_in_binary[j]+ob);
	  r[k].var_len.push_back( unfolded_list[a][b].var_len[j] );
	  if( unfolded_list[a][b].var_name.size() != unfolded_list[a][b].off_in_code.size() )
	    {
	      // we can judge var[i] is a enum or type, but not a rule
	      // in this case, size of var_name should be zero
	      assert( unfolded_list[a][b].var_name.size() == 0 &&
		       unfolded_list[a][b].off_in_code.size() == 1 );
	      r[k].var_name.push_back( var_uni_name[i] );
	    }
	  else
	    r[k].var_name.push_back( unfolded_list[a][b].var_name[j] );
	  r[k].reloc_info.push_back(unfolded_list[a][b].reloc_info[j]);
	  if(unfolded_list[a][b].enum_name[j].length()>0)
	    r[k].enum_name.push_back(var_name[i]+(string)"#"+unfolded_list[a][b].enum_name[j]);
	  else r[k].enum_name.push_back((string)"");
	}
    }
  // 处理do描述
  // 要做的包括
  // 代换do表述中变量的do
  // if(doo)
  //   {
      // copy content in do  description
      // (*doo).dfs_copy_content(r[k].doo);
      // if((*doo).ivec.size()>2)
      // 	cout<<k<<' '<<(*doo).ivec[1].ivec.size()<<' '<<r[k].doo.ivec[1].ivec.size()<<endl;
      // 对可能出现的switch中的变量进行代换
      // (*doo).switch_chg(var_name,
      // 		 var_choose_name,
      // 		 var_val,
      // 		 var_choosed_val);
      // TODO 对if语句中的变量进行代换
      //for(int i=0;i<var_name.size();++i)
      //cout<<var_choosed_val[i].first<<' '<<var_choosed_val[i].second<<endl;
      // for(vector<Asem>::iterator ite=(*doo).ivec.begin()+1;ite!=(*doo).ivec.end();++ite)
      // 	{
      // 	  if(ite->type==type_is_string1)
      // 	    {
      // 	      //应该是变量
      // 	      int i=0;
      // 	      for(;i<var_name.size();++i)
      // 		if(var_name[i]==ite->name)
      // 		  break;
      // 	      //把那个变量对应doo压入
      // 	      vector<int> &tmp=unfolded_list[var_val[i][var_choosed_val[i].first]][var_choosed_val[i].second].doo;
      // 	      for(int j=0;j<tmp.size();++j)
      // 		r[k].doo.push_back(tmp[j]);
      // 	    }
      // 	  else if(ite->type==type_is_vector)
      // 	    {
      // 	      // TODO 加入的do可能有重复，可以用hash优化
      // 	      r[k].doo.push_back(do_list.size());
      // 	      do_list.push_back(&(*ite));
      // 	    }
      // 	  else assert(0);

      //r[k].doo.push_back(analyze_do_expr((*doo).ivec[i]));
      // }
    // }

  //   for(int i=0;i<var_val.size();++i)
  //     {
  //       int a=var_val[i][var_choosed_val[i].first];
  //       int b=var_choosed_val[i].second;
  //       for(int j=0;j<unfolded_list[a][b].doo.size();++j)
  // 	r[k].doo.push_back(unfolded_list[a][b].doo[j]);
  //     }
}

// 对enum类型描述展开
// 类似(enum_name ('aaa' 'xxx') ...)
// 枚举类型每一项可以是二元组，表示名字和对应的code，binary根据
// 它的位置决定
int Asem::unfold_enum(ofstream &yout,ofstream & dot_c_out)
{
  // 新增一项
  int k=unfolded_list.size();
  unfolded_list.resize(k+1);

  //发现如果展开所有的enum结果可能很大，所以改成不对enum展开到
#define ENUM_NOT_UNFOLDED 1

#ifdef ENUM_NOT_UNFOLDED
  //cout<<"enum_"<<ivec[0].name<<":"<<endl;
  int cnt=0,m=0;
  for(int i=1;i<(int)ivec.size();++i)
    {
      if(ivec[i].is_string())
	{
	}
      else if(isNumber(ivec[i].ivec[1].name))
	{
	  cnt=string2num(ivec[i].ivec[1].name);
	}
      else if(ivec[i].ivec.size()==3 && isNumber(ivec[i].ivec[2].name))
	{
	  cnt=string2num(ivec[i].ivec[2].name);
	}
      if(m<cnt)
	m=cnt;
      ++cnt;
    }
  string binary;
  for(long long i=1;i<=m;i<<=1)
    binary+="-";
  //cout<<(ivec.size()-1)<<' '<<binary<<endl;
  unfolded_list[k].push_back(triple(ivec[0].name,s_enum_beg+ivec[0].name,binary,"e_enum"));
  unfolded_list[k][0].reloc_info.push_back(0);
  unfolded_list[k][0].off_in_code.push_back(0);
  unfolded_list[k][0].off_in_binary.push_back(0);
  unfolded_list[k][0].enum_name.push_back(ivec[0].name);
  unfolded_list[k][0].var_len.push_back( (int)binary.length() );
#endif
  for(int i=0;i<(int)ivec.size();++i)
    {
      if(ivec[i].type==type_is_vector)
	{
#ifndef ENUM_NOT_UNFOLDED
	  // 如果是ivec那么只有两个元素,且都是有引号的string
	  assert(ivec[i].ivec.size()==2 && 
		 ivec[i].ivec[0].type==type_is_string2 && 
		 ivec[i].ivec[1].type==type_is_string2);
	  
	  unfolded_list[k].push_back(triple((string)"#ENUM_"+
					    ivec[i].ivec[1].name,num2string(i-1,ivec.size()-1)));
	  cout<<"!!"<<ivec[1].name<<endl;
#else
	  // TODO 产生这个枚举相应的lex规则和处理函数
#endif
	}
      else
	{
#ifndef ENUM_NOT_UNFOLDED
	  assert(ivec[i].type==type_is_string2);
	  unfolded_list[k].push_back(triple((string)"#ENUM_"+
					    ivec[i].name,num2string(i-1,ivec.size()-1)));
#endif
	  // TODO 产生这个枚举相应的lex规则和处理函数
	}
    }
  
  return k;
}

// 处理type描述
// (name (width num) (flag xxx) )
// 生成的code是"name_width_xxx"
// 生成的binary是"-..."(共width个"-")
int Asem::unfold_type(ofstream &yout,ofstream & dot_c_out)
{
  // type定义有3个部分
  assert(ivec.size()==3);

  Asem & tmpw=*find("width");
  assert(tmpw.ivec.size()==2 && tmpw.ivec[1].type==type_is_string1);
  int width=string2num(tmpw.ivec[1].name);

  Asem & tmpf=*find("flag");
  assert(tmpf.ivec.size()==2 && tmpf.ivec[1].type==type_is_string1);

  int k=unfolded_list.size();
  unfolded_list.resize(k+1);

  string binary;
  for(int i=0;i<width;++i)
    binary+=(string)"-";
  unfolded_list[k].push_back(triple(ivec[0].name,
				    s_type_beg+"type_"+ivec[0].name+
				    "_"+tmpw.ivec[1].name+
				    "_"+tmpf.ivec[1].name,
				    binary,"e_type"));
  unfolded_list[k][0].reloc_info.push_back(0);
  unfolded_list[k][0].off_in_code.push_back(0);
  unfolded_list[k][0].off_in_binary.push_back(0);
  unfolded_list[k][0].enum_name.push_back((string)"");
  unfolded_list[k][0].var_len.push_back( width );
  return k;
}
// process addr description
// (name (width num) (pcrel TRUE/FALSE) (right_shift num) )
// generate corresponding code: name_width_TRUE/FALSE_num
// generate corresponding binary: '----...'
int Asem::unfold_addr(ofstream &yout,ofstream & dot_c_out)
{
  // 4 fileds
  assert(ivec.size()==4);

  Asem & tmp_w=*find("width");
  assert(tmp_w.ivec.size()==2 && tmp_w.ivec[1].type==type_is_string1);
  int width=string2num(tmp_w.ivec[1].name);

  Asem & tmp_pcrel=*find("pcrel");
  assert(tmp_pcrel.ivec.size()==2 && tmp_pcrel.ivec[1].type==type_is_string1);
  bool pcrel=tmp_pcrel.ivec[1].name=="TRUE";

  Asem & tmp_rs=*find("right_shift");
  assert(tmp_rs.ivec.size()==2 && tmp_pcrel.ivec[1].type==type_is_string1);
  int right_shift=string2num(tmp_rs.ivec[1].name);
  int k=unfolded_list.size();
  unfolded_list.resize(k+1);

  string binary;
  for(int i=0;i<width;++i)
    binary+=(string)"-";
  unfolded_list[k].push_back(triple(ivec[0].name,
				    s_addr_beg+"addr_"+ivec[0].name+
				    "_"+(pcrel?"true":"false")+
				    "_"+tmp_w.ivec[1].name+/*TODO sequence of name corresponds to code of info extract in asGen.cpp*/
				    "_"+tmp_rs.ivec[1].name,
				    binary,"e_addr"));
  unfolded_list[k][0].reloc_info.push_back((right_shift<<1)|(pcrel?1:0));
  unfolded_list[k][0].off_in_code.push_back(0);
  unfolded_list[k][0].off_in_binary.push_back(0);
  unfolded_list[k][0].enum_name.push_back((string)"");
  unfolded_list[k][0].var_len.push_back( width );
  return k;
}
void dfs_replace( Asem *a, unordered_map<string,string> &tab)
{
  if( a )
    {
      for( int i = 0; i < (int)a->ivec.size(); ++i )
	{
	  if( a->ivec[i].is_vec() )
	    {
	      dfs_replace( &(a->ivec[i]), tab);
	    }
	  else if( a->ivec[i].type == type_is_string1 )
	    {
	      if( tab.find( a->ivec[i].name ) != tab.end() )
		{
		  a->ivec[i].name = tab[ a->ivec[i].name ];
		}
	    }
	  // else cout << a->ivec[i].type << endl;
	}
    }
}
void replace_name( Asem * a, vector<string> &from, vector<string> &to)
{
  unordered_map<string,string> tab;
  assert( from.size() == to.size() );
  for( int i = 0; i < (int)from.size(); ++i )
    tab[ from[i] ] = to[i];
  dfs_replace(a, tab);
}
// 对instruction展开
int Asem::unfold_instr(ofstream & yout,ofstream & dot_c_out,ofstream & dot_h_out)
{
  // 变量名
  vector<string> var_name;
  // 变量可选的值(可能是其它instruction或者是type或者是enum)
  vector<vector<string> >var_choose_name;
  // 变量选不同值对应的在unfolded_list中的索引
  vector<vector<int> > var_val;

  // 找到所有变量定义 这里认为是这个样子的：
  // （= a b c ...）
  // 表示a可以是b或c或...
  // 假设变量定义很简单,没有嵌套和递归
  // 所有变量定义在当前instruction描述的最外面一层
  string rule_name=ivec[0].name;
#ifdef DOT_Y
  vector<string> var_list;
#endif
  for(int i=1;i<(int)ivec.size();++i)
    if(ivec[i].ivec[0].name==(string)"=")
      {// 这一项是变量定义
	// 这是第k个变量
	int k=var_name.size();
	var_name.resize(k+1);
	var_choose_name.resize(k+1);
	var_val.resize(k+1);

	// 保存变量名a
	var_name[k]=ivec[i].ivec[1].name;
	// j从2开始,是第一个可选的值
	for(int j=2;j<(int)ivec[i].ivec.size();++j)
	  {
	    const string &name=ivec[i].ivec[j].name;
	    // 保存可选的值的名字
	    var_choose_name[k].push_back(name);
	    // 如果变量对应的是一个instruction 或者是type或者是枚举 递归地展开先
	    if(this->is_instr(name) || this->is_type(name) || this->is_enum(name) || this->is_addr(name))
	      {
		//cout<<name<<"!"<<endl;
		Asem * tmp=get_asem(name);
		assert(tmp!=NULL);
		int val=(*tmp).unfold(yout,dot_c_out,dot_h_out);
		// 保存展开的索引
		var_val[k].push_back(val);
	      }
	    else
	      {// 不然报错
		cerr << name << endl;
		assert(0);
	      }
	  }

#ifdef DOT_Y
	yout<<rule_name<<'_'<<ivec[i].ivec[1].name<<':'<<' ';
	// every varibale in rule correspond to a global variable in .y 
	dot_h_out<<"ll "<<rule_name<<"_var_"<<ivec[i].ivec[1].name<<";"<<endl;
	for(int j=2;j<ivec[i].ivec.size();++j)
	  {
	    if(j!=2)
	      yout<<'|';
	    yout<<' '<<ivec[i].ivec[j].name;
	    var_list.push_back(ivec[i].ivec[j].name);
	  }
	yout<<endl;
#endif
      }
#ifdef DOT_Y
  yout<<'{'<<endl;
  yout<<rule_name<<"_func_"<<"do();"<<endl;
  dot_h_out<<"void "<<rule_name<<"_func_"<<"do();"<<endl;
  dot_c_out<<"void "<<rule_name<<"_func_"<<"do()\n{"<<endl;
  (*find("do")).translate_doo(dot_h_out,dot_c_out,var_list,rule_name);
  dot_c_out<<"}"<<endl;
  yout<<"};"<<endl;
#endif  

	// 为所有变量取唯一的名字
  vector<string> var_uni_name;
  for( auto i : var_name)
    {
      string name = rule_name + "_" + i;
      var_uni_name.push_back( name );
    }

  // 在unfolded_list和unfolded_list_type新增加一项
  int k=this->unfolded_list.size();
  unfolded_list.resize(k+1);
  unfolded_list_type.resize(k+1);
  do_content.resize( k + 1 );

  // 保存待展开instruction项的binary,code,do的asem地址
  Asem & code=*(this->find("code"));
  Asem & binary=*(this->find("binary"));
  Asem * doo=this->find("do");
  replace_name( doo, var_name, var_uni_name);
  Asem & pack=*(this->find("pack"));
  if(&code==NULL)
    {
      // may be a instruction description with pack attribute
      if(&pack==NULL)
	{
	  cerr<<"invalid instruction description"<<endl;
	  assert(0);
	}
      unfolded_list_type[k]=e_pack;
    }
  else
    {
      if(!((&binary!=0) && (doo!=NULL)))
	{
	  cerr<<"rule "<<rule_name<<" code/binary/do empty"<<endl;
	  assert(0);
	}
      unfolded_list_type[k]=e_notpack;
    }

  // 保存当前变量取的值，二元组表示：
  // (= a b c)
  // 第一项表示a取b还是c
  // 第二项表示取b或是c中的第几条（b和c已被展开，可能有多条可选项）
  if(unfolded_list_type[k]==e_notpack)
    {
      vector<pair<int,int> > var_choosed_val;
      var_choosed_val.resize(var_name.size());
      // 针对变量取不同值的时候得到展开的code，binary和do
      dfs_unfold_instr(rule_name,var_name,var_uni_name, var_choose_name,var_val,var_choosed_val,
		       code,binary,// doo,
		       0,unfolded_list[k], k);
      do_content[k] = *doo;
    }
  else
    {
      unfolded_list[k].resize(1);
      for(int i=0;i<(int)var_val.size();++i)
	{
	  string candidate_name;
	  for(int j=0;j<(int)var_val[i].size();++j)
	    {
	      vector<triple> & t=unfolded_list[var_val[i][j]];
	      for(int k=0;k<(int)t.size();++k)
		{
		  if(candidate_name.size())
		    candidate_name = candidate_name + s_sep + t[k].rulename;
		  else candidate_name = t[k].rulename;
		}
	    }
	  unfolded_list[k][0].arg_list.
	    push_back(make_pair(ivec[0].name + "_" + var_name[i],candidate_name));
	}
      string code;
      for(int i=1;i<(int)pack.ivec.size();++i)
	{
	  // entries must be variable
	  assert(pack.ivec[i].is_string());
	  if(i==1)
	    code = ivec[0].name + "_" + pack.ivec[i].name;
	  else code = code + s_sep + ivec[0].name + "_" + pack.ivec[i].name;
	}
      unfolded_list[k][0].rulename = ivec[0].name;
      unfolded_list[k][0].code = code;
      unfolded_list[k][0].type = "e_pack";
    }
  return k;
}

bool Asem::is_assign()
{
  // is an assignment statement. such as (= a ...)
  return is_vec() && ivec.size()>2 && ivec[0].is_string() &&
    ivec[0].name=="=";
}
// TODO 代换switch中的变量，目前什么都没做
void Asem::switch_chg(vector<string> &var_name,
		vector<vector<string> >&var_choose_name,
		vector<vector<int> >&var_val,
		vector<pair<int,int> > &var_choosed_val
		)
{
  if(type==type_is_vector)
    {
      if(ivec.size()>0)
	{
	  if(ivec[0].type==type_is_string1 && ivec[0].name==(string)"switch")
	    {
	      // 找到switch语句
	      // TODO 认为如果判断是含有变量名的表达式的话就是最简单的形式: (switch var_name ...)
	      assert(ivec.size()>1 && (ivec.size()%2)==0);
	      if(ivec[1].type==type_is_string1)
		{
		  // 分成这个变量是var.value 和 var两种
		  // 前一种对应变量是一个枚举类型
		  auto pos=ivec[1].name.find(".value");
		  if(pos!=string::npos)
		    {
		      // 第一种情况
		      // 由于现在对enum类型的是不展开，所以在执行时再处理
		      string var=ivec[1].name.substr(0,pos);
		      int i;
		      for(i=0;i<(int)var_name.size();++i)
			if(var_name[i]==var)
			  break;
		      assert(i<(int)var_name.size());
		      ivec[1].name=(string)"ENUM_"+var+(string)"_"+var_choose_name[i][0];
		    }
		  else
		    {
		      // TODO 现在没有对应描述,暂时不写
		    }
		}
	      else assert(false);
	    }
	  else
	    for(int i=0;i<(int)ivec.size();++i)
	      ivec[i].switch_chg(//ivec[i],
			 var_name,
			 var_choose_name,
			 var_val,
			 var_choosed_val);
	}
    }
}

// 递归的插入hash表
void Asem::dfs_insert_hash(string pwd)
{
  // 如果是定义的变量或者是保留词
  pwd+=".";
  if(ivec[0].type==type_is_string1)
    {
      if(ivec[0].name=="=" || 
	 ivec[0].name=="+" ||
	 ivec[0].name=="if" ||
	 ivec[0].name=="[]" ||
	 ivec[0].name=="call")
	return ;
      pwd+=ivec[0].name;
      // 不应该有重复定义
      if(NULL!=hc.insert(pwd,(void*)this))
	{
	  cerr<<pwd<<" redefined"<<endl;
	  assert(0);
	}
      //assert(sizeof(int)==sizeof(&asem));
      for(int i=1;i<(int)ivec.size();++i)
	if(ivec[i].type==type_is_vector)
	  ivec[i].dfs_insert_hash(pwd);
    }
  else if(ivec[0].type==type_is_vector)
    {
      for(int i=0;i<(int)ivec.size();++i)
	if(ivec[i].type==type_is_vector)
	  ivec[i].dfs_insert_hash(pwd);
    }
}

string Asem::get_full_name(string name,string pwd)
{
  // 最短可能的全路径
  int minl=name.length()+3;
  name=pwd+"."+name;
  //  找...a.b..c.d时，先找...a.b..c.d
  // 如果没有,则删除c.,找...a..b..d
  // 没有,继续找...a..b.d > ...a..d > ...a.d > ...d
  for(;hc.find(name)==0 && (int)name.length()>=minl;)
    {
      int l=name.length()-1;
      for(;l>=0 && name[l]!='.';--l)
	;
      int t=l;
      for(--l;l>=0 && name[l]!='.';--l)
	;
      name.erase(l+1,t-l);
    }
  // 出错返回空字符串
  if((int)name.length()<minl)
    return "";
  return name;
}

// string get_val(Asem & asem,string pwd)
// {
//   assert(size()==2);
//   string get_full_name(ivec[1].name,pwd);
// }
bool Asem::is_instr(string name)
{
  return (hc.find((string)"...instruction."+name)!=0);
}
bool Asem::is_type(string name)
{
  return (hc.find((string)"...type."+name)!=0);
}
bool Asem::is_enum(string name)
{
  return (hc.find((string)"...enum."+name)!=0);
}
bool Asem::is_addr(string name)
{
  return (hc.find("...address."+name)!=0);
}
// 返回name对应的那一项asem地址，现在的实现是首先假设是instruction，
// 然后是type最后是enum。对这些可能依次查找
Asem * Asem::get_asem(string name)
{
  void *tmp=hc.find((string)"...instruction."+name);
  if(tmp==NULL)
    {
      tmp=hc.find((string)"...type."+name);
      if(tmp==NULL)
	tmp=hc.find((string)"...enum."+name);
      if(tmp==NULL)
	tmp=hc.find((string)"...address."+name);
    }
  return (Asem*)tmp;
}

// void Asem::dfs_copy_content(do_content &dl)
// {
//   dl.type=type;
//   if(type==type_is_vector)
//     {
//       dl.ivec.resize(ivec.size());
//       for(int i=0;i<(int)ivec.size();++i)
// 	ivec[i].dfs_copy_content(dl.ivec[i]);
//     }
//   else if(type==type_is_string1 || type==type_is_string2)
//     {
//       dl.str=name;
//     }
//   else assert(0);
// }

void Asem::translate_doo(ofstream &dot_h_out,ofstream &dot_c_out,vector<string> &var_list,const string & rule_name)
{
  for(int i=1;i<(int)ivec.size();++i)
    ivec[i].doo_translate_statement(dot_h_out,dot_c_out,rule_name);
}

string Asem::doo_translate_statement(ofstream & dot_h_out,ofstream & dot_c_out,const string & rule_name)
{
  if(doo_is_assignment())
    {
      vector<string> obj;
      for(int i=1;i<(int)ivec.size();++i)
  	obj.push_back(ivec[i].doo_translate_statement(dot_h_out,dot_c_out,rule_name));
      for(int i=1;i<(int)obj.size();++i)
  	doo_output_assignment(dot_c_out,obj[i-1],obj[i]);
      return obj[0];
    }
  else if(is_string())
    {
      string func_name=rule_name+"_"+name;
      doo_output_rule_call(dot_c_out,func_name);
      return func_name;
    }
  else if(doo_is_if())
    {
      doo_output_if_beg(dot_c_out);
      ivec[1].doo_translate_or_and_cond(dot_c_out);
      dot_c_out<<"\n{"<<endl;
      for(int i=2;i<(int)ivec.size();++i)
  	ivec[i].doo_translate_statement(dot_h_out,dot_c_out,rule_name);
      doo_output_if_end(dot_c_out);
      return "";
    }
  return "";
  // else if(doo_is_switch())
  //   {
  //     doo_output_switch_beg(dot_c_out);
  //     ivec[1].doo_translate_or_and_cond(dot_c_out);
  //     dot_c_out<<"{";
  //     for(int i=2;i<ivec.size();++i)
  // 	{
  // 	  dot_c_out<<"case \'"<<ivec[i].get_string()<<"\'";
  // 	  ++i;
  // 	  dot_c_out<<": ";
  // 	  ivec[i].doo_translate_statement(dot_c_out);
  // 	  dot_c_out<<endl;
  // 	}
  //     dot_c_out<<"}"<<endl;
  //     return NULL;
  //   }
  // else if(doo_is_leftshift())
  //   {
  //     string tmpvar=gen_tmp_var();
  //     out<<tmpvar<<"="<<ivec[1].translate_statement(vl)<<"<<"
  // 	 <<ivec[2].translate_statement(vl)<<endl;
  //     return tmpvar;
  //   }
  // else if(doo_is_call())
  //   {
  //     vector<string> tmp;
  //     FEEV(i,1,ivec)
  // 	tmp.push_back(ivec[i].translate_statement(vl));
  //     out<<ivec[0].get_string()<<"(";
  //     FEEV(i,0,tmp)
  // 	{
  // 	  if(i)
  // 	    out<<",";
  // 	  out<<tmp[i];
  // 	}
  //     out<<")";
  //   }
  // else if(doo_is_idx())
  //   {
  //     return ivec[1].translate_statement(vl)+(string)"["+ivec[2].translate_statement(vl)+(string)"]";
  //   }

}
bool Asem::doo_is_if()
{
  return (is_vec() && ivec.size()>0 && ivec[0].is_string() && ivec[0].name=="if");
}

bool Asem::is_string()
{
  return !is_vec();
}
bool Asem::doo_is_assignment()
{
  return (is_vec() && ivec.size()>0 && ivec[0].is_string() && ivec[0].name==(string)"=");
}
bool Asem::doo_is_switch()
{
  return (is_vec() && ivec.size()>2 && ivec[0].is_string() &&
	  ivec[0].get_string()==(string)"switch");
}
bool Asem::doo_is_leftshift()
{
  return (is_vec() && ivec[0].is_string() && 
	  ivec[0].get_string()==(string)"<<");
}
bool Asem::doo_is_idx()
{
  return (is_vec() && ivec.size()>0 && ivec[0].is_string() &&
	  ivec[0].get_string()==(string)"[]");
}
bool Asem::doo_is_call()
{
  return (is_vec() && ivec.size()>0 &&
	  ivec[0].is_string() &&
	  ivec[0].get_string()[0]=='#');
}

bool Asem::is_vec()
{
  return type==type_is_vector;
}
string Asem::get_string()
{
  return name;
}
void Asem::doo_output_assignment(ofstream &dot_c_out,string to,string from)
{
  dot_c_out<<to<<".tmp="<<from<<".val;"<<endl;
}

void Asem::doo_output_rule_call(ofstream &dot_c_out,string s)
{
  dot_c_out<<"(*(void (*))()"<<s<<")();"<<endl;
}
void Asem::doo_output_if_beg(ofstream &dot_c_out)
{
  dot_c_out<<"if";
}
void Asem::doo_output_if_end(ofstream &dot_c_out)
{
  dot_c_out<<"}"<<endl;
}
void Asem::doo_translate_or_and_cond(ofstream &dot_c_out)
{
  dot_c_out<<"(";
  if(is_string())
    {
      dot_c_out<<name;
    }
  else
    {
      string relation;
      if(ivec[0].get_string()=="or")
	relation=" || ";
      else if(ivec[0].get_string()=="and")
	relation=" && ";
      else assert(ivec.size()==1);
      for(int i=0;i<(int)ivec.size();++i)
	{
	  if(i)
	    dot_c_out<<relation;
	  ivec[i].doo_translate_or_and_cond(dot_c_out);
	}
      }
  dot_c_out<<")";
}
void Asem::doo_output_switch_beg(ofstream &dot_c_out)
{
  dot_c_out<<"switch";
}
