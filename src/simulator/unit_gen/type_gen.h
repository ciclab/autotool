#ifndef _TYPE_DEF_GEN_H_
#define _TYPE_DEF_GEN_H_

#include <string>
#include <unordered_set>

class TypeGen
{
public:
  // generate C++ code given type width and signed info
  // e.g. GenTypeCStr(32, false) -> uint32
  static std::string GenTypeCStr(int width, bool sig);
};

#endif
