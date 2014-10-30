#ifndef _STAGE_BASE_H
#define _STAGE_BASE_H

#include <string>
#include <vector>

class StageBase
{
 public:
  static const std::string mName;

  // number of stages
  static const uint mStageCnt;

  // all stages
  enum StageListType{};

  // turn into next stage, reutrn false if no next stage
  virtual bool NextStage();

  // Init
  virtual bool Init();

 private:
  StageListType stage;
};

#endif
