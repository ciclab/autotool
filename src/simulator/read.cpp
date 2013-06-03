#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include "hash.h"
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

// 哈希表
class hash_control hc;

class Asem{
public:
  vector<Asem> ivec;
  string name;
  int type;
};

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

void display(Asem asem,int lev){
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
hash_control hc_4_table;
// 表数据结构 用于保存模拟器 自动生成时展开的内容
class table
{
  string name;
  vector< table > element;
};

void simulator(Asem &asem,string pwd)
{
  vector<Asem> &code=asem.find_entry("code");
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

  string toprule="...instruction.top";
  assert(hc.find(toprule.c_str()));
  simulator(*(Asem*)hc.find("...instruction.top"),
	    toprule);
  return 0;
}
