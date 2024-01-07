#include "BigInteger.h"

namespace math
{
	void BigInteger::cutFrontZero()
	{
		while(!data.empty() && data.back()==0)
		{
			data.pop_back();
		}
		if(data.empty())
		{
			data.push_back(0);
		}
	}
	
	void BigInteger::unify()
	{
		if(!data.empty())
		{
			for(size_t i = 0;i < data.size()-1;i ++)
			{
				if(data[i]*positivity() < 0)
				{
					//data[i] has wrong positivity
					data[i] += BASE * positivity();
					data[i+1] -= 1 * positivity();
				}
			}
		}
		cutFrontZero();
	}
	
	void BigInteger::sortOut()
	{
		for(size_t index = 0;index < data.size()-1;index ++)
		{
			data[index+1] += data[index] / BASE;
			data[index] %= BASE;
		}
		while(data.back() >= BASE)
		{
			data.push_back(data.back()/BASE);
			data[data.size()-2] %= BASE;
		}
		cutFrontZero();
		unify();
	}
	BigInteger& BigInteger::leftMove(int distance)
	{
		for(int i = 0;i < distance;i ++)
		{
			data.insert(data.begin(),0);
		}
		return *this;
	}
	
	BigInteger::BigInteger(std::string number)
	{
		if(number.front() == '-')
		{
			new (this) BigInteger(number.substr(1,number.size()-1));
			for(auto& n : data)
			{
				n = -n;
			}
			return;
		}
		while(number.size() > (size_t)BASE_LENGTH)
		{
			data.push_back(
				std::stoll(
					number.substr(number.size()-BASE_LENGTH,BASE_LENGTH)));
			number = number.substr(0,number.size()-BASE_LENGTH);
		}
		data.push_back(std::stoll(number));
		cutFrontZero();
	}
	
	BigInteger::BigInteger(long long number):
	BigInteger(std::to_string(number))
	{}
	
	bool BigInteger::positivity() const
	{
		if(data.empty())
		{
			return true;
		}
		return data.back()<0 ? false : true;
	}
	
	bool operator <(const BigInteger& a,const BigInteger& b)
	{
		if(a.positivity() != b.positivity())
		{
			return !a.positivity();
		}
		if(a.data.size() != b.data.size())
		{
			return (a.data.size()<b.data.size()) ^ !a.positivity();
		}
		for(int i = a.data.size()-1;i >= 0;i --)
		{
			if(a.data[i] != b.data[i])
			{
				return (a.data[i]<b.data[i]) ^ !a.positivity();
			}
		}
		return false;
	}
	
	bool operator >(const BigInteger& a,const BigInteger& b)
	{
		if(a.positivity() != b.positivity())
		{
			return !b.positivity();
		}
		if(a.data.size() != b.data.size())
		{
			return (a.data.size()>b.data.size()) ^ !a.positivity();
		}
		for(int i = a.data.size()-1;i >= 0;i --)
		{
			if(a.data[i] != b.data[i])
			{
				return (a.data[i]>b.data[i]) ^ !a.positivity();
			}
		}
		return false;
	}
	
	BigInteger BigInteger::operator -() const
	{
		BigInteger result(*this);
		for(auto& n : result.data)
		{
			n = -n;
		}
		return result;
	}
	
	BigInteger& BigInteger::operator +=(const BigInteger& bi)
	{
		data.resize(std::max(data.size(),bi.data.size()));
		for(size_t index = 0;index < bi.data.size();index ++)
		{
			//proved index available for this and bi
			data[index] += bi.data[index];
		}
		sortOut();
		return *this;
	}
	
	BigInteger operator +(const BigInteger& a,const BigInteger& b)
	{
		BigInteger result;
		result += a;
		result += b;
		return result;
	}
	
	BigInteger operator -(const BigInteger& a,const BigInteger& b)
	{
		return a + (-b);
	}
	
	std::string BigInteger::toString() const
	{
		std::stringstream result;
		if(data.empty())
		{
			return "0";
		}
		result << data.back();
		for(auto riter = data.crbegin()+1;riter < data.crend();riter ++)
		{
			result << std::setw(BASE_LENGTH) << std::setfill('0') << std::right;
			result << llabs(*riter);
		}
		return result.str();
	}
	
	std::ostream& operator <<(std::ostream& os,const BigInteger& bi)
	{
		os << bi.toString();
		return os;
	}
	
	bool operator ==(const BigInteger& a,const BigInteger& b)
	{
		return a.data == b.data;
	}
	
	BigInteger& BigInteger::operator *=(const int time)
	{
		for(auto& n: data)
		{
			n *= time;
		}
		sortOut();
		return *this;
	}
	
	BigInteger operator *(const BigInteger& bi,const int time)
	{
		BigInteger result(bi);
		result *= time;
		return result;
	}
	
	BigInteger operator *(const int time,const BigInteger& bi)
	{
		return bi * time;
	}
	BigInteger operator *(const BigInteger& a,const BigInteger& b)
	{
		BigInteger result;
		for(size_t i = 0;i < b.data.size();i ++)
		{
			result += (a*b.data[i]).leftMove(i);
		}
		return result;
	}
	
	BigInteger operator /(const BigInteger& a,const long long b)
	{
		if(a.data.empty())
		{
			return BigInteger(0);
		}
		BigInteger result = a;
		for(size_t i = result.data.size()-1;i > 0;i --)
		{
			result.data[i-1] += (result.data[i]%b) * BigInteger::BASE;
			result.data[i] /= b;
		}
		result.data[0] /= b;
		return result;
	}
	
	BigInteger operator /(const BigInteger& a,const BigInteger& b)
	{
		if(a < BigInteger(0))
		{
			return -(-a/b);
		}
		if(b < BigInteger(0))
		{
			return -(a/-b);
		}
		if(b == BigInteger(0))
		{
			throw exception::DividedByZeroException();
		}
		if(a < b)
		{
			return BigInteger(0);
		}
		BigInteger result(1);
		BigInteger base(b);
		while(a > base*2)
		{
			base *= 2;
			result *= 2;
		}
		result += (a-base) / b;
		return result;
	}
	
	BigInteger operator %(const BigInteger& a,const BigInteger& b)
	{
		return a - a/b*b;
	}
	
	BigInteger gcd(const BigInteger& a,const BigInteger& b)
	{
		if(b > a)
		{
			return gcd(b,a);
		}
		if(b == 0)
		{
			return 1;
		}
		if(a%b == 0)
		{
			return b;
		}
		return gcd(b,a%b);
	}
	
	auto operator ""_bi(unsigned long long number)
	{
		return BigInteger(number);
	}
	auto operator ""_bi(char const * const text,std::size_t size)
	{
		return BigInteger(std::string(text,size));
	}
}
