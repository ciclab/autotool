#ifndef _STAGE_H_
#define _STAGE_H_
#include <string>
using namespace std;
class Stage
{
 private:
  string name;
 public:
  Stage(){};
 Stage(string n):name(n){};
  void read(ifstream &);
  void output(ofstream &);
};
#endif
