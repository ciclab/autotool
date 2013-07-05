#include <iostream>
#include <fstream>
#include "wire.h"
#include "instruction.h"
#include <vector>
#include <typeinfo>
using namespace std;
class Ir
{
private:
  vector<Wire> wire;
  vector<Instruction> instruction_set;
public:
  void add_wire(Wire w);
  void output_wire(ofstream &fout);
  void add_instruction(Instruction instr);
  void output_instruction_set(ofstream &fout);
};

void Ir::output_instruction_set(ofstream &fout)
{
  fout<<"(instruction_set"<<endl;
  for(vector<Instruction>::iterator ite=instruction_set.begin();
      ite!=instruction_set.end();++ite)
    {
      fout<<"("<<ite->get_code()<<" "<<ite->get_binary()<<" ";
      for(int i=0;i<ite->get_off_size();++i)
	fout<<ite->get_off(i).first<<' '<<ite->get_off(i).second<<' ';
      fout<<")"<<endl;
    }
  fout<<")"<<endl;
}

void Ir::add_instruction(Instruction instr)
{
  instruction_set.push_back(instr);
}

void Ir::add_wire(Wire w)
{
  wire.push_back(w);
}

void Ir::output_wire(ofstream &fout)
{
  fout<<"(wire"<<endl;
  for(int i=0;i<wire.size();++i)
    fout<<"("<<wire[i].get_name()<<' '<<wire[i].get_width()<<")"<<endl;
  fout<<")"<<endl;
}
