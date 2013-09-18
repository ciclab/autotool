#ifndef _ENUM_H_
#define _ENUM_H_
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Enum
{
 private:
  string name;
  vector<pair<string,string> > list;
 public:
  Enum(){};
  void add(string name,string code);
  void output(ofstream & fout);
  void read(ifstream & fin);
};
#endif
