#include "BottomText.h"

namespace view
{
	BottomText::BottomText(status::ValueHistory* _history)
	:history(_history)
	{}
	void BottomText::update()
	{
		this->textViews.clear();
		for(auto& piece : *history)
		{
			const std::string content = piece.first + " = " + piece.second.toString();
			this->textViews.push_back(view::TextView(content));
		}
	}
	void BottomText::print(const console::Position& pos)
	{
		this->beginPosition = {pos.x,short(pos.y-textViews.size()-1)};
		for(size_t i = 0;i < textViews.size();i ++)
		{
			textViews[i].print({beginPosition.x,short(beginPosition.y+i)});
		}
	}
}
