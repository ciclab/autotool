#include "stage_base.h"

using namespace std;

const std::string StatgeBase::mName = "StatgeBase";
const uint StatgeBase::mStageCnt = 0;

bool StageBase::NextStage()
{
  return false;
}

bool StageBase::Init()
{
  return true;
}
