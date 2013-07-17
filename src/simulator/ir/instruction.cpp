#include <utility>
#include <vector>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;
typedef pair<int,int> pp;
class Instruction
{
private:
  string code;
  string binary;
  vector<pp> off;
  vector<string> enum_var;
  vector<int> doo;
public:
  void set_code(string &code);
  void set_binary(string &b);
  void set_off(vector<pp> &o);
  void set_do(vector<int> &d);
  void set_enum_var(vector<string> &ev);
  string get_code();
  string get_binary();
  int get_off_size();
  int get_do_size();
  int get_do(int id);
  int get_enum_var_size();
  string get_enum_var(int id);
  pp get_off(int id);
};
void Instruction::set_enum_var(vector<string> &ev)
{
  enum_var=ev;
}
int Instruction::get_enum_var_size()
{
  return enum_var.size();
}
string Instruction::get_enum_var(int id)
{
  return enum_var[id];
}
void Instruction::set_code(string &c)
{
  code=c;
}
void Instruction::set_binary(string &b)
{
  binary=b;
}
void Instruction::set_off(vector<pp> &o)
{
  off=o;
}
void Instruction::set_do(vector<int> &d)
{
  doo=d;
}
int Instruction::get_do_size()
{
  return doo.size();
}
int Instruction::get_do(int id)
{
  return doo[id];
}
string Instruction::get_code()
{
  return code;
}

string Instruction::get_binary()
{
  return binary;
}

int Instruction::get_off_size()
{
  return off.size();
}

pp Instruction::get_off(int id)
{
  assert(id<get_off_size());
  return off[id];
}
