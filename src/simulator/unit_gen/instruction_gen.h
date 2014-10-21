#ifndef _INSTRUCTION_GEN_H_
#define _INSTRUCTION_GEN_H_

#include <string>

#incldue "instruction.h"

class InstructionGen
{
  public:
  // generate C++ code for instruction class
  static std::string GenInstructionCStr(Instruction& Instruction);
};

#endif
