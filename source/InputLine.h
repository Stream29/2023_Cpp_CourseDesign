#ifndef INPUTLINE_H
#define INPUTLINE_H

#include "TextView.h"
#include "FileReader.h"
#include "ConsoleControl.h"

namespace view
{
	class InputLine : public TextView 
	{
	public:
		std::string* inputContent = nullptr;
		int* inputPos = nullptr;
		InputLine() = default;
		InputLine(std::string filePath,std::string* _inputContent,int* _inputPos);
		virtual void print(const console::Position& pos = {0,0});
	protected:
		inline static const WORD INPUT_LINE_FEATURE = FOREGROUND_GREEN | FOREGROUND_BLUE;
	};
}

#endif
