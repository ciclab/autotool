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
  ofstream fout;
  fout.open(argv[2],ofstream::out);
  FOR(i,0,instr_size)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
#if ASGEN_COUT==1
	  cout<<<<endl;
	  vector<ppi> off;
	  ir.get_instr_off(i,off);
	  FR(i,off)
	    cout<<i->first<<' '<<i->second<<endl;
	  cout<<endl<<endl;
#endif
	  string code=ir.get_instr_code(i);
	  string binary=ir.get_instr_binary(i);
	  fout<<"\t\\\\"<<n<<' '<<binary<<endl;
	  FR(i,binary)
	    switch(*i)
	      {
	      case '1':
		fout<<"C_1 ";break;
	      case '0':
		fout<<"C_0 ";break;
	      case '-':
	      case 'x':
		fout<<"C_0_1 ";break;
	      default: assert(0);
	      }
	  fout<<endl;
	}
    }
  return 0;
}
