#ifndef _INSTRUCTION_BASE_H_
#define _INSTRUCTION_BASE_H_

#include <string>
#include <vector>
#include <functional>
#include <boost/shared_ptr.hpp>
#include <boost/multiprecision/gmp.hpp>

#include "pipeline_base.h"
#include "stage_base.h"

typedef void Tfunc();

class SimulatorBase;
class StageBase;

class InstructionBase {
public:
	virtual ~InstructionBase();

	virtual bool Init(SimulatorBase* pSimulatorBase,
			boost::shared_ptr<StageBase> pStageBase);

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

	/*
	 * initilize internal variable 
	 */
	virtual bool InitVariable(const char* bianry,
			const boost::multiprecision::mpz_int& nowPc);

	/*
	 * called before InitVariable is called
	 * if return false, InitVariable will not executed
	 */
	virtual bool BeforeInitVariable();

	/*
	 * called after InitVariable is called
	 */
	virtual bool AfterInitVariable();

	/*
	 * go to next stage
	 * return false if there is no next stage left
	 */
	virtual bool NextStage();

	boost::shared_ptr<StageBase> mpStage;
//	std::vector<boost::shared_ptr<PipelineBase> > mPipeline;
//	std::vector<std::function<Tfunc> > mpDoList;
	SimulatorBase* mpSimulator = NULL;
};

#endif
