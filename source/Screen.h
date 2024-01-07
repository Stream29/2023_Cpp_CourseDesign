#ifndef SCREEN_H
#define SCREEN_H

#include "AllViews.h"
#include <vector>

namespace status
{
	class Screen {
	public:
		Screen() = default;
		view::MenuBar* menuBar;
		view::CenterText* centerText;
		view::BottomText* bottomText;
		view::InputLine* inputLine;
		void print();
		console::Position size {100,20};
	private:
		console::Position endPosition {};
	};
}


#endif
