/*
 * simulator_gen.h
 *
 *  Created on: Nov 18, 2014
 *      Author: q
 */

#ifndef SIMULATOR_GEN_H_
#define SIMULATOR_GEN_H_

#include <string>
#include <vector>

class SimulatorGen
{
public:
	std::string GenSimulatorCStr(const std::vector<std::string>& memory,
			const std::vector<std::string>& registerFile);
};

#endif /* SIMULATOR_GEN_H_ */
