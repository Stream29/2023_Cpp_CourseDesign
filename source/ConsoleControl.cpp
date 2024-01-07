#include "ConsoleControl.h"

namespace console
{
	auto std_handle()
	{
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}
	
	bool setTitle(std::string title)
	{
		return SetConsoleTitle(title.data());
	}
	
	bool setFeature(WORD feature)
	{
		return SetConsoleTextAttribute(std_handle(),feature);
	}
	
	bool setPosition(const Position& pos)
	{
		return SetConsoleCursorPosition(std_handle(),{pos.x,pos.y});
	}
	
	Position getPosition()
	{
		CONSOLE_SCREEN_BUFFER_INFO temp;
		GetConsoleScreenBufferInfo(std_handle(),&temp);
		return temp.dwCursorPosition;
	}
	
	void setConsoleSize(Position size)
	{
		std::string command = "mode con cols=" + std::to_string(size.x) + " lines=" + std::to_string(size.y);
		system(command.c_str());
	}
	
	void clear()
	{
		setFeature(0);
		system("cls");
		setFeature(0);
	}
	
	int next()
	{
		int a = _getwch();
		if(a == 224)
		{
			a = -a*1000 - _getwch();
		}
		return a;
	}
}
