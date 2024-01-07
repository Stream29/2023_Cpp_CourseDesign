#ifndef VALUEHISTORY_H
#define VALUEHISTORY_H

#include <map>
#include <string>
#include "Mathematical.h"

namespace status
{
	class ValueHistory : public std::map<std::string,math::RationalNumber>
	{
		using std::map<std::string,math::RationalNumber>::map;
	public:
		bool has(key_type key) const;
	};
}

#endif
