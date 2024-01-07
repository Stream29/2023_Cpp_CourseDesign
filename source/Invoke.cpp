#include "Invoke.h"

namespace status
{
	FunctionPtr invoke(const FunctionPtr _func)
	{
		using Function = FunctionPtr(void);
		const Function* func = (Function*)_func;
		return (*func)();
	}
}
