#ifndef _STAGE_GEN_H_
#define _STAGE_GEN_H_

#include <string>
#include <vector>

#include "stages.h"

class StageGen
{
public:
  // generate C++ code for stage class
  static string GenStageCStr(std::vector<Stage>& stage);
};

#endif
