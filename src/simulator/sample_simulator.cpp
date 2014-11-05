#include <glog/logging.h>
#include <gflags/gflags.h>

#include "src/simulator/framework/simulator.h"

using namespace std;

DEFINE_string(binaryFilePath, "./binary", "path of binary file");

int main(int argc, char* argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::ParseCommandLineFlags(&argc, &argv, true);

	FLAGS_alsologtostderr = true;

	LOG(INFO)<< "binaryFilePath: " << FLAGS_binaryFilePath;

	Simulator simulator1;

	if (simulator1.LoadBinaryFile(FLAGS_binaryFilePath) && simulator1.Init())
	{
		simulator1.Run();
	}
	else
	{
		LOG(INFO) << "cannot load/init simulaor";
	}

	return 0;
}

