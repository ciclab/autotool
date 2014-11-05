#include "mem_base.h"

#include <vector>
#include <algorithm>
#include <glog/logging.h>

using namespace std;

//const string MemoryBase::cName = "MemoryBase";
//const uint MemoryBase::cSize = 0;

MemoryBase::~MemoryBase()
{
	LOG(INFO)<< "do nothing";
}

bool MemoryBase::BeforeRead()
{
	LOG(INFO)<< "do nothing";

	return true;
}

bool MemoryBase::AfterRead()
{
	LOG(INFO)<< "do nothing";

	return true;
}

bool MemoryBase::BeforeWrite()
{
	LOG(INFO)<< "do nothing";

	return true;
}

bool MemoryBase::AfterWrite()
{
	LOG(INFO)<< "do nothing";

	return true;
}

bool MemoryBase::Read(uint offset, uint size, vector<char>& value)
{
	if (!CheckAddressValidity(offset, size))
	{
		LOG(ERROR)<< "Read address invalid, offset: " << offset <<
		" size: " << size;
		return false;
	}

	value.assign(mContent.begin() + offset,
			mContent.begin() + offset + size);

	return true;
}

bool MemoryBase::Write(uint offset, uint size, const vector<char>& value)
{
	if (!CheckAddressValidity(offset, size))
	{
		LOG(ERROR)<< "Write address invalid, offset: " << offset <<
		" size: " << size;

		return false;
	}

	if (value.size() < size)
	{
		LOG(ERROR) << "size of value is less than size, value.size(): " << value.size() <<
				" size: " << size;
		return false;
	}

	copy(value.begin(), value.begin() + size, mContent.begin() + offset);

	return true;
}

bool MemoryBase::CheckAddressValidity(uint offset, uint size)
{
	return offset  + size <= mContent.size();
}

bool MemoryBase::Init()
{
	LOG(INFO)<< "do nothing";
	return true;
}
