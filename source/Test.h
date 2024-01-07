#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include "AllViews.h"
#include <string_view>
#include <list>
#include "Context.h"
#include <chrono>

#define varName(x) std::string(#x)
#define fmt(x) (varName(x)+std::string(" = ")+test::toString(x))
#define nowFunc __PRETTY_FUNCTION__
#define nowTime test::currentTime()
#define nowInfo (std::string(__FILE__)+" : "+nowFunc+" at line "+std::to_string(__LINE__))

namespace test
{
	void show_wait(std::string_view content,int y);
	void show(std::string_view content,int y);
	
	std::string currentTime();
	
	template <typename T>
	std::string toString(const T& v)
	{
		return std::to_string(v);
	}
	std::string toString(const std::string& v);
	std::string toString(std::string_view v);
	std::string toString(const math::RationalNumber& v);
	template <typename T>
	std::string toString(const std::vector<T>& v)
	{
		std::stringstream ss;
		ss << '{';
		for(auto e : v)
		{
			ss << toString(e) << ',';
		}
		ss << '}';
		return ss.str();
	}
	template <typename T>
	std::string toString(const std::list<T>& v)
	{
		std::stringstream ss;
		ss << '{';
		for(auto e : v)
		{
			ss << toString(e) << ',';
		}
		ss << '}';
		return ss.str();
	}
}

#endif
