#include "mem_base.h"

#include <vector>
#include <glog/logging.h>

using namespace std;

const string MemoryBase::cName = "MemoryBase";
const uint MemoryBase::cSize = 0;

bool MemoryBase::BeforeRead()
{
  LOG(INFO) << "do nothing";

  return true;
}

bool MemoryBase::AfterRead()
{
  LOG(INFO) << "do nothing";

  return true;
}

bool MemoryBase::BeforeWrite()
{
  LOG(INFO) << "do nothing";

  return true;
}

bool MemoryBase::AfterWrite()
{
  LOG(INFO) << "do nothing";

  return true;
}

bool MemoryBase::Read(uint offset, uint size,
		      vector<char>& value)
{
  if (!CheckAddressValidity(offset, size))
    {
      LOG(ERROR) << "Read address invalid, offset: " << offset <<
	" size: " << size;
      return false;
    }

  value.assign(mContent.begin() + offset,
	       mContent.begin() + offset + size);

  return true;
}

bool MemoryBase::Write(uint offset, uint size,
		       const vector<char>& value)
{
  if (!CheckAddressValidity(offset, size))
    {
      LOG(ERROR) << "Write address invalid, offset: " << offset <<
	" size: " << size;

      return false;
    }

  if (value.size() < cSize)
    {
      LOG(ERROR) << "length of value(" << value.size() << ")\
is less than " << size;
      return false;
    }

  for (int i = 0; i < cSize; ++i)
    {
      mContent[i + offset] = value[i];
    }

  return true;
}

bool MemoryBase::CheckAddressValidity(uint offset, uint size)
{
  if (offset + size > cSize)
    {
      return false;
    }

  return true;
}

bool MemoryBase::Init()
{
  LOG(INFO) << "do nothing";
  return true;
}
