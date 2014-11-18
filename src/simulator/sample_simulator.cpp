#include <glog/logging.h>
#include <gflags/gflags.h>

//#include "src/simulator/unit_prot/simulator.h"

#include "build/memory_out.h"
#include "build/stage_out.h"
#include "build/pipeline_out.h"
#include "build/simulator_out.h"

using namespace std;

DEFINE_string(binaryFilePath, "./binary", "path of binary file");

int main(int argc, char* argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::ParseCommandLineFlags(&argc, &argv, true);

	FLAGS_alsologtostderr = true;

	LOG(INFO)<< "binaryFilePath: " << FLAGS_binaryFilePath;

	TSimulator simulator;

	if (simulator.LoadBinaryFile(FLAGS_binaryFilePath) && simulator.Init())
	{
		simulator.Run();
	}
	else
	{
		LOG(INFO) << "cannot load/init simulaor";
	}

	return 0;
}

