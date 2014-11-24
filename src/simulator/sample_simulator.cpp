#include <glog/logging.h>
#include <gflags/gflags.h>

//#include "src/simulator/unit_prot/simulator.h"

#include "build/memory_out.h"
#include "build/stage_out.h"
#include "build/pipeline_out.h"
#include "build/simulator_out.h"

using namespace std;

DEFINE_string(binaryFilePath, "./binary", "path of binary file");

class SampleSimulator: public TSimulator
{
public:
	bool AfterLoadBinaryFile(const vector<char>& content) override
	{
		LOG(INFO) << "In AfterLoadBinaryFile";
		return memory1->Write(0, content.size(), content);
	}

	bool AfterInit() override
	{
		LOG(INFO) << "In afterInit";
		return pc->Write(0, 0);
	}

	void Run() override
	{
		LOG(INFO) << "In Run";
	}
};

int main(int argc, char* argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::ParseCommandLineFlags(&argc, &argv, true);

	FLAGS_alsologtostderr = true;

	LOG(INFO)<< "binaryFilePath: " << FLAGS_binaryFilePath;

	SampleSimulator simulator;

	if (simulator.Init() && simulator.LoadBinaryFile(FLAGS_binaryFilePath))
	{
		simulator.Run();
	}
	else
	{
		LOG(INFO)<< "cannot load/init simulaor";
	}

	return 0;
}

