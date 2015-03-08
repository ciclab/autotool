/*
 * mem_gen.cpp
 *
 *  Created on: 2014-11-5
 *      Author: q
 */

#include "mem_gen.h"

#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

using namespace std;

string MemGen::GenMemCStr(Memory& memory, vector<string>& needInit)
{
	string name = memory.get_name();
	int size = memory.get_size();
	// NOTE width of memory not use yet

	string code;

	code =
			boost::lexical_cast<string>(
					boost::format(
							"class T%1%: public MemoryBase{"
									"public:"
									"bool Init() override"
									"{"
									"LOG(INFO) << \"Init memory:  %1% , set size: \" << %2%;"
									"mContent.resize(%2%);"
									"return true;"
									"};"
									"};") % name % size);

	needInit.push_back(name);

	return code;
}
