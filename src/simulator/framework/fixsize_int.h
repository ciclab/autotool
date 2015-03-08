/*
 * FixInt.h
 *
 *  Created on: 2014-11-5
 *      Author: q
 */

#ifndef FIXINT_H_
#define FIXINT_H_

#include <boost/multiprecision/gmp.hpp>

class FixsizeInt
{
public:
	bool Init(int len);
	boost::multiprecision::mpz_int value;
private:
	void round();
	int length;
};


#endif /* FIXINT_H_ */
