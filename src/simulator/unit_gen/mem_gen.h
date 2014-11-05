#ifndef _MEM_GEN_H_
#define _MEM_GEN_H_

#include <string>

#include "include/memory.h"

class MemGen
{
public:
	/*
	 *  generate C++ code in string for memory class
	 * @param memory ir holding info about memory
	 *
	 * @return C++ code generated
	 */
	std::string GenMemCStr(Memory& memory);
};

#endif
