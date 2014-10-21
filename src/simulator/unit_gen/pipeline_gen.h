#ifndef _PIPELINE_GEN_H_
#define _PIPELINE_GEN_H_

#include <string>

#include "pipeline.h"

class PipelineGen
{
public:
  // generate C++ code for pipeline Class
  static std::string GenPipelineCStr(Pipeline& pipeline);

};

#endif
