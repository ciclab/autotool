#ifndef _DO_CONTENT_H_
#define _DO_CONTENT_H_
#include <vector>
#include <string>
#include <fstream>
using namespace std;
#define do_type_is_vector 0

//表示Asem的name有效
//表示没有引号的string，可能是关键词，操作符等
#define do_type_is_string1 1
//表示有引号的string
#define do_type_is_string2 2
using namespace std;
class do_content
{
 public:
  string str;
  int type;
  vector<do_content> ivec;
  bool is_empty();
  void output(ofstream &fout);
  void output_empty(ofstream &fout);
  void read(ifstream &fin);
};
#endif
