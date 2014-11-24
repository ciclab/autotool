#ifndef _INSTRUCTION_BASE_H_
#define _INSTRUCTION_BASE_H_

#include <string>
#include <vector>
#include <functional>
#include <boost/shared_ptr.hpp>

#include "pipeline_base.h"
#include "stage_base.h"

typedef void Tfunc();

class InstructionBase
{
 public:
	virtual ~InstructionBase();

	virtual bool Init();

	/*
	 * called inside Init, executed first
	 */
	virtual bool BeforeInit();

	/*
	 * called in side Init, executed last
	 */
	virtual bool AfterInit();

	/*
	 * correspond (do ...) statement of each instruction
	 * return true if executed success
	 */
	virtual bool Do();

 protected:
	boost::shared_ptr<StageBase> mStage;
	std::vector<boost::shared_ptr<PipelineBase> > mPipeline;
	std::vector<std::function<Tfunc> > mpDoList;
};

#endif
