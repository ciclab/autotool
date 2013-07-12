#include<iostream>
#include <fstream>
#include<cstdio>
#include<vector>
#include<string>
#include "hash.h"
#include <utility>
#include <assert.h>
#include <ctype.h>
#include "ir/ir.cpp"
#include "ir/wire.h"
#include "ir/instruction.h"
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
    for(int i=0;i<this->ivec.size();++i)
      if(this->ivec[i].type==type_is_vector &&
	 this->ivec[i].ivec[0].type==type_is_string1 &&
	 name==this->ivec[i].ivec[0].name)
	return &(this->ivec[i]);
  cout<<"Cannot find "<<name<<endl;
  assert(0);
  return NULL;
}

void gen(Asem &asem){
  int c1;
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
      int c2;
      while((c2=getchar())!=EOF && c2!='\'')
	asem_2.name+=c2;
      asem.ivec.push_back(asem_2);
    }
    //普通string
    else if(isgraph(c1)){
      Asem asem_3;
      asem_3.type=type_is_string1;
      asem_3.name=c1;
      int c3;
      while((c3=getchar())!=EOF && (c3==(int)']' || isalnum(c3) || c3=='_' || c3=='['
				    /*TODO 这里应该也用isgraph,但是会出现奇怪的效果，暂时列举]*/))
	asem_3.name+=c3;
      asem.ivec.push_back(asem_3);
      if(c3==')' || c3==EOF)
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
void dfs_insert_hash(Asem &asem,string pwd)
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
      assert(NULL==hc.insert(pwd.c_str(),(void*)&asem));
      //assert(sizeof(int)==sizeof(&asem));
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

//用于保存do的数据结构
vector<Asem*> do_list;
// 用于查找已经展开的内容
hash_control hc_unfold;
// 表数据结构 用于保存模拟器 自动生成时展开的内容
class triple
{
public:
  string code;
  string binary;
  vector<int> doo;
  vector<int> off_in_code;
  vector<int> off_in_binary;
  triple(string c,string b){code=c,binary=b;};
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
bool is_instr(string name)
{
  return (hc.find((string)"...instruction."+name)!=0);
}
bool is_type(string name)
{
  return (hc.find((string)"...type."+name)!=0);
}
bool is_enum(string name)
{
  return (hc.find((string)"...enum."+name)!=0);
}
// 返回name对应的那一项asem地址，现在的实现是首先假设是instruction，
// 然后是type最后是enum。对这些可能依次查找
Asem *get_asem(string name)
{
  void *tmp=hc.find((string)"...instruction."+name);
  if(tmp==NULL)
    {
      tmp=hc.find((string)"...type."+name);
      if(tmp==NULL)
	tmp=hc.find((string)"...enum."+name);
    }
  return (Asem*)tmp;
}
int unfold(Asem &asem);

// 分析do中的表达式，
// 假设对变量do的引用只出现在最外层
int analyze_do_expr(Asem expr)
{
  
  if(expr.type==type_is_string1)
    {
      // 因该是一个变量
    }
  else if(expr.type==type_is_vector)
    {
      // 因该是一个表达式
    }
  return 0;
};
// 每个变量已经定好取值后计算code，binary，do并保存到r中
void eval_unfold(vector<string> &var_name,
		 vector<vector<string> >&var_choose_name,
		 vector<vector<int> >&var_val,
		 vector<pair<int,int> > &var_choosed_val,
		 Asem &code,
		 Asem &binary,
		 Asem * doo,
		 vector<triple> &r)
{
  // 记录变量在code中出现的位置，目前认为一个变量在code中只出现一次
  vector<int> var_off_in_code;
  // 记录变量在binary中出现的位置，目前认为一个变量在binary中只出现一次
  vector<int> var_off_in_bin;

  var_off_in_code.resize(var_name.size());
  var_off_in_bin.resize(var_name.size());

  // r中新增一项保留结果
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
	  assert(j<var_name.size());

	  // 记录找到的变量在code中的偏移
	  var_off_in_code[j]=r[k].code.length();
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
	  
	  // 找到switch中指定的变量在var_name中的序号
	  int j=0;
	  for(;j<var_name.size() && var_name[j]!=binary.ivec[i].ivec[1].name;++j)
	    ;
	  assert(j<var_name.size());

	  int z=2;
	  // 遍历switch中每一个选项，找到当前匹配的那一项
	  for(;z<binary.ivec[i].ivec.size() &&
		var_choose_name[j][var_choosed_val[j].first]!=binary.ivec[i].ivec[z].name;z+=2)
	    assert(binary.ivec[i].ivec[z].type==type_is_string1);
	  assert(z+1<binary.ivec[i].ivec.size());

	  // 现在认为switch后面的值只是常量string，以后应该处理其他情况
	  assert(binary.ivec[i].ivec[z+1].type==type_is_string2);
	  r[k].binary+=binary.ivec[i].ivec[z+1].name;
	}
    }
  // 计算新生成的code offset和binary offset 信息
  for(int i=0;i<var_val.size();++i)
    {
      int a=var_val[i][var_choosed_val[i].first];
      int b=var_choosed_val[i].second;
      int oc=var_off_in_code[i];
      int ob=var_off_in_bin[i];
      for(int j=0;j<unfolded_list[a][b].off_in_code.size();++j)
	{
	  r[k].off_in_code.push_back(unfolded_list[a][b].off_in_code[j]+oc);
	  r[k].off_in_binary.push_back(unfolded_list[a][b].off_in_binary[j]+ob);
	}
    }
  // 处理do描述
  // 要做的包括
  // 代换do表述中变量的do
  if(doo)
    {
      for(vector<Asem>::iterator ite=(*doo).ivec.begin()+1;ite!=(*doo).ivec.end();++ite)
	{
	  if(ite->type==type_is_string1)
	    {
	      //应该是变量
	      int i=0;
	      for(;i<var_name.size();++i)
		if(var_name[i]==ite->name)
		  break;
	      //把那个变量对应doo压入
	      vector<int> &tmp=unfolded_list[var_val[i][var_choosed_val[i].first]][var_choosed_val[i].second].doo;
	      for(int j=0;j<tmp.size();++j)
		r[k].doo.push_back(tmp[j]);
	    }
	  else if(ite->type==type_is_vector)
	    {
	      r[k].doo.push_back(do_list.size());
	      do_list.push_back(&(*ite));
	    }
	  else assert(0);

	  //r[k].doo.push_back(analyze_do_expr((*doo).ivec[i]));
	}
    }

//   for(int i=0;i<var_val.size();++i)
//     {
//       int a=var_val[i][var_choosed_val[i].first];
//       int b=var_choosed_val[i].second;
//       for(int j=0;j<unfolded_list[a][b].doo.size();++j)
// 	r[k].doo.push_back(unfolded_list[a][b].doo[j]);
//     }
}
void dfs_unfold_instr(vector<string> &var_name, // 变量名字
		      vector<vector<string> > &var_choose_name, // 变量可选的值的名字
		      vector<vector<int> > &var_val,		// 变量可选值对应unfolded_list的索引
		      vector<pair<int,int> > &var_choosed_val,	// 变量取值的情况
		      Asem &code,				// 待展开的code对应asem
		      Asem &binary,				// 待展开的binary对应asem
		      Asem * doo,				// 待展开do对应的asem
		      int lev,					// 当前枚举到第lev个变量
		      vector<triple> &r)			// 保存展开结果
{
  if(lev>=var_name.size())
    eval_unfold(var_name,var_choose_name,var_val,var_choosed_val,
		code,binary,doo,r);
  else
    for(int i=0;i<var_val[lev].size();++i)
      {
	// 第lev个变量选择第i个值
	var_choosed_val[lev].first=i;
	for(int j=0;j<unfolded_list[var_val[lev][i]].size();++j)
	  {
	    // 第i个值中第j个展开项
	    var_choosed_val[lev].second=j;
	    dfs_unfold_instr(var_name,var_choose_name,var_val,var_choosed_val,
			     code,binary,doo,lev+1,r);
	  }
      }
}

// 返回v的二进制，宽度能表示w项（从0开始）
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
  // 新增一项
  int k=unfolded_list.size();
  unfolded_list.resize(k+1);

  //发现如果展开所有的enum结果可能很大，所以改成不对enum展开到
#define ENUM_NOT_UNFOLDED 1

#ifdef ENUM_NOT_UNFOLDED
  //cout<<"enum_"<<asem.ivec[0].name<<":"<<endl;
  string binary;
  for(int i=0;i<asem.ivec.size()-1;++i)
    binary+="-";
  unfolded_list[k].push_back(triple(asem.ivec[0].name,binary));
  unfolded_list[k][0].off_in_code.push_back(0);
  unfolded_list[k][0].off_in_binary.push_back(0);
#endif
  for(int i=1;i<asem.ivec.size();++i)
    {
      if(asem.ivec[i].type==type_is_vector)
	{
	  // 如果是ivec那么只有两个元素,且都是有引号的string
	  assert(asem.ivec[i].ivec.size()==2 && 
		 asem.ivec[i].ivec[0].type==type_is_string2 && 
		 asem.ivec[i].ivec[1].type==type_is_string2);
	  
#ifndef ENUM_NOT_UNFOLDED
	  unfolded_list[k].push_back(triple(asem.ivec[i].ivec[1].name,num2string(i-1,asem.ivec.size()-1)));
#else
	  // TODO 产生这个枚举相应的lex规则和处理函数
#endif
	}
      else
	{
#ifndef ENUM_NOT_UNFOLDED
	  assert(asem.ivec[i].type==type_is_string2);
	  unfolded_list[k].push_back(triple(asem.ivec[i].name,num2string(i-1,asem.ivec.size()-1)));
#endif
	  // TODO 产生这个枚举相应的lex规则和处理函数
	}
    }
  return k;
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
// 生成的code是"name_width_xxx"
// 生成的binary是"-..."(共width个"-")
int unfold_type(Asem &asem)
{
  // type定义有3个部分
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
  unfolded_list[k].push_back(triple((string)"type_"+asem.ivec[0].name+
				    (string)"_"+tmpw.ivec[1].name+
				    (string)"_"+tmpf.ivec[1].name,
				    binary));
  unfolded_list[k][0].off_in_code.push_back(0);
  unfolded_list[k][0].off_in_binary.push_back(0);
  return k;
}
// 对instruction展开
int unfold_instr(Asem &asem)
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
  for(int i=1;i<asem.ivec.size();++i)
    if(asem.ivec[i].ivec[0].name==(string)"=")
      {// 这一项是变量定义
	// 这是第k个变量
	int k=var_name.size();
	var_name.resize(k+1);
	var_choose_name.resize(k+1);
	var_val.resize(k+1);

	// 保存变量名a
	var_name[k]=asem.ivec[i].ivec[1].name;
	// j从2开始,是第一个可选的值
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

  // 保存待展开instruction项的binary,code,do的asem地址
  Asem & code=*asem.find("code");
  Asem & binary=*asem.find("binary");
  Asem * doo=asem.find("do");
  assert((&code!=0) && (&binary!=0) && (doo!=NULL));

  // 在unfolded_list新增加一项
  int k=unfolded_list.size();
  unfolded_list.resize(k+1);

  // 保存当前变量取的值，二元组表示：
  // (= a b c)
  // 第一项表示a取b还是c
  // 第二项表示取b或是c中的第几条（b和c已被展开，可能有多条可选项）
  vector<pair<int,int> > var_choosed_val;
  var_choosed_val.resize(var_name.size());
  // 针对变量取不同值的时候得到展开的code，binary和do
  dfs_unfold_instr(var_name,var_choose_name,var_val,var_choosed_val,
		   code,binary,doo,0,unfolded_list[k]);
  return k;
}


// 展开一个描述，包括枚举，指令，类型
int unfold(Asem &asem)
{
  string & name=asem.ivec[0].name;

  // 如果已经展开过
  if(hc_unfold.find(name)!=0)
    {
      return (long long)hc_unfold.find(name)-1; // 由于加入hash表的时候加过1
    }

  //cout<<"unfolding:"<<name<<endl;

  int r;
  // 对不同的类型分别展开
  if(is_instr(name))
    r=unfold_instr(asem);
  else if(is_enum(name))
    r=unfold_enum(asem);
  else if(is_type(name))
    r=unfold_type(asem);
  else assert(0);

  //cout<<"done:"<<name<<endl;
  // 加入hash表，由于r可能是0，而hash.find返回0表示没有找到
  hc_unfold.insert(name,(void*)(r+1));
  return r;
}
int string2int(string & s)
{
  int r(0);
  for(int i=0;i<s.length();++i)
    r=r*10+s[i]-'0';
  return r;
}
int main(){
  freopen("in.txt","r",stdin);
  Asem asem;

  asem.type=type_is_vector;
  // 读入文件
  gen(asem);
  //display(asem,0);

  // 把保留字加入hash表
  for(int i=0;i<sizeof(reserved)/sizeof(reserved[0]);++i)
    hc.insert(reserved[i].c_str(),(void*)reserved);
  
  // 插入hash表
  dfs_insert_hash(asem,"");

  // instruction里必须有顶层规则
  //string instr="...instruction.top";
  //assert(hc.find(instr)!=0);
  //找到instruction那一项
  Asem &instruction=*(asem.ivec[0].find((string)"instruction"));

  //找到instruction中的top
  Asem &top=*(instruction.find((string)"top"));
  Asem &rule=*instruction.find(top.ivec[1].name);

  //查看结果
  int allrule=unfold(rule);
  cout<<unfolded_list[allrule].size()<<endl;
  fstream out_txt("out.txt");
  hash_control tmp;
  for(int i=0;i<unfolded_list[allrule].size();++i)
    {
      out_txt<<i<<endl<<"\tcode: "<<unfolded_list[allrule][i].code<<endl
	  <<"\tbinary: "<<unfolded_list[allrule][i].binary<<endl;
      out_txt<<"do: "<<endl;
      for(int i=0;i<unfolded_list[allrule][i].doo.size();++i)
	out_txt<<unfolded_list[allrule][i].doo[i]<<' ';
      out_txt<<endl;
      for(int i=0;i<unfolded_list[allrule][i].off_in_code.size();++i)
	out_txt<<unfolded_list[allrule][i].off_in_code[i]<<' '<<unfolded_list[allrule][i].off_in_binary[i]<<' ';
      out_txt<<endl;
    }

  //接下来是输出到为ir
  //处理wire描述
  Ir ir;
  Asem &asem_wire=*asem.ivec[0].find((string)"wire");
  assert(asem_wire.type==type_is_vector);
  Asem &asem_type=*asem.ivec[0].find((string)"type");
  assert(asem_type.type==type_is_vector);
  for(int i=1;i<asem_wire.ivec.size();++i)
    {
      string wire_type_name=(*asem_wire.ivec[i].find((string)"width")).ivec[1].name;
      //TODO 没有检查type对应的数据类型应该是无符号，查找过程加入出错检查
      int wire_width=string2int((*(*(asem_type.find(wire_type_name))).find((string) "width")).ivec[1].name);
      ir.add_wire(Wire(asem_wire.ivec[i].ivec[0].name,wire_width));
    }
  ofstream out2_txt("out2.txt");
  ir.output_wire(out2_txt);

  // 把code和binary加入到ir里
  for(vector<triple>::iterator ite=unfolded_list[allrule].begin();
      ite!=unfolded_list[allrule].end();++ite)
    {
      vector<pp> tmp;
      for(int i=0;i<ite->off_in_code.size();++i)
	tmp.push_back(pp(ite->off_in_code[i],ite->off_in_binary[i]));
      ir.add_instruction(ite->code,ite->binary,ite->doo,tmp);
    }
  ir.output_instruction_set(out2_txt);
  return 0;
}
