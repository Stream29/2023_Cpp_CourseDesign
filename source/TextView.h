#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#include "Position.h"
#include "ConsoleControl.h"
#include <iostream>

namespace view
{
	//this text view should be in one line, otherwise printing is is undefined behaviour.
	class TextView {
	public:
		TextView() = default;
		TextView(std::string _content,console::Position _position = {0,0},WORD _feature = FOREGROUND_INTENSITY);
		
		virtual void print(const console::Position& pos = {0,0});
		virtual void clear();
		
		virtual void setContent(std::string ws);
		virtual std::string getContent() const;
		virtual void setPosition(console::Position pos);
		virtual console::Position getPosition() const;
	protected:
		std::string content;
		console::Position position {};
		console::Position endPosition {};
		WORD feature = FOREGROUND_INTENSITY;
	};
}

#endif
