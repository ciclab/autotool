#ifndef _REG_GEN_H_
#define _REG_GEN_H_

#include <string>

#include "register.h"

class RegGen
{
 public:
  // generate C++ code for register class
  static std::string GenRegCStr(Register &register);
};

#endif
