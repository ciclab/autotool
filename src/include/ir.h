#ifndef _IR_H_
#define _IR_H_
#include <iostream>
#include <fstream>
#include "wire.h"
#include "instruction.h"
#include <vector>
#include <typeinfo>
#include "do_content.h"
#include "type.h"
#include "stages.h"
#include "enum.h"
#include "memory.h"
#include "register.h"
#include "pipeline.h"
#include "def.h"
#include "addr.h"
#include "asem.h"
using namespace std;
class Ir
{
private:
  vector<Wire> wire;
  vector<Type> type;
  vector<Stage> stage;
  vector<Instruction> instruction_set;
  vector<Enum> enumm;
  vector<Memory> memory;
  vector<Register> registers;
  vector<Pipeline> pipeline;
  vector<Addr> addr;
  vector<do_content> docnt;
  string top_rule_name;
  bool vliw_mode_set;
  int vliw_mode_sig;
  int vliw_mode_off;
public:
  Ir(){vliw_mode_set=false;};
  //asgen interface
  Enum find_enum(string name);
  Type get_type(int);
  int type_size();
  void get_enum(int,Enum &);
  int get_num_enum();
  void get_instr_off(int,vector<ppi> &);
  string get_instr_type(int );
  void get_instr_arglist(int,vector<pair<string,string> > &);
  string get_instr_binary(int);
  int get_instr_size();
  string get_top_rule_name();
  string get_instr_name(int);
  string get_instr_code(int);
  void get_instr_reloc_info(int , vector<int> &);
  //reader writer interface
  bool get_vliw_mode(int &,int &);
  void add_vliw_mode(int,int);
  void output_vliw_mode(ofstream &fout);
  void read_vliw_mode(ifstream &fin);
  int addr_size();
  void get_addr(int,Addr &);
  void add_addr(Addr);
  void read_addr(ifstream &fin);
  void output_addr(ofstream &fout);
  void add_top_name(string n);
  void add_stage(Stage s);
  void read_stage(ifstream &fin);
  void output_stage(ofstream &fout);
  void add_type(Type t);
  /* void add_wire(string &n,int w); */
  void add_wire(Wire w);
  void output_wire(ofstream &fout);
  void read_wire(ifstream &fin);
  void add_instruction(const string &name,string &c,string &b,
		       vector<pp> &off,vector<string> &enum_var,vector<pair<string,string>  > &al,
		       vector<int> &ri,string type, vector<string> &vn, vector<int> &dl);
  void add_do_content( Asem & dc);
  void output_instruction_set(ofstream &fout);
  void read_instr(ifstream &fin);
  void output_type(ofstream &fout);
  void read_type(ifstream &fin);
  void add_enum(string name);
  void add_enum_entry(string name,string code,int value);
  void read_enum(ifstream & fin);
  void output_enum(ofstream & fout);
  void add_memory(Memory m);
  void output_memory(ofstream &);
  void read_memory(ifstream &);
  void add_register(Register r);
  void read_register(ifstream &);
  void output_register(ofstream &);
  void add_pipeline(Pipeline p);
  void read_pipeline(ifstream &);
  void output_pipeline(ofstream &);
  void output_all(ofstream &);
  void read_all(ifstream &);
  int get_mem_size(int i);
  int get_mem_width(int i);
  string get_mem_name(int i);
  int get_num_mem();
  int get_num_reg();
  string get_reg_name(int i);
  int get_reg_size(int i);
  int get_reg_width(int i);
  int find_type(string);
  string get_type_name(int i);
  int get_type_width(int i);
  int get_num_pipeline();
  int get_pipeline_width(int i);
  string get_pipeline_name(int i);
  void output_do_content(ofstream &out);
  void read_do_content(ifstream &fin);
};
#endif
