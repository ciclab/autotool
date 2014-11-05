#include "stage_base.h"

#include <glog/logging.h>

using namespace std;

const std::string StageBase::mName = "StatgeBase";
const uint StageBase::mStageCnt = 0;

StageBase::~StageBase()
{
	LOG(INFO) << "do nothing";
}

bool StageBase::NextStage()
{
  return false;
}

bool StageBase::Init()
{
  return true;
}
