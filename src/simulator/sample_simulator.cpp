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

  LOG(INFO) << "binaryFilePath: " << FLAGS_binaryFilePath;

  Simulator simulator1;

  return 0;
}
