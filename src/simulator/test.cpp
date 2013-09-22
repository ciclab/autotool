#include "ir/ir.h"
int main()
{
  Ir ir;
  ifstream fin("out2.txt");
  ir.read_all(fin);
  return 0;
}
