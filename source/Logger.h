#ifndef LOG_H
#define LOG_H

#include <fstream>
#include "Test.h"

namespace util
{
	static std::ofstream logger {"log.txt",std::ios::app | std::ios::out};
	
	template <typename...T>
	void log(const T&... args)
	{
		((logger << args << ' '),...) << std::endl;
	}
};

#endif
