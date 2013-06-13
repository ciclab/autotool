#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include "hash.h"
#include <utility>
#include <assert.h>
using std::vector;
using namespace std;
//表示Asem的ivec有效
#define type_is_vector 0

//表示Asem的name有效
//表示没有引号的string，可能是关键词，操作符等
#define type_is_string1 1
//表示有引号的string
#define type_is_string2 2
string reserved[] ={
  "rule",
  "stage","false","true","enum","const","width",
  "size","type","index","read","write","wire","pipe_line",
  "register","like","override","alias","function_unit",
  "instruction","top","select","code","do","binary","switch"};

// 哈希表 hash controller
class hash_control hc;

class Asem{
public:
  vector<Asem> ivec;
  string name;
  int type;
  Asem * find(const string &name);
};

// 查找当前vector中名字是的name那一项
Asem * Asem::find(const string &name)
{
  if(this->type==type_is_vector)
    for(int i=1;i<this->ivec.size();++i)
      if(this->ivec[i].type==type_is_vector &&
	 this->ivec[i].ivec[0].type==type_is_string1 &&
	 name==this->ivec[i].ivec[0].name)
	return &(this->ivec[i]);
}

void gen(Asem &asem){
  char c1;
  while((c1=getchar())!=EOF){
    if(c1==')') return;
    //一个vector开始
    else if(c1=='('){
      Asem asem_1;
      asem_1.type=type_is_vector;
      asem.ivec.push_back(asem_1);
      gen(asem.ivec[asem.ivec.size()-1]);
    }
    //带单引号的string
    else if(c1=='\''){
      Asem asem_2;
      asem_2.type=type_is_string2;
      char c2;
			
      while((c2=getchar())!=EOF&&c2!='\'')
	asem_2.name+=c2;
      asem.ivec.push_back(asem_2);
    }
    //普通string
    else if(c1!=' '&&c1!='\n'){
      Asem asem_3;
      asem_3.type=type_is_string1;
      asem_3.name=c1;
      char c3;

      while((c3=getchar())!=EOF&&c3!=' '&&c3!='\n'&&c3!=')') 
	asem_3.name+=c3;
      asem.ivec.push_back(asem_3);
      if(c3==')')
	return ;
    }
		
  }
}

void display(const Asem &asem,int lev){
  for(int i=0;i<asem.ivec.size();++i){
    if(asem.ivec[i].type==type_is_vector){
      if(i)
	{
	  cout<<endl;
	  for(int j=0;j<lev;++j)
	    cout<<"  ";
	}
      cout<<'(';
      display(asem.ivec[i],lev+1);
      cout<<')';
    }
    else
      {
	if(i && asem.ivec[i-1].type==type_is_vector)
	  {
	    cout<<endl;
	    for(int j=0;j<lev;++j)
	      cout<<"  ";
	  }
	if(asem.ivec[i].type==type_is_string1)
	  cout<<asem.ivec[i].name<<' ';
	else cout<<'\''<<asem.ivec[i].name<<'\''<<' ';
      }
  }
}

// 递归的插入hash表
void dfs_insert_hash(const Asem &asem,string pwd)
{
  // 如果是定义的变量或者是保留词
  pwd+=".";
  if(asem.ivec[0].type==type_is_string1)
    {
      if(asem.ivec[0].name=="=" || 
	 asem.ivec[0].name=="+" ||
	 asem.ivec[0].name=="if" ||
	 asem.ivec[0].name=="[]")
	return ;
      pwd+=asem.ivec[0].name;
      // 不应该有重复定义
      assert(NULL==
	     hc.insert(pwd.c_str(),(int)(&asem)));
      assert(sizeof(int)==sizeof(&asem));
      for(int i=1;i<asem.ivec.size();++i)
	if(asem.ivec[i].type==type_is_vector)
	  dfs_insert_hash(asem.ivec[i],pwd);
    }
  else if(asem.ivec[0].type==type_is_vector)
    {
      for(int i=0;i<asem.ivec.size();++i)
	if(asem.ivec[i].type==type_is_vector)
	  dfs_insert_hash(asem.ivec[i],pwd);
    }
}
// 用于查找已经展开的内容
hash_control hc_unfold;
// 表数据结构 用于保存模拟器 自动生成时展开的内容
class triple
{
public:
  string code;
  string binary;
  string doo;
  vector<int> off_in_code;
  vector<int> off_in_binary;
  triple(string c,string b,string d){code=c,binary=b,doo=d;};
  triple(){};
};
vector<vector<triple> > unfolded_list;

string get_full_name(string name,string pwd)
{
  // 最短可能的全路径
  int minl=name.length()+3;
  name=pwd+"."+name;
  //  找...a.b..c.d时，先找...a.b..c.d
  // 如果没有,则删除c.,找...a..b..d
  // 没有,继续找...a..b.d > ...a..d > ...a.d > ...d
  for(;hc.find(name)==0 && name.length()>=minl;)
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
  if(name.length()<minl)
    return "";
  return name;
}

// string get_val(Asem & asem,string pwd)
// {
//   assert(asem.size()==2);
//   string get_full_name(asem.ivec[1].name,pwd);
// }
bool is_instr(const string &name)
{
  return (hc.find((string)"...instruction."+name)!=0);
}
bool is_type(const string &name)
{
  return (hc.find((string)"...type."+name)!=0);
}
bool is_enum(const string &name)
{
  return (hc.find((string)"...enum."+name)!=0);
}
Asem *get_asem(const string &name)
{
  int tmp=hc.find((string)"...instruction."+name);
  if(tmp==0)
    {
      tmp=hc.find((string)"...type."+name);
      if(tmp==0)
	tmp=hc.find((string)"...enum."+name);
    }
  return (Asem*)tmp;
}
int unfold(Asem &asem);

int unfold_enum(const Asem &asem)
{
  cout<<asem.ivec[0].name<<endl;
  return 0;
}
int unfold_type(const Asem &asem)
{
  cout<<asem.ivec[0].name<<endl;
  return 0;
}
void eval_unfold(vector<string> &var_name,
		 vector<vector<string> >&var_choose_name,
		 vector<vector<int> >&var_val,
		 vector<pair<int,int> > &var_choosed_val,
		 Asem &code,
		 Asem &binary,
		 Asem &doo,
		 vector<triple> &r)
{
  // 记录变量在code中出现的位置，目前认为一个变量在code中只出现一次
  vector<int> var_off_in_code;
  // 记录变量在binary中出现的位置，目前认为一个变量在binary中只出现一次
  vector<int> var_off_in_bin;
  var_off_in_code.resize(var_name.size());
  var_off_in_bin.resize(var_name.size());
  int k=r.size();
  r.resize(k+1);
  // 对code和binary的求值应该可以写成函数
  // 求出code
  assert(code.ivec[0].name==(string)"code");
  for(int i=1;i<code.ivec.size();++i)
    {
      if(code.ivec[i].type==type_is_string2)
	{// 是带引号的string
	  r[k].code+=code.ivec[i].name;
	}
      else if(code.ivec[i].type==type_is_string1)
	{
	  // string1的内容目前只能是临时变量的名字
	  int j=0;
	  // 找到对应的变量在var_list的索引，目前是顺序查找
	  for(;j<var_name.size() && var_name[j]!=code.ivec[i].name;++j)
	    ;
	  var_off_in_code[j]=r[k].code.length();
	  assert(j<var_name.size());
	  r[k].code+=unfolded_list[var_val[j][var_choosed_val[j].first]][var_choosed_val[j].second].code;
	}
      else assert(0);
    }
  // 求出binary
  for(int i=1;i<binary.ivec.size();++i)
    {
      if(binary.ivec[i].type==type_is_string2)
	{
	  r[k].binary+=binary.ivec[i].name;
	}
      else if(binary.ivec[i].type==type_is_string1)
	{
	  int j=0;
	  for(;j<var_name.size() && var_name[j]!=binary.ivec[i].name;++j)
	    ;
	  assert(j<var_name.size());
	  var_off_in_bin[j]=r[k].binary.length();
	  r[k].binary+=unfolded_list[var_val[j][var_choosed_val[j].first]][var_choosed_val[j].second].binary;
	}
      else if(binary.ivec[i].type==type_is_vector)
	{
	  // 目前只可能是switch语句
	  assert(binary.ivec[i].ivec[0].name==(string)"switch");
	  int j=0;
	  for(;j<var_name.size() && var_name[j]!=binary.ivec[i].ivec[1].name;++j)
	    ;
	  assert(j<var_name.size());
	  int k=2;
	  // 遍历switch中每一个选项
	  for(;k<binary.ivec[i].ivec.size() &&
		var_choose_name[j][var_choosed_val[j].first]!=binary.ivec[i].ivec[k].name;k+=2)
	    ;
	  assert(k<binary.ivec[i].ivec.size());
	  // 现在认为switch后面的值只是常量string，以后应该处理其他情况
	  assert(binary.ivec[i].ivec[k+1].type==type_is_string2);
	  r[k].binary+=((binary.ivec[i]).ivec[k+1]).name;
	}
    }
  // 计算新生成的code offset和binary offset 信息
  for(int i=0;i<var_val.size();++i)
    for(int j=0;j<
	  unfolded_list[var_val[i][var_choosed_val[i].first]][var_choosed_val[i].second].off_in_code.size();++j)
      {
	r[k].off_in_code.push_back(unfolded_list[var_val[i][var_choosed_val[i].first]][var_choosed_val[i].second].off_in_code[j]+
				   var_off_in_code[i]);
	r[k].off_in_binary.push_back(unfolded_list[var_val[i][var_choosed_val[i].first]][var_choosed_val[i].second].off_in_binary[j]+
				     var_off_in_bin[i]);
      }
  // 处理do描述
      //for(int i=1;i<
}
void dfs_unfold_instr(vector<string> &var_name,
		      vector<vector<string> > &var_choose_name,
		      vector<vector<int> > &var_val,
		      vector<pair<int,int> > &var_choosed_val,
		      Asem &code,
		      Asem &binary,
		      Asem &doo,
		      int lev,
		      vector<triple> &r)
{
  if(lev>=var_name.size())
    eval_unfold(var_name,var_choose_name,var_val,var_choosed_val,
		code,binary,doo,r);
  else
    for(int i=0;i<var_val[lev].size();++i)
      {
	var_choosed_val[lev].first=i;
	for(int j=0;j<unfolded_list[var_val[lev][i]].size();++j)
	  {
	    var_choosed_val[lev].second=j;
	    dfs_unfold_instr(var_name,var_choose_name,var_val,var_choosed_val,
			     code,binary,doo,lev+1,r);
	  }
      }
}
// 在unfolded_list的第i项里增加一个triple
void new_unfolded_triple(int i,string code,string binary,string doo)
{
  unfolded_list[i].push_back(triple(code,binary,doo));
}
// 返回v的二进制，宽度是w
string num2string(int v,int w)
{
  string r;
  for(int i=1;i<w;i<<=1)
    {
      if(i&v)
	r=(string)"1"+r;
      else r=(string)"0"+r;
    }
  return r;
}
// 对enum类型描述展开
// 类似(enum_name ('aaa' 'xxx') ...)
// 枚举类型每一项可以是二元组，表示名字和对应的code，binary根据
// 它的位置决定
int unfold_enum(Asem &asem)
{
  int k=unfolded_list.size();
  unfolded_list.resize(k+1);
  for(int i=1;i<asem.ivec.size();++i)
    {
      if(asem.ivec[i].type==type_is_vector)
	{
	  // 如果是ivec那么只有两个元素
	  assert(asem.ivec[i].ivec.size()==2 && 
		 asem.ivec[i].ivec[0].type==type_is_vector && 
		 asem.ivec[i].ivec[1].type==type_is_vector);
	  new_unfolded_triple(k,asem.ivec[i].ivec[1].name,num2string(i-1,asem.ivec.size()-1),(string)"");
	}
    }
}
// 把string转成int
int string2num(string s)
{
  int v(0);
  // 没考虑溢出情况
  for(int i=0;i<s.length();++i)
    v=(int)(s[i]-'0')+v*10;
  return v;
}
// 处理type描述
// (name (width num) (flag xxx) )
int unfold_type(Asem &asem)
{
  assert(asem.ivec.size()==3);
  Asem & tmpw=*asem.find("width");
  assert(tmpw.ivec.size()==2 && tmpw.ivec[1].type==type_is_string1);
  int width=string2num(tmpw.ivec[1].name);
  Asem & tmpf=*asem.find("flag");
  assert(tmpf.ivec.size()==2 && tmpf.ivec[1].type==type_is_string1);
  int k=unfolded_list.size();
  unfolded_list.resize(k+1);
  string binary;
  for(int i=0;i<width;++i)
    binary+=(string)"-";
  new_unfolded_triple(k,(string)"type_"+asem.ivec[0].name+(string)"_"+
		     tmpw.ivec[1].name+(string)"_"+tmpf.ivec[1].name,
		     binary,(string)"");
}
// 对instruction展开
int unfold_instr(Asem &asem)
{
  // 变量名
  vector<string> var_name;
  // 变量可选的值
  vector<vector<string> >var_choose_name;
  // 变量选不同值对应的索引
  vector<vector<int> > var_val;

  // 找到所有变量定义 这里认为是这个样子的：（= a b c ...）
  // 且假设变量定义很简单 没有嵌套 递归
  // 所有变量定义在最外面一层
  for(int i=1;i<asem.ivec.size();++i)
    if(asem.ivec[i].ivec[0].name==(string)"=")
      {// 这一项是变量定义
	int k=var_name.size();
	var_name.resize(k+1);
	var_choose_name.resize(k+1);
	// 保存变量名a
	var_name[k]=asem.ivec[i].ivec[1].name;
	// j从2开始 第一个可选的值
	for(int j=2;j<asem.ivec[i].ivec.size();++j)
	  {
	    const string &name=asem.ivec[i].ivec[j].name;
	    // 保存可选的值的名字
	    var_choose_name[k].push_back(name);
	    // 如果变量对应的是一个instruction 或者是type或者是枚举 递归地展开先
	    if(is_instr(name) || is_type(name) || is_enum(name))
	      {
		int val=unfold(*get_asem(name));
		// 保存展开的索引
		var_val[k].push_back(val);
	      }
	    else
	      {// 不然报错
		assert(0);
	      }
	  }
      }

  // 保存待展开instruction项的binary,code,do
  Asem & code=*asem.find("code");
  Asem & binary=*asem.find("binary");
  Asem & doo=*asem.find("do");

  assert((&code!=0) && (&binary!=0) && (&doo!=0));
  int k=unfolded_list.size();
  unfolded_list.resize(k+1);
  vector<pair<int,int> > var_choosed_val;
  dfs_unfold_instr(var_name,var_choose_name,var_val,var_choosed_val,
		   code,binary,doo,0,unfolded_list[k]);
}

// 展开一个描述，包括枚举，指令，类型
int unfold(Asem &asem)
{
  string & name=asem.ivec[0].name;
  cout<<'!'<<name<<endl;
  // 如果已经展开过
  if(hc_unfold.find(name)!=0)
    return hc_unfold.find(name)-1; // 由于加入hash表的时候加过1

  int r;
  // 对不同的类型分别展开
  if(is_instr(name))
    r=unfold_instr(asem);
  else if(is_enum(name))
    r=unfold_enum(asem);
  else if(is_type(name))
    r=unfold_type(asem);
  else assert(0);

  // 加入hash表，由于r可能是0，而hash.find返回0表示没有找到
  hc_unfold.insert(name,r+1);

  return r;
}

int main(){
  freopen("in.txt","r",stdin);
  Asem asem;
  asem.type=type_is_vector;
  gen(asem);
  //display(asem,0);

  // 保留字
  for(int i=0;i<sizeof(reserved)/sizeof(reserved[0]);++i)
    hc.insert(reserved[i].c_str(),(int)(void*)reserved);
  
  // 插入hash表
  
  dfs_insert_hash(asem,"");

  // instruction里必须有顶层规则
  string instr="...instruction.top";
  assert(hc.find(instr)!=0);
  Asem &rule=*(Asem*)hc.find(instr);
  assert(rule.type==type_is_vector && 
	 rule.ivec.size()==2
	 && rule.ivec[1].type==type_is_string1);

  // 得到顶层规则名
  instr="...instruction."+rule.ivec[1].name;
  assert(hc.find(instr)!=0);
  rule=*(Asem*)hc.find(instr);
  
  unfold(rule);

  return 0;
}
