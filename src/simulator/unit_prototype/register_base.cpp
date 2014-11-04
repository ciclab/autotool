#include "register_base.h"

#include <algorithm>
#include <glog/logging.h>
#include <vector>
#include <string>

using namespace std;

const string RegisterBase::cName = "RegisterBase";
const uint RegisterBase::cWidth = 0;
const uint RegisterBase::cSize = 0;

bool RegisterBase::BeforeRead()
{
  LOG(INFO) << "do nothing";
  return true;
}

bool RegisterBase::AfterRead()
{
  LOG(INFO) << "do nothing";
  return true;
}

bool RegisterBase::BeforeWrite()
{
  LOG(INFO) << "do nothing";
  return true;
}

bool RegisterBase::AfterWrite()
{
  LOG(INFO) << "do nothing";
  return true;
}

bool RegisterBase::Read(uint offset, vector<char>& value)
{
  if (!CheckAddressValidity(offset))
    {
      LOG(ERROR) << cName << "Read address invalid: " << 
	offset;
    }

  value.assign(mContent.begin() + offset * cWidth, 
	       mContent.begin() + offset * (1 + cWidth));

  return true;
}

bool RegisterBase::Write(uint offset, const vector<char>& value)
{
  if (!CheckAddressValidity(offset))
    {
      LOG(ERROR) << cName << "Write address invalid: " <<
	offset;
    }

  if (value.size() < cWidth)
    {
      LOG(ERROR) << "Size of value write to register is less than\
 expected( " << cWidth << "): " << value.size();
      return false;
    }

  for (int i = 0; i < cWidth; ++i)
    {
      mContent[offset * cWidth + i] = value[i];
    }

  return true;
}

bool RegisterBase::CheckAddressValidity(uint offset)
{
  if ((long long)offset * cWidth >= cSize)
    {
      return false;
    }

  return true;
}

bool RegisterBase::Init()
{
  LOG(INFO) << "RegisterBase initialized, clear all content to\
zero";

  fill(mContent.begin(), mContent.end(), 0);

  return true;
}
