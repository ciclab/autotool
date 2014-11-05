/*
 * stage_gen.cpp
 *
 *  Created on: 2014-11-5
 *      Author: q
 */

#include "stage_gen.h"

#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

using namespace std;

string StageGen::GenStageCStr(vector<Stage>& stage)
{
	string name = "stage";

	string enumList;
	for (int i = 0; i < stage.size(); ++i)
	{
		if (i != stage.size() - 1)
		{
			enumList += ", ";
		}

		enumList += stage[i].get_name();
	}

	string enumEndToken = "STAGE_END_TOKEN";

	string code;

	code = boost::lexical_cast<string>(
			boost::format(
					"class %1%: public StageBase<StageList%1%>"
					"{"
					"public:"
					"enum StageList {%2%};"
					"bool Init() override"
					"{"
					"stage = 0;"
					"return true;"
					"};"
					"bool NextStage() override"
					"{"
					"if (stage != %3%)"
					"{"
					"++stage;"
					"return true;"
					"}"
					"return false;"
					"};"
					"};") % name % enumList % enumEndToken);

	return code;
}

