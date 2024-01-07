#include "MultiTextView.h"

namespace view
{
	void MultiTextView::setPosition(console::Position pos)
	{
		position = std::move(pos);
	}
	
	console::Position MultiTextView::getPosition() const
	{
		return position;
	}
	
	void MultiTextView::print(const console::Position& pos)
	{
		for(unsigned short i = 0;i < textViews.size();i ++)
		{
			textViews[i].print(getPosition() + pos);
		}
		this->endPosition = console::getPosition();
	}
	
	void MultiTextView::push_back(TextView textView)
	{
		textViews.push_back(std::move(textView));
	}
	
	void MultiTextView::clear()
	{
		for(auto& e : textViews)
		{
			e.clear();
		}
	}
}
