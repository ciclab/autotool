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

std::string InstructionGen::GenInstructionCStr(
		const std::string& instructionName,
		const std::vector<do_content>& doContentVec,
		const std::vector<std::string>& varList) {
	std::string doCodeStr;
	// TODO generate code for Do

	std::string initCodeStr;
	initCodeStr =
			boost::lexical_cast<std::string>(
					boost::format(
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

	std::string initVariableCodeStr;

	if (!varList.empty()) {
		std::string varListStr;
		for (const auto& varI : varList) {
			varListStr += ",";
			varListStr += varI;
		}

		initVariableCodeStr = boost::lexical_cast<std::string>(
				boost::format(
						"bool InitVariable (const char* binaryStr) override"
								"{\n"
								"_FUNC_%1%(binaryStr %2%, mPc);\n"
								"return true;\n"
								"}\n") % instructionName % varListStr);
	}

	// translate variable to class member
	std::string argumentCodeStr;
	for_each(varList.begin(), varList.end(), [&](const std::string& var)
	{
		argumentCodeStr += boost::lexical_cast<std::string>(
				boost::format("boost::multiprecision::mpz_int %1%;\n") % var);
	});

	std::string code = boost::lexical_cast<std::string>(
			boost::format("class instr_%1%: public InstructionBase"
					"{"
					"bool Do() override\n{\n"
					"%2%\n"
					"return true;\n"
					"}\n"
					"%4%\n"
					"%5%\n"
					"protected:\n"
					"boost::multiprecision::mpz_int mPc;\n"
					"%3%"
					"};") % instructionName % doCodeStr % argumentCodeStr
					% initCodeStr % initVariableCodeStr);

	return code;
}
