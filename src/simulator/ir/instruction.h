#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <utility>
#include <vector>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
#include "../asem.h"
#include "../do_content.h"
using namespace std;
typedef pair<int,int> pp;
class Instruction
{
private:
  string name;
  string code;
  string binary;
  vector<pp> off;
  vector<string> enum_var;
  do_content doo;
  vector<pair<string,string>  > arglist;
public:
  void output_arglist(ofstream &fout);
  void read_arglist(ifstream &fin);
  void set_arglist(vector<pair<string,string>  > & al);
  void set_code(string &code);
  void set_binary(string &b);
  void set_off(vector<pp> &o);
  void set_do(do_content &d);
  void set_name(const string & n);
  void set_enum_var(vector<string> &ev);
  string get_code();
  string get_binary();
  int get_off_size();
  // int get_do_size();
  // int get_do(int id);
  int get_enum_var_size();
  void output_do(ofstream & fout);
  void read_do(ifstream &fin);
  string get_enum_var(int id);
  pp get_off(int id);
  void read(ifstream &);
  void output(ofstream &);
};
#endif
