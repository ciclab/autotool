#ifndef _REG_GEN_H_
#define _REG_GEN_H_

#include <string>

#include "include/register.h"

/*
 * NOTE
 * need #include <boost/multiprecision/gmp.hpp>
 */

class RegGen
{
 public:
  /*
   * generate C++ code for register class
   * @param reg holding register info
   *
   * @return generated code in string
   */
  std::string GenRegCStr(Register& reg);
};

#endif
