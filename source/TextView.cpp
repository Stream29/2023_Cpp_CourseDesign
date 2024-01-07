#include "TextView.h"

namespace view
{
	TextView::TextView(std::string _content,console::Position _position,WORD _feature) : 
	content(std::move(_content)),
	position(std::move(_position)),
	feature(std::move(_feature))
	{}
	
	void TextView::setContent(std::string ws)
	{
		content = std::move(ws);
	}
	
	std::string TextView::getContent() const
	{
		return content;
	}
	
	void TextView::setPosition(console::Position pos)
	{
		position = std::move(pos);
	}
	
	console::Position TextView::getPosition() const
	{
		return position;
	}
	
	void TextView::print(const console::Position& pos)
	{
		console::setPosition(getPosition() + pos);
		console::setFeature(feature);
		std::cout << content;
		this->endPosition = console::getPosition();
	}
	
	void TextView::clear()
	{
		console::Position beginPosition = endPosition;
		beginPosition.x -= content.size();
		TextView(std::string(content.size(),' '),beginPosition,0).print();
		this->content = "";
	}
}
