#include <vector>
#include <string>
#include "../hash.h"
#include <cassert>
using namespace std;
typedef pair<string,string> Tss;
class Assign_element
{
private:
  // 记录发生赋值的前提(那些变量要先被赋值)
  vector<string> cond;
  // to = from
  string from;
  string to;
  // 与生成的c中对应的变量名字
  string ent;
public:
  void add_cond(string &c);
  void set_frm(string &f);
  void set_to(string &t);
  void set_ent(string &e);
};
static int exprnum;
void Assign_element::set_ent(string &e)
{
  ent=e;
}
void Assign_element::add_cond(string &c)
{
  cond.push_back(c);
}
void Assign_element::set_frm(string &f)
{
  from=f;
}
void Assign_element::set_to(string &t)
{
  to=t;
}
//用于保存do的表达式的类
class Expr
{
private:
  // 这个表达式的类型
  #define IS_ASSIGN 1
  #define IS_STRING 2
  #define IS_VECTOR 3
  int type;
  string value;
  vector<Expr> expr;
  vector<vector<string> > read_port;
  vector<vector<string> > write_port;
  hash_control hc_name_port;
public:
  // 分析当前表达式，返回依赖关系
  string analyze(vector<Assign_element> &r);
  // 返回当前表达式是否是赋值
  bool is_assign();
  // 返回当前表达式value是否有效
  bool is_string();
  // 返回当前表达式expr是否有效
  bool is_vector();
  // 返回当前expr是否是索引表达式
  bool is_index();
  // 是否是if判断
  bool is_if();
  // 是否是switch
  bool is_switch();
  // 应该是用来设置设备名字到端口的映射关系
  // 一个设备可能有多个端口
  // 目前认为一个端口在一个clock里只能写一次
  void set_port_info(string &name,vector<string> &r,vector<string> &w);
  // 根据名字返回端口名字
  string get_port(string name,string dir,string p);
  // 根据名字返回对应c代码的对象名字
  string get_c_obj(Expr exp);
  // 返回内部条件表达
  string analyze_if_cond();
  
};
bool Expr::is_switch()
{
  if(is_vector() && expr[0].is_string() && expr[0].value==(string)"switch")
    {
      assert(expr.size()>1 && ((expr.size()%2)==0));
      return true;
    }
  return false;
}
string Expr::analyze_if_cond()
{
  if(is_string())
    return value;
  // 目前不支持更复杂的表达式
  assert(false);
  return (string)"";
}
bool Expr::is_if()
{
  return (is_vector() && expr[0].is_string() && expr[0].value=="if"
	  && expr.size() >1);
}
string Expr::get_c_obj(Expr exp )
{
  if(is_string())
    return value;
  if(is_assign())
    {
      return expr[1].value+(string)"["+expr[2].value+(string)"]";
    }
  assert(0);
  return (string)"";
}

void Expr::set_port_info(string &name,vector<string> &r,vector<string> &w)
{
  int n=read_port.size();
  read_port.resize(n+1);
  write_port.resize(n+1);
  read_port[n]=r;
  assert(hc_name_port.insert(name,(void*)(1+n))!=NULL);
}

string Expr::get_port(string name,string dir,string p)
{
  int tmp;
  tmp=(int)(long long)hc_name_port.find(name);
  assert(tmp);
  if(dir==(string)"read")
    {
      if(p==(string)"")
	return read_port[tmp][0];
      for(int i=0;i<read_port[tmp].size();++i)
	if(read_port[tmp][i]==p)
	  return p;
      assert(0);
    }
  else if(dir==(string)"write")
    {
      if(p==(string)"")
	return write_port[tmp][0];
      for(int i=0;i<write_port[tmp].size();++i)
	if(write_port[tmp][i]==p)
	  return p;
      assert(0);
    }
  assert(0);
  return (string)"";
}

bool Expr::is_index()
{
  return (is_vector() && expr.size()>0 && expr[0].is_string() && expr[0].value==(string)"[]");
}

bool Expr::is_string()
{
  return type==IS_STRING;
}

bool Expr::is_vector()
{
  return type==IS_VECTOR;
}

bool Expr::is_assign()
{
  return (is_vector() && expr.size()>0 && expr[0].is_string() && expr[0].value==(string)"=");
}

string Expr::analyze(vector<Assign_element> &r)
{
  if(is_string())
    {
      return value;
    }
  else if(is_assign())
    {
      // (= c1 c2 c3 ...)
      // 保存赋值对象到chain
      vector<string> chain(expr.size()-1);
      for(int i=1;i<expr.size();++i)
	chain.push_back(analyze(r));

      // 记录下赋值关系
      for(int i=1;i<chain.size();++i)
	{
	  int j=r.size();
	  r.resize(j+1);
	  r[j].add_cond(chain[i]);
	  r[j].set_frm(chain[i]);
	  r[j].set_to(chain[i-1]);
	  r[j].set_ent(chain[i-1]);
	}
      return chain[0];
    }
  else if(is_index())
    {
      // ([] mem index) <=> ( (= port index) ([] mem idx) )
	{
	  // 目前只支持单层的mem
	  assert(expr[1].is_string());
	  int j=r.size();
	  r.resize(j+1);
	  string index=expr[2].analyze(r);
	  r[j].add_cond(index);
	  // 没有from和to
	  string ent=expr[1].value+(string)"["+expr[3].value+(string)"]";
	  r[j].set_ent(ent);
	  return ent;
	}
    }
  else if(is_if())
    {
      // 输出判断对应的c代码
      // 跳过先

      // 把if的条件转换为内部条件表示
      string cond;
      cond=expr[1].analyze_if_cond();
      int s=r.size();
      // 分析子规则
      for(int i=2;i<expr.size();++i)
	expr[i].analyze(r);
      for(;s<r.size();++s)
	r[s].add_cond(cond);
      return (string)"";
    }
  else if(is_switch())
    {
      assert(expr[1].is_string());
      string var=expr[1].value;
    }
  else if(is_vector())
    {
      for(int i=0;i<expr.size();++i)
	{
	  assert(expr[i].is_vector());
	  expr[i].analyze(r);
	}
      return (string)"";
    }
  assert(false);
  return (string)"";
}
