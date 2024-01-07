#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "Exceptions.h"

namespace math
{
	class BigInteger
	{
	private:
		std::vector<long long> data;
		constexpr static long long BASE = 1e9;
		constexpr static int BASE_LENGTH = 9;
		void cutFrontZero();
		void unify();
		void sortOut();
		BigInteger& leftMove(int distance);
	public:
		BigInteger() = default;
		BigInteger(std::string number);
		BigInteger(long long number);
		bool positivity() const;
		friend bool operator <(const BigInteger& a,const BigInteger& b);
		friend bool operator >(const BigInteger& a,const BigInteger& b);
		BigInteger operator -() const;
		BigInteger& operator +=(const BigInteger& bi);
		friend BigInteger operator +(const BigInteger& a,const BigInteger& b);
		friend BigInteger operator -(const BigInteger& a,const BigInteger& b);
		std::string toString() const;
		friend std::ostream& operator <<(std::ostream& os,const BigInteger& bi);
		friend bool operator ==(const BigInteger& a,const BigInteger& b);
		BigInteger& operator *=(const int time);
		friend BigInteger operator *(const BigInteger& bi,const int time);
		friend BigInteger operator *(const int time,const BigInteger& bi);
		friend BigInteger operator *(const BigInteger& a,const BigInteger& b);
		friend BigInteger operator /(const BigInteger& a,const long long b);
		friend BigInteger operator /(const BigInteger& a,const BigInteger& b);
		friend BigInteger operator %(const BigInteger& a,const BigInteger& b);
	};
	
	BigInteger gcd(const BigInteger& a,const BigInteger& b);
	auto operator ""_bi(unsigned long long number);
	auto operator ""_bi(char const * const text,std::size_t size);
}

#endif
