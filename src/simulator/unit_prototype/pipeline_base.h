#ifndef _PIPELINE_BASE_H_
#define _PIPELINE_BASE_H_

#include <string>

class PipelineBase
{
 public:
  status const std::string mName = "PipelineBase";
  virtual void Freeze();
  virtual void Flush();
 private:
  bool mFlushed;
};

#endif
