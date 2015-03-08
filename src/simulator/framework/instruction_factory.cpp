/*
 * instruction_factory.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: q
 */

#include "instruction_factory.h"

boost::shared_ptr<InstructionBase> NewInstruction(int instructionId)
{
	return boost::shared_ptr<InstructionBase>(NULL);
}

