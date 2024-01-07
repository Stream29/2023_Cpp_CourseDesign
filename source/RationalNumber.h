#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include "BigInteger.h"
#include "Exceptions.h"

namespace math
{
	class RationalNumber 
	{
	public:
		bool positivity = true;
		BigInteger numerator = 1;
		BigInteger denominator = 1;
		RationalNumber() = default;
		RationalNumber(const BigInteger& value);
		RationalNumber(const BigInteger& _numerator,const BigInteger& _denominator);
		void reduce();
		friend bool operator <(const RationalNumber& a,const RationalNumber& b);
		friend bool operator >(const RationalNumber& a,const RationalNumber& b);
		RationalNumber operator -() const;
		RationalNumber reciprocal() const;
		RationalNumber& operator +=(const RationalNumber& bi);
		friend RationalNumber operator +(const RationalNumber& a,const RationalNumber& b);
		friend RationalNumber operator -(const RationalNumber& a,const RationalNumber& b);
		std::string toString() const;
		friend std::ostream& operator <<(std::ostream& os,const RationalNumber& bi);
		friend bool operator ==(const RationalNumber& a,const RationalNumber& b);
		RationalNumber& operator *=(const RationalNumber& num);
		friend RationalNumber operator *(const RationalNumber& a,const RationalNumber& b);
		friend RationalNumber operator /(const RationalNumber& a,const RationalNumber& b);
	};
}

#endif
