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
  vector<int> value_list;
 public:
  Enum(){};
  void add(string name,string code,int value);
  void output(ofstream & fout);
  void read(ifstream & fin);
  void set_name(string n);
  int width();
  int size();
  string enum_name();
  string ent_name(int);
  string ent_code(int);
  int ent_value(int);
};
#endif
