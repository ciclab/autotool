#ifndef _STAGE_BASE_H
#define _STAGE_BASE_H

#include <string>
#include <vector>

template<typename Tstage>
class StageBase
{
public:
	virtual ~StageBase();

	// turn into next stage, reutrn false if no next stage
	virtual bool NextStage();

	// Init
	virtual bool Init();

};

#endif
