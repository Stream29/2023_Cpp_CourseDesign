#include "Position.h"

namespace console
{
	Position::Position(axis_type _x,axis_type _y)
	{
		x = _x;
		y = _y;
	}
	Position::Position(COORD coord)
	{
		x = coord.X;
		y = coord.Y;
	}
	bool Position::operator <(const Position& p) const
	{
		if(y != p.y)
		{
			return y < p.y;
		}
		return x < p.x;
	}
	
	Position Position::operator +(const Position& p) const
	{
		return {static_cast<short>(x+p.x),static_cast<short>(y+p.y)};
	}
}
