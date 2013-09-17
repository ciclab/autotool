#ifndef WIRE_H
#define WIRE_H
#include <fstream>
#include <string>
using namespace std;
class Wire
{
private:
  string name;
  int width;
  string end[2];
public:
  Wire(){};
  Wire(string &n,int w);
  void read(ifstream &fin);
  void output(ofstream &fout);
  string get_name();
  int get_width();
};
#endif
