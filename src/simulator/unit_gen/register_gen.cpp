/*
 * register.cpp
 *
 *  Created on: 2014-11-5
 *      Author: q
 */

#include "register_gen.h"

#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

string RegGen::GenRegCStr(Register& reg)
{
	string name = reg.get_name();
	uint size = reg.get_size();
	uint width = reg.get_width();

	string code = boost::lexical_cast<string>(
			boost::format("class %1%: public RegisterBase{"
					"public:"
					"bool Init() override"
					"{"
					"LOG(INFO) << \"Init register:  %1%\";"
					"mWidth = %2%;"
					"mContent.resize(%3%);"
					"return true;"
					"};"
					"};") % name % width % size);

	return code;
}

