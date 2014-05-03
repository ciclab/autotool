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
#include "do_content.h"
#include "def.h"
using namespace std;
typedef pair<int,int> pp;
class Instruction
{
private:
  string type;
  string name;
  string code;
  string binary;
  vector<pp> off;
  vector<string> enum_var;
  vector<string> var_name;
  do_content doo;
  vector<pair<string,string>  > arglist;
  vector<int> reloc_info;
  vector<int> do_list;
public:
  void output_arglist(ofstream &fout);
  void output_varname(ofstream &fout);
  void read_arglist(ifstream &fin);
  void read_varname(ifstream &fin);
  void read_reloc_info(ifstream &fin);
  void set_arglist(vector<pair<string,string>  > & al);
  void set_code(string &code);
  void set_binary(string &b);
  void set_off(vector<pp> &o);
  void set_do(do_content &d);
  void set_name(const string & n);
  void set_varname(vector<string>&);
  void set_enum_var(vector<string> &ev);
  void set_reloc_info(vector<int> &);
  void set_do_list(vector<int> &);
  void set_type(string type);
  void read_do_list( ifstream &fin );
  void output_do_list( ofstream &fout);
  string get_code();
  string get_binary();
  int get_off_size();
  void get_reloc_info(vector<int> &);
  string get_type();
  string get_name();
  void get_arglist(vector<pair<string,string> > &);
  // int get_do_size();
  // int get_do(int id);
  int get_enum_var_size();
  void output_do(ofstream & fout);
  void read_do(ifstream &fin);
  void output_reloc_info(ofstream &);
  string get_enum_var(int id);
  void get_off(vector<ppi> &);
  void read(ifstream &);
  void output(ofstream &);
};
#endif
