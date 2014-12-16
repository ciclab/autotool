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

string PipelineGen::GenPipelineCStr(Pipeline& pipeline,
		std::vector<std::string>& needInit) {
	string name = pipeline.get_name();
	int eleSize = pipeline.get_num_ele();

	string code4Ele;
	string code4Init;
	string code4Read;
	string code4Write;

	for (int i = 0; i < eleSize; ++i) {
		string eleName = pipeline.get_ele_name(i);
		int eleWidth = (int) pipeline.get_ele_width(i);

		code4Ele += boost::lexical_cast<string>(
				boost::format("FixsizeInt %1%;") % eleName);

		code4Init += boost::lexical_cast<string>(
				boost::format("if (! %1%.Init(%2%))\n"
						"{\n"
						"LOG(ERROR)<<\"Cannot init %1%\";"
						"return false;\n"
						"}\n") % eleName % eleWidth);

		code4Read += boost::lexical_cast<string>(
				boost::format(
						"bool Read%1%(boost::multiprecision::mpz_int& val)\n"
								"{\n"
								"val = %1%.value;\n"
								"return true;"
								"}\n") % eleName);

		code4Write +=
				boost::lexical_cast<string>(
						boost::format(
								"bool Write%1%(const boost::multiprecision::mpz_int& val)\n"
										"{\n"
										"%1%.value = val;\n"
										"return true;"
										"}\n") % eleName);
	}

	string code;
	code = boost::lexical_cast<string>(
			boost::format("class T%1%: public PipelineBase"
					"{"
					"public:"
					"bool Init() override"
					"{"
					"LOG(INFO) << \"Init pipeline: %1%\";"
					"%2%"
					"return true;"
					"}"
					"%3%"
					"%4%"
					"%5%"
					"};") % name % code4Init % code4Ele % code4Read
					% code4Write);

	needInit.push_back(name);

	return code;
}
