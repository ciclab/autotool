#include "ir.h"
#include "def.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(int argc,char *argv[])
{
  assert(argc==3);
  ifstream fin;
  fin.open(argv[1],ofstream::in);
  Ir ir;
  ir.read_all(fin);
  
  int instr_size=ir.get_instr_size();
  string top_rule_name=ir.get_top_rule_name();
  
  FOR(i,0,instr_size)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
	  cout<<n<<endl;
	  cout<<ir.get_instr_code(i)<<endl;
	  cout<<ir.get_instr_binary(i)<<endl;
	  vector<ppi> off;
	  ir.get_instr_off(i,off);
	  FR(i,off)
	    cout<<i->first<<' '<<i->second<<endl;
	  cout<<endl<<endl;
	}
    }
  return 0;
}
