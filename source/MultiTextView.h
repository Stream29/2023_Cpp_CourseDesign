#ifndef MULTITEXTVIEW_H
#define MULTITEXTVIEW_H

#include <vector>
#include "TextView.h"
#include "Position.h"
#include "ConsoleControl.h"

namespace view
{
	class MultiTextView 
	{
	public:
		std::vector<TextView> textViews;
		
		MultiTextView() = default;
		
		virtual void push_back(TextView textView);
		virtual void print(const console::Position& pos = {0,0});
		virtual void clear();
		
		virtual void setPosition(console::Position pos);
		virtual console::Position getPosition() const;
		
		console::Position position;
		console::Position endPosition;
	};
}

#endif
