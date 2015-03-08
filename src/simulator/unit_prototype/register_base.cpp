#include "register_base.h"

#include <algorithm>
#include <glog/logging.h>
#include <vector>
#include <string>

using namespace std;
using namespace boost::multiprecision;

RegisterBase::~RegisterBase()
{
	LOG(INFO)<< "do nothing";
}

bool RegisterBase::BeforeRead()
{
	LOG(INFO)<< "do nothing";
	return true;
}

bool RegisterBase::AfterRead()
{
	LOG(INFO)<< "do nothing";
	return true;
}

bool RegisterBase::BeforeWrite()
{
	LOG(INFO)<< "do nothing";
	return true;
}

bool RegisterBase::AfterWrite()
{
	LOG(INFO)<< "do nothing";
	return true;
}

bool RegisterBase::Read(uint offset, mpz_int& value)
{
	if (!CheckAddressValidity(offset))
	{
		LOG(ERROR)<< "Read address invalid: " << offset;
	}

	value = mContent[offset];

	return true;
}

bool RegisterBase::Write(uint offset, const mpz_int& value)
{
	if (!CheckAddressValidity(offset))
	{
		LOG(ERROR)<< "Write address invalid: " << offset;
	}

	mContent[offset] = value;

	return true;
}

bool RegisterBase::CheckAddressValidity(uint offset)
{
	return offset < mContent.size();
}

bool RegisterBase::Init()
{
	LOG(INFO)<< "do nothing";
	return true;
}
