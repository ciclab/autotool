#include "instruction_base.h"

#include <glog/logging.h>

InstructionBase::~InstructionBase() {
	LOG(INFO)<< "do nothing";
}

bool InstructionBase::Init(SimulatorBase* pSimulatorBase,
		boost::shared_ptr<StageBase> pStageBase) {
	LOG(INFO)<< "do nothing";

	return true;
}

bool InstructionBase::AfterInit() {
	LOG(INFO)<< "do nothing";

	return true;
}

bool InstructionBase::BeforeInit() {
	LOG(INFO)<< "do nothing";

	return true;
}

bool InstructionBase::Do() {
	LOG(INFO)<< "do nothing";

	return true;
}

bool InstructionBase::InitVariable(const char* bianryStr,
		const boost::multiprecision::mpz_int& nowPc) {
	LOG(INFO)<< "do nothing";

	return true;
}

bool InstructionBase::BeforeInitVariable() {
	LOG(INFO)<< "do nothing";

	return true;
}

bool InstructionBase::AfterInitVariable() {
	LOG(INFO)<< "do nothing";

	return true;
}

bool InstructionBase::NextStage() {
	LOG(INFO)<< "do nothing, return false";

	return false;
}

