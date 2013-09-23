#ifndef _MEMORY_H
#define _MEMORY_H
#include <fstream>
#include <string>
using namespace std;
class Memory
{
 private:
  string name;
  int size;
  string type;
  string idx;
 public:
  Memory(){};
 Memory(string n,int s,string t,string i):name(n),size(s),type(t),idx(i){};
  void read(ifstream &fin);
  void output(ofstream &fout);
};
#endif
