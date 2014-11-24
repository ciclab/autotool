/*
 * InstructionFactory.h
 *
 *  Created on: Nov 24, 2014
 *      Author: q
 */

#ifndef INSTRUCTIONFACTORY_H_
#define INSTRUCTIONFACTORY_H_

#include <boost/shared_ptr.hpp>

#include "instruction_base.h"

class InstructionFactoryBase
{
public:
	virtual ~InstructionFactoryBase();

	/*
	 * given id of instruction, return a pointer to a new allocated instruction object
	 */
	virtual boost::shared_ptr<InstructionBase> NewInstruction(int instructionId);
};


#endif /* INSTRUCTIONFACTORY_H_ */
