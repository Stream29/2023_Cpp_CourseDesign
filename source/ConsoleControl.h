#ifndef CONSOLECONTROL_H
#define CONSOLECONTROL_H

#include "Position.h"
#include <string>
#include <sstream>
#include <windows.h>
#include "Position.h"
#include <conio.h>
#include "Keys.h"
#include <variant>
#include <optional>
#include "Invoke.h"


namespace console
{
	auto std_handle();
	bool setTitle(std::string title);
	bool setFeature(WORD feature);
	bool setPosition(const Position& pos);
	Position getPosition();
	void setConsoleSize(Position size);
	int next();
	void clear();
}

#endif
