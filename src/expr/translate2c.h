#ifndef _TRANSLATE2C_H_
#define _TRANSLATE2C_H_
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
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
  void output_switch_beg();
  bool is_assignment();
  bool is_vec();
  bool is_string();
  bool is_if();
  bool is_switch();
  bool is_leftshift();
  bool is_call();
  bool is_idx();
  string gen_tmp_var();
};

#endif
