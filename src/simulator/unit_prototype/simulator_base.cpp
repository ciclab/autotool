//#include "src/simulator/unit_prototype.h"

#include <glog/logging.h>
#include <boost/filesystem.hpp>
#include <fstream>

#include "simulator_base.h"

using namespace std;
using namespace boost;

SimulatorBase::SimulatorBase()
{
}

SimulatorBase::~SimulatorBase()
{
}

bool SimulatorBase::BeforeLoadBinaryFile(const string& filePath)
{
	LOG(INFO)<< "Before load binary file, do nothing";

	return true;
}

bool SimulatorBase::AfterLoadBinaryFile(const vector<char>& content)
{
	LOG(INFO)<< "After load binary file, do nothing";

	return true;
}

bool SimulatorBase::LoadBinaryFile(const std::string& filePath)
{
	if (!BeforeLoadBinaryFile(filePath))
	{
		return false;
	}

	LOG(INFO)<< "loading file" << filePath;

	filesystem::path binaryFile(filePath);

	if (!filesystem::exists(binaryFile))
	{
		LOG(ERROR)<< "file not exist, file name: " << filePath;
		return false;
	}

	if (!filesystem::is_regular_file(binaryFile))
	{
		LOG(ERROR)<< "given file is not regular, file name: " << filePath;
		return false;
	}

	ifstream fileIf;
	fileIf.open(filePath.c_str(), ios::binary | ios::in);

	vector<char> content;
	for (char t; EOF != (t = fileIf.get());)
	{
		content.push_back(t);
	}

	LOG(INFO)<< "binary file loaded, file name: " << filePath;

	return AfterLoadBinaryFile(content);
}

void SimulatorBase::Run()
{
	LOG(INFO)<< "do nothing";
}

bool SimulatorBase::Init()
{
	if (!BeforeInit())
	{
		LOG(WARNING) << "Before Init failed";
		return false;;
	}

	LOG(INFO)<< "do nothing";

	if (!AfterInit())
	{
		LOG(WARNING) << "After Init failed";
		return false;
	}

	return true;
}

bool SimulatorBase::BeforeInit()
{
	LOG(INFO)<< "Before init, do nothing";
	return true;
}

bool SimulatorBase::AfterInit()
{
	LOG(INFO)<< "After init, do nothing";
	return true;
}
