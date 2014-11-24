#ifndef _INSTRUCTION_GEN_H_
#define _INSTRUCTION_GEN_H_

#include <string>
#include <vector>

#include "instruction_base.h"

class InstructionGen
{
  public:

  /*
   * generate C++ code for instruction class
   */
  std::string GenInstructionCStr(Instruction& Instruction, std::vector<std::string>& needInit);
};

#endif
