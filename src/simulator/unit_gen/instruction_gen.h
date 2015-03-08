#ifndef _INSTRUCTION_GEN_H_
#define _INSTRUCTION_GEN_H_

#include <string>
#include <vector>
#include <utility>

#include "instruction_base.h"
#include "do_content.h"

typedef std::pair<std::string, std::string> pss;

class InstructionGen
{
  public:

  /*
   * generate C++ code for instruction class
   */
  std::string GenInstructionCStr(const std::string& instructionName , const std::vector<do_content>& doContentVec, 
          const std::vector<std::string>& varList);
};

#endif
