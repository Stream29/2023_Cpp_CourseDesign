#ifndef MENUBAR_H
#define MENUBAR_H

#include "MultiTextView.h"
#include <string>
#include <fstream>
#include "windows.h"
#include <iterator>
#include <iostream>
#include <algorithm>
#include "FileReader.h"

namespace view
{
	class MenuBar : public MultiTextView 
	{
	public:
		MenuBar() = default;
		MenuBar(std::string fileName);
		
	protected:
		
		inline const static short DELTA_X = 30;
		inline const static WORD MENU_BAR_FEATURE = FOREGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY;
	};
}

#endif
