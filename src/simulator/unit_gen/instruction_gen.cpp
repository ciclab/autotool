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

std::string InstructionGen::GenInstructionCStr(Instruction& instruction,
		std::vector<std::string>& needInit)
{
	// get do content
	do_content doContent;
	instruction.GetDoContent(doContent);
	std::string doCodeStr;
	// TODO generate code for Do

	// get argument list
	typedef std::pair<std::string, std::string> pss;
	std::vector<pss> argList;
	instruction.get_arglist(argList);
	// translate variable to class member
	std::vector<std::string> argumentCodeStr;
	for_each(argList.begin(), argList.end(), [&](const pss& argument)
			{
				argumentCodeStr += boost::lexical_cast<std::string>(
						boost::format("mpz_int %1%;\n") % argument.first);
			}
		);

	// name of instruction
	std::string name = instruction.get_name();

	std::string code = boost::lexical_cast<std::string>(boost::format(
			"class Instruction T%1%: public InstructionBase"
			"{"
			"bool Do() override\n{\n"
			"%2%\n"
			"}\n"
			"protected:\n"
			"%3"
			"};") % name % doCodeStr % argumentCodeStr);

	return code;
}
