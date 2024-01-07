#include <iostream>
#include <windows.h>
#include <functional>

#include "AllViews.h"
#include "Status.h"
#include "Mathematical.h"
#include "Test.h"

status::FunctionPtr nowStatus = (status::FunctionPtr)&status::initStatus;

int main(int argc, char** argv) 
{
	console::setTitle("ConsoleCaculator");
	while(true)
	{
		nowStatus = status::invoke(nowStatus);
	}
	return 0;
}
