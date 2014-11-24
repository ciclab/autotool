#include "instruction_base.h"

#include <glog/logging.h>

InstructionBase::~InstructionBase()
{
	LOG(INFO) << "do nothing";
}

bool InstructionBase::Init()
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
