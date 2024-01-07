#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <exception>

namespace exception
{
	struct Exception
	{
		std::string content {};
	};
	struct InvalidNameException : public Exception
	{};
	struct NullInputException : public Exception
	{};
	struct BracketMismatchException : public Exception
	{};
	struct UnknownVarException : public Exception
	{};
	struct DividedByZeroException : public Exception
	{};
}

#endif
