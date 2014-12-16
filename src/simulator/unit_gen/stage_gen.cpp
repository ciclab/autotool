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
	string name = "Stage";

	string enumList;
	string lastStageName;
	for (int i = 0; i < (int)stage.size(); ++i)
	{
		if (i != 0)
		{
			enumList += ", ";
		}

		lastStageName = stage[i].get_name();
		enumList += lastStageName;
		if (i == 0)
		{
			enumList += "= 0";
		}
	}
        
                  string inStageFunCodeStr;
                  inStageFunCodeStr = boost::lexical_cast<string>(
                          boost::format(
                          "bool InStage(StageList stage)\n"
                          "{\n"
                          "return stage == mStage;\n"
                          "}\n"
                          ));

	string code;

	code = boost::lexical_cast<string>(
			boost::format(
					"class T%1%: public StageBase"
					"{"
					"public:"
					"enum StageList {%2%};"
					"bool Init() override"
					"{"
					"LOG(INFO) << \"Init stage: %1%\";"
					"mStage = StageList(0);"
					"return true;"
					"};"
					"bool NextStage() override"
					"{"
					"if (mStage != %3%)"
					"{"
					"int tmp = (int)mStage + 1;"
					"mStage = StageList(tmp);"
					"return true;"
					"}"
					"return false;"
					"};"
                                                                                          "%4%"
					"StageList mStage;"
					"};") % name % enumList % lastStageName % inStageFunCodeStr);

	return code;
}

