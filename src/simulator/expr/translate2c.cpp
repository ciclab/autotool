#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;
// For Every Entry in Vector
#define FEEV(a,s,b) for(int a=s;a<(b).size();++a)

class Vardef
{
private:
#define IS_RULE (string)"rule"
  string type;
  string name;
public:
  string get_type();
  string get_name();
  bool is_rule();
  bool is_var();
};
bool Vardef::is_var()
{
  return !is_rule();
}
bool Vardef::is_rule()
{
  return type==IS_RULE;
}
string Vardef::get_type()
{
  return type;
}
string Vardef::get_name()
{
  return name;
}

static ofstream out;

class Varlist
{
private:
  vector<Vardef> variable_list;
public:
  int find_var(string s);
  bool var_is_rule(int i);
  int get_size();
  string get_name(int i);
  string get_type(int i);
  bool is_var(int i);
};
bool Varlist::is_var(int i)
{
  return variable_list[i].is_var();
}
int Varlist::get_size()
{
  return variable_list.size();
}
string Varlist::get_name(int i)
{
  return variable_list[i].get_name();
}
string Varlist::get_type(int i)
{
  return variable_list[i].get_type();
}
bool Varlist::var_is_rule(int i)
{
  return variable_list[i].is_rule();
}
int Varlist::find_var(string s)
{
  FEEV(i,0,variable_list)
    if(variable_list[i].get_name()==s)
      return i+1;
  return 0;
}

class Expression
{
private:
#define IS_VEC 1
#define IS_STATEMENT 2
  int type;
  string statement;
  vector<Expression> expr;
public:
  string get_string();
  void translate_variable_list(string type,string name);
  void translate_function_name(string function_name);
  // 把行为描述从ir转换成c
  void translate(string rule_name,Varlist &vl);
  void translate_or_and_cond(string c);
  string translate_statement(Varlist &vl);
  void output_assignment(string to,string from);
  void output_if_end();
  void output_cond_var(string s);
  void output_rule_call(string);
  void output_if_beg();
  bool is_assignment();
  bool is_vec();
  bool is_string();
  bool is_if();
};
string Expression::get_string()
{
  return statement;
}
void Expression::output_cond_var(string s)
{
  out<<' '<<s<<' ';
}
void Expression::output_if_end()
{
  out<<"}"<<endl;
}
void Expression::translate_or_and_cond(string c)
{
  out<<"(";
  FEEV(i,0,expr)
    {
      if(i)
	out<<c;
      if(expr[i].is_string())
	output_cond_var(expr[i].get_string());
      else if(expr[i].is_vec())
	{
	  if(expr[i].expr[0].get_string()==(string)"or")
	    expr[i].translate_or_and_cond(" || ");
	  else if(expr[i].expr[0].get_string()==(string)"and")
	    expr[i].translate_or_and_cond(" && ");
	  else assert(false);
	}
    }
  out<<")";
}
void Expression::output_if_beg()
{
  out<<"if"<<endl;
}
void output_rule_call(string s)
{
  out<<"s()"<<endl;
}
bool Expression::is_if()
{
  return (is_vec() && expr.size()>0 && expr[0].is_string() && expr[0].statement=="if");
}
bool Expression::is_vec()
{
  return type==IS_VEC;
}
bool Expression::is_string()
{
  return type==IS_STATEMENT;
}
bool Expression::is_assignment()
{
  return (is_vec() && expr.size()>0 && expr[0].is_string() && expr[0].statement==(string)"=");
}
void Expression::output_assignment(string to,string from)
{
  out<<to<<".bak="<<from<<".val;"<<endl;
}
string Expression::translate_statement(Varlist &vl)
{
  if(is_assignment())
    {
      vector<string> obj;
      FEEV(i,1,expr)
	obj.push_back(expr[i].translate_statement(vl));
      FEEV(i,1,obj)
	output_assignment(obj[i-1],obj[i]);
      return obj[0];
    }
  else if(is_string())
    {
      int tmp=vl.find_var(statement);
      if(tmp)
	{
	  if(vl.var_is_rule(tmp))
	    output_rule_call(statement);
	  return NULL;
	}
      return statement;
    }
  else if(is_if())
    {
      output_if_beg();
      expr[1].translate_or_and_cond(" || ");
      FEEV(i,2,expr)
	expr[i].translate_statement(vl);
      output_if_end();
    }
}
void Expression::translate_function_name(string function_name)
{
  out<<"void "<<function_name<<"("<<endl;
}

void Expression::translate_variable_list(string type,string name)
{
  out<<type<<' '<<name;
}
void Expression::translate(string rule_name,Varlist &vl)
{
  // 输出函数名
  translate_function_name(rule_name);

  // 输出函数变量
  for(int i=vl.get_size()-1;i>=0;--i)
    {
      if(vl.is_var(i))
	translate_variable_list(vl.get_type(i),vl.get_name(i));
      if(i)
	out<<" , ";
    }

  // 输出函数体
  out<<"{"<<endl;
  FEEV(i,0,expr)
    expr[i].translate_statement(vl);
  out<<"}"<<endl;
}
