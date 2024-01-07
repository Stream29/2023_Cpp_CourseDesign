#include "RationalNumber.h"

namespace math
{
	RationalNumber::RationalNumber(const BigInteger& value)
	{
		if(value.positivity())
		{
			numerator = value;
		}
		else
		{
			numerator = -value;
			positivity = true;
		}
	}
	RationalNumber::RationalNumber(const BigInteger& _numerator,const BigInteger& _denominator)
	{
		if(_denominator == 0)
		{
			throw exception::DividedByZeroException();
		}
		if(_numerator.positivity())
		{
			numerator = _numerator;
		}
		else
		{
			numerator = -_numerator;
			positivity = !positivity;
		}
		if(_denominator.positivity())
		{
			denominator = _denominator;
		}
		else
		{
			denominator = -_denominator;
			positivity = !positivity;
		}
		reduce();
	}
	
	void RationalNumber::reduce()
	{
		const BigInteger __gcd = gcd(numerator,denominator);
		numerator = numerator / __gcd;
		denominator = denominator / __gcd;
	}
	
	bool operator <(const RationalNumber& a,const RationalNumber& b)
	{
		return a.numerator*b.denominator - b.numerator*a.denominator < 0;
	}
	bool operator >(const RationalNumber& a,const RationalNumber& b)
	{
		return b < a;
	}
	RationalNumber RationalNumber::operator -() const
	{
		RationalNumber result(*this);
		result.positivity = !result.positivity;
		return result;
	}
	RationalNumber RationalNumber::reciprocal() const
	{
		RationalNumber result(*this);
		std::swap(result.numerator,result.denominator);
		return result;
	}
	RationalNumber& RationalNumber::operator +=(const RationalNumber& bi)
	{
		return *this = *this + bi;
	}
	RationalNumber operator +(const RationalNumber& a,const RationalNumber& b)
	{
		int base_a = a.positivity ? 1 : -1;
		int base_b = b.positivity ? 1 : -1;
		return RationalNumber(
			a.numerator*b.denominator*base_a + b.numerator*a.denominator*base_b,
			a.denominator * b.denominator);
	}
	RationalNumber operator -(const RationalNumber& a,const RationalNumber& b)
	{
		return a + (-b);
	}
	std::string RationalNumber::toString() const
	{
		const std::string _positivity = positivity ? "" : "-";
		if(denominator == 1)
		{
			return _positivity + numerator.toString();
		}
		return _positivity + numerator.toString() + "/" + denominator.toString();
	}
	std::ostream& operator <<(std::ostream& os,const RationalNumber& bi)
	{
		return os << bi.toString();
	}
	bool operator ==(const RationalNumber& a,const RationalNumber& b)
	{
		return a.numerator==b.numerator && a.denominator==b.denominator;
	}
	RationalNumber& RationalNumber::operator *=(const RationalNumber& num)
	{
		return *this = *this * num;
	}
	RationalNumber operator *(const RationalNumber& a,const RationalNumber& b)
	{
		int positivity = !(!a.positivity^!b.positivity) ? 1 : -1;
		return RationalNumber(a.numerator*b.numerator*positivity,a.denominator*b.denominator);
	}
	RationalNumber operator /(const RationalNumber& a,const RationalNumber& b)
	{
		return a * b.reciprocal();
	}
}
