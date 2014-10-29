#ifndef _STAGES_H_
#define _STAGES_H_
#include <string>
#include <fstream>
using namespace std;
class Stage
{
 private:
  string name;
 public:
  Stage(){};
 Stage(string n):name(n){};
  void read(ifstream &fin);
  void output(ofstream &fout);
  string get_name();
};
#endif
