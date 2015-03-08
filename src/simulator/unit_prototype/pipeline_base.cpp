#include "pipeline_base.h"

#include <glog/logging.h>

const std::string mName = "PipelineBase";

PipelineBase::~PipelineBase()
{
	LOG(INFO) << "do nothing";
}

void PipelineBase::Freeze()
{
	LOG(INFO) << "do nothing";
}

void PipelineBase::Flush()
{
	LOG(INFO) << "do nothing";
}

bool PipelineBase::Init()
{
	LOG(INFO) << "do nothing";

	return true;
}
