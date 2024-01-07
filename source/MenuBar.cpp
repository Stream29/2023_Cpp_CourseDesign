#include "MenuBar.h"

namespace view
{
	MenuBar::MenuBar(std::string fileName)
	{
		position = {0,0};
		util::FileReader getMenubar(std::move(fileName));
		std::vector<std::string> menuBarItems = getMenubar.readByBlank();
		short nowX = 0;
		for(auto e : menuBarItems)
		{
			push_back(TextView(e,{nowX,0},MENU_BAR_FEATURE));
			nowX += DELTA_X;
		}
	}
}
