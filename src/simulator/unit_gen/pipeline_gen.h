#ifndef _PIPELINE_GEN_H_
#define _PIPELINE_GEN_H_

#include <string>

#include "pipeline.h"
#include <vector>

class PipelineGen
{
public:
  // generate C++ code for pipeline Class
  std::string GenPipelineCStr(Pipeline& pipeline);

};

#endif
