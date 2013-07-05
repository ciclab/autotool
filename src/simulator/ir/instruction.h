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
public:
  Instruction(string c,string b,vector<pp> &o);
  string get_code();
  string get_binary();
  int get_off_size();
  pp get_off(int id);
};
#endif
