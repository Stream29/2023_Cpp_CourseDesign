#include "Screen.h"

namespace status
{
	void Screen::print()
	{
		this->size.y = centerText->textViews.size() + bottomText->history->size() + 5;
//		console::setConsoleSize({short(this->size.x+20),short(this->size.y+20)});
		this->menuBar->print();
		this->centerText->print();
		this->bottomText->print({0,size.y});
		this->inputLine->print({0,size.y});
		this->endPosition = console::getPosition();
	}
}
