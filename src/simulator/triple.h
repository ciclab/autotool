#ifndef _TRIPLE_H_
#define _TRIPLE_H_
#include <utility>
// 表数据结构 用于保存模拟器 自动生成时展开的内容
class triple
{
public:
  string code;
  string binary;
  vector<pair<string,string> > arg_list;
  vector<int> doo;
  vector<int> off_in_code;
  vector<int> off_in_binary;
  vector<string> enum_name;
  triple(string c,string b){code=c,binary=b;};
  triple(){};
};
#endif
