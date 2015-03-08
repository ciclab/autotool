#include "type_base.h"

#include <glog/logging.h>

const std::string TypeBase::mName = "TypeBase";
const int TypeBase::mWidth = 0;

TypeBase::~TypeBase()
{
	LOG(INFO) << "do nothing";
}
