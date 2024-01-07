#ifndef CONTEXT_H
#define CONTEXT_H

#include "AllViews.h"
#include "ValueHistory.h"
#include "Utils.h"

namespace status
{
	inline Screen nowScreen;
	
	inline std::string inputString {};
	inline int inputPos {};
	
	inline ValueHistory history {};
	
	inline std::map<std::string,std::string> hintText = util::FileReader("Hint.txt").readMap();
	
	inline view::MenuBar menuBar {"MenuBar.txt"};
	inline view::CenterText defaultHelper {"DefaultHelper.txt"};
	inline view::CenterText longerHelper {"Helper.txt"};
	inline view::BottomText currentBottomText {&history};
	inline view::InputLine defaultInputLine {"InputHint.txt",&inputString,&inputPos};
};

#endif
