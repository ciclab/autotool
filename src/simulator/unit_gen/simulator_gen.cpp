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
		const vector<string>& registerFile, const vector<string>& pipeline)
{
                   vector<string> readCodeStrVec;
                   vector<string> writeCodeStrVec;
                   
	/*
	 * step 1. generate function unit declatation and init code
	 */
	string functionUnitDeclarationCode;
	string functionUnitInitCode;
	{
		functionUnitDeclarationCode += "protected:\n";
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
                                                      readCodeStrVec.push_back(
                                                      lexical_cast<string>(
                                                      format("bool Read%1% (uint offset, uint size, std::vector<char>& value)\n"
                                                      "{\n"
                                                      "if (%1%.get() == NULL)\n"
                                                      "{\n"
                                                      "return false;\n"
                                                      "}\n"
                                                      "if (%1%->Read(offset, size, value))\n"
                                                      "{\n"
                                                      "return false;\n"
                                                      "}\n"
                                                      "return true;\n"
                                                      "}\n") % i
                                                      )
                                                      );
                                                      
                                                      writeCodeStrVec.push_back(
                                                      lexical_cast<string>(
                                                      format("bool Write%1% (uint offset, uint size, const std::vector<char>& value)\n"
                                                      "{\n"
                                                      "if (%1%.get() == NULL)\n"
                                                      "{\n"
                                                      "return false;\n"
                                                      "}\n"
                                                      "if (%1%->Write(offset, size, value))\n"
                                                      "{\n"
                                                      "return false;\n"
                                                      "}\n"
                                                      "return true;\n"
                                                      "}\n") % i
                                                      ));
		}
	}

	{
		/*
		 * generate code for register declaration and initialization in simulator
		 */
		functionUnitDeclarationCode += "protected:\n";
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
                                                      readCodeStrVec.push_back(
                                                      lexical_cast<string>(
                                                      format("bool Read%1% (uint offset, boost::multiprecision::mpz_int& value)\n"
                                                      "{\n"
                                                      "if (%1%.get() == NULL)\n"
                                                      "{\n"
                                                      "return false;\n"
                                                      "}\n"
                                                      "if (%1%->Read(offset, value))\n"
                                                      "{\n"
                                                      "return false;\n"
                                                      "}\n"
                                                      "return true;\n"
                                                      "}\n") % i
                                                      )
                                                      );
                                                      
                                                      writeCodeStrVec.push_back(
                                                      lexical_cast<string>(
                                                      format("bool Write%1% (uint offset, const boost::multiprecision::mpz_int& value)\n"
                                                      "{\n"
                                                      "if (%1%.get() == NULL)\n"
                                                      "{\n"
                                                      "return false;\n"
                                                      "}\n"
                                                      "if (%1%->Write(offset, value))\n"
                                                      "{\n"
                                                      "return false;\n"
                                                      "}\n"
                                                      "return true;\n"
                                                      "}\n") % i
                                                      ));
                        
		}
	}

                  {
                            /*
                             *  generate code for pipeline initialization
                             */
                           functionUnitDeclarationCode += "protected:\n";
                           for (auto i: pipeline)
                           {
                                    functionUnitDeclarationCode += lexical_cast<string>(
                                            format("boost::shared_ptr<PipelineBase> %1%;\n") % i);
                                    functionUnitInitCode += lexical_cast<string>(
                                            format("%1%.reset(new T%1%);\n"
                                            "if (!%1%->Init())\n"
                                            "{\n"
                                            "return false;\n"
                                            "}\n") % i);
                           }
                  }
        
                  string readCodeStr;
                  for (auto i: readCodeStrVec)
                  {
                      readCodeStr.append(i);
                  }
                  
                  string writeCodeStr;
                  for (auto i: writeCodeStrVec)
                  {
                      writeCodeStr.append(i);
                  }
	/*
	 * output class definition code for simulator
	 */
	string code = lexical_cast<string>(
			format("class TSimulator: public SimulatorBase{\n"
					"%1%\n"
					"public:"
					"bool Init() override{\n"
					"if (!BeforeInit())"
					"{"
					"return false;"
					"}\n"
					"%2%\n"
					"if (!AfterInit())"
					"{"
					"return false;"
					"}\n"
					"return true;\n"
					"}"
                                                                                          "%3%"
                                                                                          "%4%"
					"};") % functionUnitDeclarationCode % functionUnitInitCode % readCodeStr % writeCodeStr);

	return code;
}

