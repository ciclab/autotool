#include <utility>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
typedef pair<int,int> pp;
class Instruction
{
private:
  string code;
  string binary;
  vector<pp> off;
public:
  Instruction(string c,string b,vector<pp> &o);
  string get_code();
  string get_binary();
  int get_off_size();
  pp get_off(int id);
};

Instruction::Instruction(string c,string b,vector<pp> &o)
{
  code=c;
  binary=b;
  off=o;
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
