#include "Test.h"

namespace test
{
	void show_wait(std::string_view content,int y)
	{
		auto temp = view::TextView(std::string(content),{30,(short)y},BACKGROUND_GREEN | BACKGROUND_RED );
		temp.print();
//		console::next();
		temp.clear();
	}
	void show(std::string_view content,int y)
	{
		auto temp = view::TextView(std::string(content),{30,(short)y},BACKGROUND_GREEN | BACKGROUND_RED );
		temp.print();
	}
	
	std::string toString(std::string_view v)
	{
		return toString(std::string(v));
	}
	std::string toString(const std::string& v)
	{
		std::stringstream ss;
		ss << std::quoted(v);
		return ss.str();
	}
	std::string toString(const math::RationalNumber& v)
	{
		return v.toString();
	}
	std::string currentTime()
	{
		std::stringstream ss;
		std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
		std::time_t t1 = std::chrono::system_clock::to_time_t(a);
		ss << std::put_time(localtime(&t1),"%Y-%m-%d %H:%M:%S");
		std::string str1 = ss.str();
		return str1;
	}
}
