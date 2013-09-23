#include "ir/ir.h"
int main()
{
  Ir ir;
  ifstream fin("out2.txt");
  ir.read_all(fin);
  ofstream fout("out3.txt");
  ir.output_all(fout);
  return 0;
}
