#ifndef _PIPELINE_BASE_H_
#define _PIPELINE_BASE_H_

#include <string>

class PipelineBase
{
 public:
  static const std::string mName;

  // pipeline freeze
  virtual void Freeze();

  // flush pipeline
  virtual void Flush();

  // init, return true if success
  bool Init();
 private:
  bool mFlushed;
  bool mFreezed;
};

#endif
