#ifndef WIRE_H
#define WIRE_H
#include <iostream>
#include <string>
using namespace std;
class Wire
{
private:
  string name;
  int width;
  string end[2];
public:
  Wire(string &n,int w);
  void input(istream fin);
  void output(ostream fout);
  string get_name();
  int get_width();
};
#endif
