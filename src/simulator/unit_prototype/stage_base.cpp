#include "stage_base.h"

#include <glog/logging.h>

using namespace std;

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
