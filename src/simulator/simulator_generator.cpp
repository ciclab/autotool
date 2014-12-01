/*
 * simulator_generator.cpp
 *
 *  Created on: 2014-11-5
 *      Author: q
 */

#include "simulator/unit_gen/mem_gen.h"
#include "simulator/unit_gen/pipeline_gen.h"
#include "simulator/unit_gen/register_gen.h"
#include "simulator/unit_gen/stage_gen.h"
#include "simulator/unit_gen/simulator_gen.h"
#include "simulator/unit_gen/instruction_gen.h"
#include "ir.h"

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <boost/format.hpp>

DEFINE_string(irFilePath, "out", "ir file");
DEFINE_string(outputFilePath, "out2", "output file path");
DEFINE_string(memoryOutputFilePath, "memory_out.h", "memory output file path");
DEFINE_string(stageOutputFilePath, "stage_out.h", "stage output file path");
DEFINE_string(registerOutputFilePath, "register_out.h",
		"register output file path");
DEFINE_string(pipelineOutputFilePath, "pipeline_out.h",
		"pipeline output file path");
DEFINE_string(simulatorOutputFilePath, "simulator_out.h",
		"simulator output file path");
DEFINE_string(instructionOutputFilePath, "instruction_out.h", "simulator output file path");

using namespace std;
using namespace boost;

int main(int argc, char* argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::ParseCommandLineFlags(&argc, &argv, true);

	FLAGS_alsologtostderr = true;

	ifstream fin;
	fin.open(FLAGS_irFilePath.c_str());

	LOG(INFO)<< "loading ir from file, file name: " << FLAGS_irFilePath;

	Ir ir;
	ir.read_all(fin);

	LOG(INFO)<< "ir loaded";

	std::vector<std::string> memoryNeedInit;

	{
		/*
		 * step 1. generate memory
		 */

		LOG(INFO)<< "generating code for memory...";

		ofstream fout;
		fout.open(FLAGS_memoryOutputFilePath.c_str());

		/*
		 * output header
		 */
		fout << "#ifndef _MEM_GEN_H_\n";
		fout << "#define _MEM_GEN_H_\n";
		fout << "#include \"mem_base.h\"\n";
		fout << "#include <glog/logging.h>\n";

		uint memNum = ir.get_num_mem();

		for (uint i = 0; i < memNum; ++i)
		{
			LOG(INFO) << "generating memory... " << i << "/" << memNum;
			MemGen memGenerator;
			Memory* pMemory = NULL;
			if (ir.GetMemory(i, &pMemory))
			{
				LOG(FATAL) << "memory index error, index: " << i;
			}

			string memCode = memGenerator.GenMemCStr(*pMemory, memoryNeedInit);
			LOG(INFO) << "code for " << i << "th memory: " << memCode << endl;
			fout << memCode;
		}

		fout << "\n#endif\n";
		fout.close();
	}

	{
		/*
		 * step 2. generate stage
		 */

		LOG(INFO)<< "generating code for stage...";

		StageGen stageGenerator;

		vector<Stage>* pStageVec;
		if (ir.GetStageVec(&pStageVec))
		{
			LOG(FATAL) << "cannot get stage";
		}

		string stageCode = stageGenerator.GenStageCStr(*pStageVec);

		LOG(INFO) << "code for stage generated, code: " << stageCode;

		ofstream fout;
		fout.open(FLAGS_stageOutputFilePath.c_str());

		/*
		 * output header
		 */
		fout << "#ifndef _STAGE_GEN_H_\n";
		fout << "#define _STAGE_GEN_H_\n";
		fout << "#include \"stage_base.h\"\n";
		fout << "#include <glog/logging.h>\n";

		fout << stageCode;

		fout << "\n#endif\n";

		fout.close();
	}

	std::vector<std::string> registerNeedInit;
	{
		/*
		 * step 3. generate code for register
		 */

		LOG(INFO)<< "generating code for register...";

		ofstream fout;
		fout.open(FLAGS_registerOutputFilePath.c_str());

		fout << "#ifndef _REGISTER_GEN_H_\n";
		fout << "#define _REGISTER_GEN_H_\n";
		fout << "#include \"register_base.h\"\n";
		fout << "#include <glog/logging.h>\n";

		int registerNum = ir.get_num_reg();

		for (int i = 0; i < registerNum; ++i)
		{
			Register* pRegister;
			if (ir.GetRegister(i, &pRegister))
			{
				LOG(FATAL) << "cannot get " << i << "th register";
			}

			RegGen registerGenerator;

			string registerCode;
			registerCode = registerGenerator.GenRegCStr(*pRegister, registerNeedInit);

			LOG(INFO) << "code generated for " << i << "th register: " << registerCode;

			fout << registerCode;
		}

		fout << "\n#endif\n";
		fout.close();

		LOG(INFO) << "code for registers generated";
	}

	{
		/*
		 * step 4. generate code for pipeline
		 */
		LOG(INFO)<< "generating code for pipeline...";

		ofstream fout;
		fout.open(FLAGS_pipelineOutputFilePath.c_str());

		fout << "#ifndef _PIPELINE_GEN_H_\n";
		fout << "#define _PIPELINE_GEN_H_\n";
		fout << "#include \"pipeline_base.h\"\n";
		fout << "#include <glog/logging.h>\n";
		fout << "#include \"fixsize_int.h\"\n";

		int pipelineNum = ir.get_num_pipeline();

		for (int i = 0; i < pipelineNum; ++i)
		{
			LOG(INFO) << "generating code for " << i << "th pipeline";

			Pipeline* pPipeline(NULL);
			if (ir.GetPipline(i, &pPipeline))
			{
				LOG(FATAL) << "cannot get " << i << "th pipeline";
			}

			PipelineGen pipelineGenerator;
			string pipelineCode = pipelineGenerator.GenPipelineCStr(*pPipeline);

			LOG(INFO) << "code for " << i << "th pipeline: " << pipelineCode;
			fout << pipelineCode;
		}

		fout << "\n#endif\n";
		fout.close();

		LOG(INFO) << "code for pipeline generated";
	}
        
//                    std::vector<std::string> instructionNeedInit;
                  {
                                    /*
                                     * step 5. generate code for instruction
                                    */
                                    LOG(INFO) << "generating code for instructions...";
                                    
                                    ofstream fout;
                                    fout.open(FLAGS_instructionOutputFilePath.c_str());
                                    
                                    fout << "#ifndef _instruction_GEN_H_\n";
                                    fout << "#define _instruction_GEN_H_\n";
		fout << "#include \"instruction_base.h\"\n";
                                    fout << "#include <boost/multiprecision/gmp.hpp>\n";
                
                                    int size = ir.get_instr_size();
                                    LOG(INFO) << "number of instruction: " << size;
                                    
                                    InstructionGen instructionGenerator;
                                    for (int i  = 0; i < size; ++i)
                                    {
                                        LOG(INFO) << "generating code for " << i << "th instruction";
                                        
                                        std::vector<do_content> doContentVec;
                                        ir.get_instruction_do_content(i, doContentVec);
                                        std::string instructionName = ir.get_instr_name(i);
                                        std::vector<pss> argList;
                                        ir.get_instr_arglist(i, argList);
                                        
                                        std::string instructionCode = instructionGenerator.GenInstructionCStr(instructionName, 
                                                doContentVec, argList);
                                        
                                        fout << instructionCode << endl;;
                                    }
                                    
		fout << "\n#endif\n";
		fout.close();

		LOG(INFO) << "code for instruction generated";
                  }

	{

                                    /*
                                     * final step. generate code for simulator
                                     */
            
		LOG(INFO)<< "generating code for simulator...";

		ofstream fout;
		fout.open(FLAGS_simulatorOutputFilePath.c_str());

		fout << "#ifndef _simulator_GEN_H_\n";
		fout << "#define _simulator_GEN_H_\n";
		fout << "#include <glog/logging.h>\n";
		fout << "#include \"simulator_base.h\"\n";
		fout << format("#include \"%1%\"\n") % FLAGS_memoryOutputFilePath;
		fout << format("#include \"%1%\"\n") % FLAGS_stageOutputFilePath;
		fout << format("#include \"%1%\"\n") % FLAGS_pipelineOutputFilePath;
		fout << format("#include \"%1%\"\n") % FLAGS_registerOutputFilePath;

		SimulatorGen simulatorGen;
		string simulatorCode = simulatorGen.GenSimulatorCStr(memoryNeedInit,
				registerNeedInit);

		fout << simulatorCode;

		fout << "\n#endif\n";
		fout.close();

		LOG(INFO) << "code for simulator generated";
	}

	return 0;
}

