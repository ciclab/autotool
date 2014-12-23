#include <glog/logging.h>
#include <gflags/gflags.h>

//#include "src/simulator/unit_prot/simulator.h"

#include <deque>

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
extern InstructionBase * sim_dis_list[100];
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
			// step 1. fetch
			pc->Read(0, nowPc);
			memory1->Read((uint)nowPc, MAX_BINARY_LEN * MAX_SLOT_LEN / 8, buf);

			// step 2. decode
			buf.push_back(0);

			std::string buffer;
			buffer.resize(buf.size() * 8);
			for (int i = 0; i < (int)buf.size() * 8; ++i)
			{
				buffer[i] = buf[i / 8] & (1 << (7 - (7 & i))) ? '1' : '0';
			}

			YY_BUFFER_STATE bs = dis__scan_string (buffer.data());
			sim_dis_list_cnt=0;
			for (int i(0); i < MAX_SLOT_LEN; ++i)
			{
				sim_dis_list[i] = NULL;
			}

			dis_parse ();
			LOG(INFO) << "sim_dis_list_cnt: " << sim_dis_list_cnt;

			for (int i(0); i < sim_dis_list_cnt; ++i)
			{
				nowPc += sim_dis_list_len[i] / 4;
			}

			vector<boost::shared_ptr<InstructionBase> > instructionPtrVec;
			for (int i(0), binaryInBuffer(0); i < sim_dis_list_cnt; ++i)
			{
				LOG(INFO) << "instruction: " << i << " address: " << sim_dis_list[i];
				if (sim_dis_list_len[i] > 0 && sim_dis_list[i] != NULL)
				{
					boost::shared_ptr<StageBase> pStage(new TStage);
					if (!pStage->Init())
					{
						LOG(ERROR) << "Stage Init error";
						throw "Stage Init error";
					}
					if (!sim_dis_list[i]->Init(this, pStage))
					{
						LOG(ERROR) << "Instruction init error";
						throw "Instruction init error";
					}

					LOG(INFO) << "init variable: " << i << ' ' << sim_dis_list[i];
					if (!sim_dis_list[i]->InitVariable(buffer.data() + binaryInBuffer, nowPc))
					{
						LOG(ERROR) << "InitVariable error";
						throw "Instruction initVariable error";
					}
				}

				instructionPtrVec.push_back(boost::shared_ptr<InstructionBase>(sim_dis_list[i]));

				binaryInBuffer += sim_dis_list_len[i];
			}

			mInstructionPtrQue.push_back(instructionPtrVec);

			dis__delete_buffer (bs);

			LOG(INFO) << "nowPc: " << nowPc;

			// step 3. push new instructions to queue
			for (auto instructionVecQueIte: mInstructionPtrQue)
			{
				for (auto instructionVecIte: instructionVecQueIte)
				{
					if (instructionVecIte.get() != NULL)
					{
						if(!instructionVecIte->Do())
						{
							LOG(ERROR) << "Instruction do error";
						}

						if (!instructionVecIte->NextStage())
						{
							instructionVecIte.reset();
						}
					}
				}
			}

			// delete useless instruction vector
			for (;!mInstructionPtrQue.empty();)
			{
				auto frontVec = mInstructionPtrQue.front();
				bool erase(true);
				for (auto ite: frontVec)
				{
					if (ite.get() != NULL)
					{
						erase = false;
						break;
					}
				}
				if (erase)
				{
					mInstructionPtrQue.pop_front();
				}
				else
				{
					break;
				}
			}
		}
	}
private:
	deque<vector<boost::shared_ptr<InstructionBase> > > mInstructionPtrQue;
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

