/*
 * instruction_gen.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: q
 */

#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <algorithm>

#include "instruction_gen.h"
#include "instruction.h"

std::string InstructionGen::GenInstructionCStr(const std::string& instructionName , const std::vector<do_content>& doContentVec,
        const std::vector<pss>& argList)
{
	std::string doCodeStr;
	// TODO generate code for Do
        
                  std::string initCodeStr;
                  initCodeStr = boost::lexical_cast<std::string>(boost::format(
                          "bool Init(boost::shared_ptr<SimulatorBase> pSimulatorBase, boost::shared_ptr<StageBase> pStageBase) override\n"
                          "{\n"
                          "if (pSimulatorBase.get() == NULL || pStageBase.get() == NULL)"
                          "{"
                          "return false;"
                          "}"
                          "mpSimulator = pSimulatorBase;\n"
                          "mpStage = pStageBase;\n"
                          "return true;\n"
                          "}\n"));
                  
	// translate variable to class member
	std::string argumentCodeStr;
	for_each(argList.begin(), argList.end(), [&](const pss& argument)
			{
				argumentCodeStr += boost::lexical_cast<std::string>(
						boost::format("boost::multiprecision::mpz_int %1%;\n") % argument.first);
			}
		);
                 
	std::string code = boost::lexical_cast<std::string>(boost::format(
			"class instr_%1%: public InstructionBase"
			"{"
			"bool Do() override\n{\n"
			"%2%\n"
                                                      "return true;\n"
			"}\n"
                                                      "%4%"
			"protected:\n"
			"%3%"
			"};") % instructionName % doCodeStr % argumentCodeStr % initCodeStr);

	return code;
}
