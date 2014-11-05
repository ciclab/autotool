#include "src/simulator/framework/simulator.h"

#include <glog/logging.h>

Simulator::Simulator()
{
}

Simulator::~Simulator()
{
}

bool Simulator::LoadBinaryFile(const std::string& filePath)
{
  LOG(INFO) << "Loading " << filePath;

  LOG(INFO) << "do nothing";

  return false;
}

void Simulator::Run()
{
  LOG(INFO) << "do nothing";
}

bool Simulator::Init()
{
  LOG(INFO) << "do nothing";

  return true;
}
