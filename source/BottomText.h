#ifndef BOTTOMTEXT_H
#define BOTTOMTEXT_H

#include "MultiTextView.h"
#include "ValueHistory.h"

namespace view
{
	class BottomText : public MultiTextView 
	{
	public:
		BottomText(status::ValueHistory* _history);
		void update();
		virtual void print(const console::Position& position) override;
		status::ValueHistory* history = nullptr;
	protected:
		console::Position beginPosition {};
	};
}

#endif
