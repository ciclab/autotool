/*
 * simulator_gen.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: q
 */

#include "simulator_gen.h"

#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

using namespace std;
using namespace boost;

string SimulatorGen::GenSimulatorCStr(const vector<string>& memory,
		const vector<string>& registerFile)
{
	string functionUnitDeclarationCode;
	string functionUnitInitCode;
	{
		functionUnitDeclarationCode += "private:\n";
		/*
		 * generate code for memory declaration and initialization in simulator
		 */
		for (auto i : memory)
		{
			functionUnitDeclarationCode += lexical_cast<string>(
					format("std::shared_ptr<MemoryBase> %1%;\n") % i);
			functionUnitInitCode += lexical_cast<string>(
					format("%1%.reset(new T%1%);\n"
							"if (!%1%->Init())"
							"{"
							"return false;"
							"}\n") % i);
		}
	}

	{
		/*
		 * generate code for register declaration and initialization in simulator
		 */
		functionUnitDeclarationCode += "private:\n";
		for (auto i : registerFile)
		{
			functionUnitDeclarationCode += lexical_cast<string>(
					format("std::shared_ptr<RegisterBase> %1%;\n") % i);
			functionUnitInitCode += lexical_cast<string>(
					format("%1%.reset(new T%1%);\n"
							"if (!%1%->Init())"
							"{"
							"return false;"
							"}\n") % i);
		}
	}

	string code = lexical_cast<string>(
			format("class TSimulator: public SimulatorBase{\n"
					"%1%\n"
					"public:"
					"bool Init() override{\n"
					"%2%\n"
					"return true;\n"
					"}"
					"};") % functionUnitDeclarationCode % functionUnitInitCode);

	return code;
}

