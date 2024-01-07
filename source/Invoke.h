#ifndef INVOKE_H
#define INVOKE_H

namespace status
{
	using FunctionPtr = void*;
	
	FunctionPtr invoke(const FunctionPtr _func);
}

#endif
