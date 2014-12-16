#include "instruction_base.h"

#include <glog/logging.h>

InstructionBase::~InstructionBase()
{
	LOG(INFO) << "do nothing";
}

bool InstructionBase::Init(boost::shared_ptr<SimulatorBase> pSimulatorBase, boost::shared_ptr<StageBase> pStageBase)
{
	LOG(INFO) << "do nothing";

	return true;
}

bool InstructionBase::AfterInit()
{
	LOG(INFO) << "do nothing";

	return true;
}

bool InstructionBase::BeforeInit()
{
	LOG(INFO) << "do nothing";
	return true;
}

bool InstructionBase::Do()
{
	LOG(INFO) << "do nothing";

	return true;
}
