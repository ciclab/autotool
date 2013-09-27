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
  void set_name(string n);
  int size();
  string enum_name();
  string ent_name(int);
  string ent_code(int);
};
#endif
