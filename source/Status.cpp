#include "Status.h"

namespace status
{
	FunctionPtr initStatus()
	{
		util::log("\n");
		util::log(nowTime,"init");
		util::log(nowInfo);
		
		nowScreen.menuBar = &menuBar;
		nowScreen.centerText = &defaultHelper;
		nowScreen.bottomText = &currentBottomText;
		nowScreen.inputLine = &defaultInputLine;
		return (FunctionPtr)&inputStatus;
	}
	
	FunctionPtr getCodeStatus()
	{
		util::log(nowInfo);
		
		console::clear();
		nowScreen.inputLine = &defaultInputLine;
		nowScreen.print();
		
		while(true)
		{
			int input = console::next();
//			hint("begin","invalid character",std::to_string(input),"continue","end");
			util::log(nowTime,fmt(input));
		}
		return (FunctionPtr)&getCodeStatus;
	}
	
	FunctionPtr inputStatus()
	{
		util::log(nowInfo);
		
		console::clear();
		nowScreen.inputLine = &defaultInputLine;
		nowScreen.print();
		
		while(true)
		{
			int input = console::next();
			if(input == keys::endl)
			{
				util::log("endl");
				break;
			}
			if(keys::funcChar.count(input))
			{
				return keys::funcChar[input];
			}
			if(keys::validInputChar.has(input) && keys::isASCII(input))
			{
				util::log("get valid Ascii charactor",char(input),std::to_string(input));
				__insert(input);
			}
			else
			{
				hint("begin","invalid character",std::to_string(input),"continue","end");
				util::log("get invalid charactor",input);
			}
			util::log(fmt(inputString));
			console::clear();
			nowScreen.print();
		}
		try
		{
			auto result = util::analyze(inputString,history);
			
			history[result.first] = result.second;
			nowScreen.bottomText->update();
			
			__clear();
		}
		catch(exception::InvalidNameException e)
		{
			hint("begin","fail","invalid name",e.content,"continue","end");
			util::log("InvalidNameException : " + e.content);
		}
		catch(exception::NullInputException e)
		{
			hint("begin","fail","null input","continue","end");
			util::log("NullInputException : " + e.content);
		}
		catch(exception::BracketMismatchException e)
		{
			hint("begin","fail","bracket mismatch",e.content,"continue","end");
			util::log("BracketMismatchException : " + e.content);
		}
		catch(exception::UnknownVarException e)
		{
			hint("begin","fail","unknown name",e.content,"continue","end");
			util::log("UnknownVarException : " + e.content);
		}
		catch(exception::DividedByZeroException e)
		{
			hint("begin","fail","divided by zero","continue","end");
			util::log("DividedByZeroException : ");
		}
		
		return (FunctionPtr)&inputStatus;
	}
	
	FunctionPtr helpStatus()
	{
		if(nowScreen.centerText == &longerHelper)
		{
			nowScreen.centerText = &defaultHelper;
		}
		else
		{
			nowScreen.centerText = &longerHelper;
		}
		
		return (FunctionPtr)&inputStatus;
	}
	
	void __insert(char c)
	{
		inputString.insert(inputPos,1,c);
		inputPos ++;
	}
	
	void __clear()
	{
		inputString.clear();
		inputPos = 0;
	}
	
	FunctionPtr __leftStatus()
	{
		if(inputPos > 0)
		{
			inputPos --;
		}
		return (FunctionPtr)&inputStatus;
	}
	
	FunctionPtr __rightStatus()
	{
		if(inputPos < inputString.size())
		{
			inputPos ++;
		}
		return (FunctionPtr)&inputStatus;
	}
	
	FunctionPtr __deleteStatus()
	{
		if(inputPos < inputString.size())
		{
			inputString.erase(inputString.begin() + inputPos);
		}
		return (FunctionPtr)&inputStatus;
	}
	
	FunctionPtr __backspaceStatus()
	{
		__leftStatus();
		__deleteStatus();
		return (FunctionPtr)&inputStatus;
	}
	
	FunctionPtr exitStatus()
	{
		int input = hint("exit confirm 1","exit confirm 2");
		util::log(nowInfo,fmt(input));
		if(keys::exitConfirmChar.has(input))
		{
			return (FunctionPtr)&__exitStatus;
		}
		else
		{
			return (FunctionPtr)&inputStatus;
		}
	}
	
	FunctionPtr __exitStatus()
	{
		util::log(nowInfo);
		std::exit(0);
		return (FunctionPtr)&__exitStatus;
	}
	
	int __hint(const std::vector<std::string>& content)
	{    
		view::CenterText originalCenterText = *(nowScreen.centerText);
		originalCenterText.clear();
		
		view::CenterText hint {content};
		hint.print();
		
		int input = console::next();
		
		hint.clear();
		nowScreen.print();
		
		return input;
	}
}

