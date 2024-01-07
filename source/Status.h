#ifndef STATUS_H
#define STATUS_H

#include "Test.h"
#include "Utils.h"
#include "Context.h"
#include "Invoke.h"

namespace status
{
	FunctionPtr initStatus();
	
	FunctionPtr getCodeStatus();
	
	FunctionPtr inputStatus();
	
	FunctionPtr helpStatus();
	
	void __insert(char c);
	
	void __clear();
	
	FunctionPtr __leftStatus();
	
	FunctionPtr __rightStatus();
	
	FunctionPtr __deleteStatus();
	
	FunctionPtr __backspaceStatus();
	
	FunctionPtr exitStatus();
	
	FunctionPtr __exitStatus();
	
	int __hint(const std::vector<std::string>& content);
	
	template <typename ...T>
	int hint(const T& ...args)
	{
		return __hint(
			{
				hintText.find(args)==hintText.end() ? args : hintText[args]
				...
			}
		);
	}
}

namespace keys
{
	inline std::map<int,status::FunctionPtr> funcChar
	{
		{esc,(status::FunctionPtr)&status::exitStatus},
		{_left,(status::FunctionPtr)&status::__leftStatus},
		{_right,(status::FunctionPtr)&status::__rightStatus},
		{_delete,(status::FunctionPtr)&status::__deleteStatus},
		{_backspace,(status::FunctionPtr)&status::__backspaceStatus},
		{ctrlT,(status::FunctionPtr)&status::helpStatus}
	};
}

#endif
