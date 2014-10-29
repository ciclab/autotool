#ifndef _TRIPLE_H_
#define _TRIPLE_H_
#include <utility>
#include <vector>
#include "do_content.h"
#include "asem.h"
using namespace std;
// 表数据结构 用于保存模拟器 自动生成时展开的内容

class triple
{
 public:
  string rulename;
  string code;
  string binary;
  string type;
  vector<pair<string,string> > arg_list;
  do_content doo;
  vector<int> off_in_code;
  vector<int> off_in_binary;
  vector<string> var_name;
  vector<int> var_len;
  vector<int> reloc_info;
  vector<string> enum_name;
  vector<int> do_list;
 triple(string n,string c,string b,string t):
  rulename(n),code(c),binary(b),type(t){};
  triple(){};
};
#endif
