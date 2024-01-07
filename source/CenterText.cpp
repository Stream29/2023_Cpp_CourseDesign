#include "CenterText.h"

namespace view
{
	CenterText::CenterText()
	{
		this->position = {10,2};
	}
	
	CenterText::CenterText(std::vector<std::string> content):
	CenterText()
	{
		for(size_t i = 0;i < content.size();i ++)
		{
			this->push_back(TextView(content[i],{0,static_cast<short>(i)},CENTER_TEXT_FEATURE));
		}
	}
	
	CenterText::CenterText(std::string fileName):
	CenterText(util::FileReader(std::move(fileName)).readByEndl())
	{}
}
