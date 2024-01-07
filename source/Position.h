#ifndef POSITION_H
#define POSITION_H

#include <windows.h>

namespace console
{
	struct Position {
		using axis_type = short;
		axis_type x;
		axis_type y;
		Position() = default;
		Position(axis_type _x,axis_type _y);
		Position(COORD coord);
		bool operator <(const Position& p) const;
		Position operator +(const Position& p) const;
	};
}

#endif
