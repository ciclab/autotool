#ifndef _MEM_GEN_H_
#define _MEM_GEN_H_

#include <string>

#include "memory.h"

class MemGen
{
 public:
  // generate C++ code in string for memory class
  static std::string GenMemCStr(Memory& memory);
};

#endif
