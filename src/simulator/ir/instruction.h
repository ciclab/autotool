#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <utility>
#include <vector>
#include <string>
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
#endif
