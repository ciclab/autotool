#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include "../unit_prototype/mem_base.h"
#include "../unit_prototype/type_base.h"
#include "../unit_prototype/stage_base.h"
#include "../unit_prototype/pipeline_base.h"
#include "../unit_prototype/register_base.h"
#include "../unit_prototype/instruction_base.h"

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

typedef std::shared_ptr<MemoryBase> MemoryBasePtr;
typedef std::shared_ptr<RegisterBase> RegisterBasePtr;
typedef std::shared_ptr<PipelineBase> PipelineBasePtr;
typedef std::shared_ptr<InstructionBase> InstructionBasePtr;

class Simulator
{
 public:
  Simulator();

  ~Simulator();

  // initialize internal data
  virtual bool Init();

  // load binary file, called before run
  virtual bool LoadBinaryFile(const std::string& filePath);

  // run simulator
  virtual void Run();
 private:
  // map from memory name to pointer to memory instance
  std::unordered_map<std::string, MemoryBasePtr> mName2MemoryPtr;

  // map from register file name to register file instance pointer
  std::unordered_map<std::string, RegisterBasePtr> mName2RegisterFilePtr;

  std::vector<PipelineBasePtr> pipelineBasePtr;

  // pointer to instruction instance on each stage
  std::vector<InstructionBasePtr> instructionBasePtrVec;
  
 private:
  Simulator(const Simulator& Simulator);
  Simulator& operator=(const Simulator& Simulator);
  Simulator& operator=(const Simulator&& Simulator);
};

#endif
