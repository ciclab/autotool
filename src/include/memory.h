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
  int width;
 public:
  Memory(){};
 Memory(string n,int s, int w):name(n),size(s),width(w){};
  void read(ifstream &fin);
  void output(ofstream &fout);
  int get_size();
  int get_width();
  string get_name();
};
#endif
