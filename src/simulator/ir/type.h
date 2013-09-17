#ifndef _TYPE_H_
#define _TYPE_H_
#include <vector>
#include <string>
using namespace std;
class Type
{
 public:
  string name;
  int len;
  string type;
  Type(){};
  Type(string,int,string);
  void output(ofstream&);
  void read(ifstream&);
};
#endif
