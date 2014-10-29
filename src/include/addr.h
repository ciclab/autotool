#ifndef _ADDR_H_
#define _ADDR_H_
#include <fstream>
#include <string>
using namespace std;
class Addr
{
 private:
  int width;
  bool pcrel;
  int right_shift;
  string name;
 public:
  Addr(){};
 Addr(int w,int p,int r,string n):width(w),pcrel(p),right_shift(r),name(n){};
  void set_width(int);
  void set_pcrel(bool);
  void set_right_shift(int);
  void set_name(string);
  void set(int,bool,int,string);
  int get_width();
  bool get_pcrel();
  int get_right_shift();
  string get_name();
  int ent_value(int);
  void read(ifstream &);
  void output(ofstream &);
};
#endif
