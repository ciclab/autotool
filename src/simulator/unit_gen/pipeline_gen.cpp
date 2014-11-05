/*
 * pipeline_gen.cpp
 *
 *  Created on: 2014-11-5
 *      Author: q
 */

#include "pipeline_gen.h"

#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

string PipelineGen::GenPipelineCStr(Pipeline& pipeline)
{
	string name = pipeline.get_name();
	int eleSize = pipeline.get_num_ele();

	string code4Ele;
	string code4Init;
	for (int i = 0; i < eleSize; ++i)
	{
		string eleName = pipeline.get_ele_name(i);
		int eleWidth = pipeline.get_ele_width(i);

		code4Ele += boost::lexical_cast<string>(
				boost::format("FixsizeInt %1%;") % eleName);

		code4Init += boost::lexical_cast<string>(
				boost::format("%1%.Init(%2%);") % eleName % eleWidth);
	}

	string code;
	code = boost::lexical_cast<string>(
			boost::format("class %1%: public PipelineBase"
					"{"
					"public:"
					"bool Init() override"
					"{"
					"LOG(INFO) << \"Init pipeline: %1%\";"
					"%2%"
					"return 0;"
					"}"
					"%3%"
					"};") % name % code4Init % code4Ele);

	return code;
}
