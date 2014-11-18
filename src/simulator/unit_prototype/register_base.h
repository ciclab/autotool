#ifndef _REGISTER_BASE_H_
#define _REGISTER_BASE_H_

#include <vector>
#include <string>
#include <functional>
#include <boost/multiprecision/gmp.hpp>

class RegisterBase
{
public:
	virtual ~RegisterBase();

	virtual bool Init();

	// called before Read is called. If return false,
	// Read won't be called
	virtual bool BeforeRead();

	// called after Read is called.
	virtual bool AfterRead();

	// If reutrn false, Write won't be called
	virtual bool BeforeWrite();

	// called after Write
	virtual bool AfterWrite();

	// read a register into value, value will be resized to cWidth
	bool Read(uint offset, boost::multiprecision::mpz_int& value);

	// write a register
	bool Write(uint offset, const boost::multiprecision::mpz_int& value);
protected:
	std::vector<boost::multiprecision::mpz_int> mContent;
	int mWidth;

	bool CheckAddressValidity(uint offset);
};

#endif
