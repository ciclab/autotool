#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include "mem_base.h"
#include "type_base.h"
#include "stage_base.h"
#include "pipeline_base.h"
#include "register_base.h"
#include "instruction_base.h"

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <vector>

typedef boost::shared_ptr<MemoryBase> MemoryBasePtr;
typedef boost::shared_ptr<RegisterBase> RegisterBasePtr;
typedef boost::shared_ptr<PipelineBase> PipelineBasePtr;
typedef boost::shared_ptr<InstructionBase> InstructionBasePtr;

class SimulatorBase
{
public:
	SimulatorBase();

	virtual ~SimulatorBase();

	// initialize internal data
	virtual bool Init();

	// called in Init, executed first
	virtual bool BeforeInit();

	// called in Init, executed last
	virtual bool AfterInit();

	// called in Init, executed last

	// load binary file, called before run
	virtual bool LoadBinaryFile(const std::string& filePath);

	/*
	 * called in LoadBinaryFile(), fist to be executed
	 */
	virtual bool BeforeLoadBinaryFile(const std::string& filePath);

	/*
	 * called in LoadBinaryFile(), last to be executed
	 */
	virtual bool AfterLoadBinaryFile(const std::vector<char>& content);

	// run simulator
	virtual void Run();
private:
	// map from name to function unit(memory, stage...)
//	std::unordered_map<std::string, MemoryBasePtr> mName2FunctionUnit;

	// map from register file name to register file instance pointer
//	std::unordered_map<std::string, RegisterBasePtr> mName2RegisterFilePtr;

	std::vector<PipelineBasePtr> pipelineBasePtr;

	// pointer to instruction instance on each stage
	std::vector<InstructionBasePtr> instructionBasePtrVec;
};

#endif
