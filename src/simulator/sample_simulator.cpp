#include <glog/logging.h>
#include <gflags/gflags.h>

//#include "src/simulator/unit_prot/simulator.h"

#include "build/memory_out.h"
#include "build/stage_out.h"
#include "build/pipeline_out.h"
#include "build/simulator_out.h"
#include "build/instruction_out.h"
#include "build/sim_dis.y.h"
#include "build/sim_dis.h"
#include "build/sim_dis.l.h"

#define CHECK_RTN_FUNC(f) for(bool rtn = (); false;){ if(!rtn) return false;}

extern int sim_dis_list_len[100];
extern int sim_dis_list_cnt;

using namespace std;

DEFINE_string(binaryFilePath, "./binary", "path of binary file");

class SampleSimulator: public TSimulator {
public:
	bool AfterLoadBinaryFile(const vector<char>& content) override
	{
		LOG(INFO)<< "In AfterLoadBinaryFile";
		return memory1->Write(0, content.size(), content);
	}

	bool AfterInit() override
	{
		LOG(INFO) << "In afterInit";
		return pc->Write(0, 0);
	}

	void Run() override
	{
		LOG(INFO) << "set pc to 0";
		pc->Write(0, 0);

		{
			vector<char> buf;
			boost::multiprecision::mpz_int nowPc;
			// read pc
			pc->Read(0, nowPc);
			memory1->Read((uint)nowPc, MAX_BINARY_LEN * MAX_SLOT_LEN / 8, buf);

			// decode
			buf.push_back(0);

			std::vector<char> buffer;
			buffer.resize(buf.size() * 8);
			for (int i = 0; i < (int)buf.size() * 8; ++i)
			{
				buffer[i] = buf[i / 8] & (1 << (7 - (7 & i))) ? '1' : '0';
			}

			YY_BUFFER_STATE bs = dis__scan_string (buffer.data());
			sim_dis_list_cnt=0;
			dis_parse ();
			LOG(INFO) << "sim_dis_list_cnt: " << sim_dis_list_cnt;

			dis__delete_buffer (bs);

			LOG(INFO) << "nowPc: " << nowPc;
		}
		LOG(INFO) << "In Run";
	}
};

int main(int argc, char* argv[]) {
	google::InitGoogleLogging(argv[0]);
	google::ParseCommandLineFlags(&argc, &argv, true);

	FLAGS_alsologtostderr = true;

	LOG(INFO)<< "binaryFilePath: " << FLAGS_binaryFilePath;

	SampleSimulator simulator;

	if (simulator.Init() && simulator.LoadBinaryFile(FLAGS_binaryFilePath)) {
		simulator.Run();
	} else {
		LOG(INFO)<< "cannot load/init simulaor";
	}

	return 0;
}

