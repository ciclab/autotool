#ifndef _ADDR_H_
#define _ADDR_H_
#include <fstream>
using namespace std;
class Addr
{
 private:
  int width;
  bool pcrel;
  int right_shift;
 public:
  Addr(){};
 Addr(int w,int p,int r):width(w),pcrel(p),right_shift(r){};
  void set_width(int);
  void set_pcrel(bool);
  void set_right_shift(int);
  void set(int,bool,int);
  int get_width();
  bool get_pcrel();
  int get_right_shift();
  int ent_value(int);
  void read(ifstream &);
  void output(ofstream &);
};
#endif
