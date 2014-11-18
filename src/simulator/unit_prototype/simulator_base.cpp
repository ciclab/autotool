//#include "src/simulator/unit_prototype.h"

#include <glog/logging.h>

#include "simulator_base.h"

SimulatorBase::SimulatorBase()
{
}

SimulatorBase::~SimulatorBase()
{
}

bool SimulatorBase::LoadBinaryFile(const std::string& filePath)
{
  LOG(INFO) << "Loading " << filePath;

  LOG(INFO) << "do nothing";

  return true;
}

void SimulatorBase::Run()
{
  LOG(INFO) << "do nothing";
}

bool SimulatorBase::Init()
{
  LOG(INFO) << "do nothing";

  return true;
}
