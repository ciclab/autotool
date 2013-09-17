#include "translate2c.h"
// For Every Entry in Vector
#define FEEV(a,s,b) for(int a=s;a<(b).size();++a)

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
bool Expression::is_idx()
{
  return (is_vec() && expr.size()>0 && expr[0].is_string () &&
	  expr[0].get_string()==(string)"[]");
}
bool Expression::is_call()
{
  return (is_vec() && expr.size()>0 &&
	  expr[0].is_string() &&
	  expr[0].get_string()[0]=='#');
}
string Expression::gen_tmp_var()
{//得到一个数
  static int cnt=0;
  string buf;
#define base 4
  for(int i=cnt++;i;i>>=base)
    {
      int t=i&((1<<base)-1);
      char tt;
      if(t>=10)
	tt=t+'A';
      else tt=t+'0';
      buf.insert(buf.begin(),tt);
    }
  return (string)"tmp"+buf;
}
bool Expression::is_leftshift()
{
  return (is_vec() && expr[0].is_string() && 
	  expr[0].get_string()==(string)"<<");
}
void Expression::output_switch_beg()
{
  out<<"switch";
}
bool Expression::is_switch()
{
  return (is_vec() && expr.size()>2 && expr[0].is_string() &&
	  expr[0].get_string()==(string)"switch");
}
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
  //TODO 如果from和to都是wire的话，应该特殊处理。
  out<<to<<".tmp="<<from<<".val;"<<endl;
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
      return NULL;
    }
  else if(is_switch())
    {
      output_switch_beg();
      expr[1].translate_or_and_cond(" || ");
      out<<"{";
      FEEV(i,2,expr)
	{
	  out<<"case \'"<<expr[i].get_string()<<"\'";
	  ++i;
	  out<<": ";
	  expr[i].translate_statement(vl);
	  out<<endl;
	}
      out<<"}"<<endl;
      return NULL;
    }
  else if(is_leftshift())
    {
      string tmpvar=gen_tmp_var();
      out<<tmpvar<<"="<<expr[1].translate_statement(vl)<<"<<"\
	 <<expr[2].translate_statement(vl)<<endl;
      return tmpvar;
    }
  else if(is_call())
    {
      vector<string> tmp;
      FEEV(i,1,expr)
	tmp.push_back(expr[i].translate_statement(vl));
      out<<expr[0].get_string()<<"(";
      FEEV(i,0,tmp)
	{
	  if(i)
	    out<<",";
	  out<<tmp[i];
	}
      out<<")";
    }
  else if(is_idx())
    {
      return expr[1].translate_statement(vl)+(string)"["+expr[2].translate_statement(vl)+(string)"]";
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
