#ifndef CENTERTEXT_H
#define CENTERTEXT_H

#include "MultiTextView.h"
#include "windows.h"
#include "FileReader.h"

namespace view
{
	class CenterText : public MultiTextView 
	{
	public:
		CenterText();
		CenterText(std::string fileName);
		CenterText(std::vector<std::string> content);
	protected:
		inline const static WORD CENTER_TEXT_FEATURE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	};
}

#endif
