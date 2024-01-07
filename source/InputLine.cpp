#include "InputLine.h"

namespace view
{
	InputLine::InputLine(std::string filePath,std::string* _inputContent,int* _inputPos): 
	TextView(util::FileReader(filePath).readText(),{5,0},INPUT_LINE_FEATURE),
	inputContent(_inputContent),
	inputPos(_inputPos)
	{}
	void InputLine::print(const console::Position& pos)
	{
		TextView::print(pos);
		std::cout << *inputContent << std::flush;
		endPosition = console::getPosition();
		console::setPosition({short(endPosition.x-inputContent->size()+*inputPos),endPosition.y});
	}
}
