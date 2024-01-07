#include "Analyze.h"

namespace util
{
	std::pair<std::string,math::RationalNumber> analyze(std::string_view text,const status::ValueHistory& history)
	{
		util::log(nowInfo,fmt(text));
		
		if(text.size() == 0)
		{
			throw exception::NullInputException{"analyze()"};
		}
		
		std::string processed = "";
		
		if(text.find('=') == text.npos)
		{
			processed.append("_=");
		}
		
		for(auto c : text)
		{
			if(!keys::blankChar.has(c))
			{
				processed.push_back(c);
			}
		}
		
		return __analyze(processed,history);
	}
	
	std::pair<std::string,math::RationalNumber> __analyze(std::string_view text,const status::ValueHistory& history)
	{
		util::log(nowInfo,fmt(text));
		
		if(text.size() == 0)
		{
			throw exception::NullInputException{"__analyze()"};
		}
		
		std::string name = "";
		auto now = text.begin();
		for(;now != text.end();now ++)
		{
			if(*now == '=')
			{
				now ++;
				break;
			}
			else
			{
				name.push_back(*now);
			}
		}
		
		__checkValidName(name);
		
		return {name,__getValue(std::string_view(now,text.end()-now),history)};
	}
	
	math::RationalNumber __getValue(std::string_view text,const status::ValueHistory& history)
	{
		util::log(nowInfo,fmt(text));
		
		if(text.size() == 0)
		{
			throw exception::NullInputException{"__getValue()"};
		}
		
		std::vector<std::size_t> bracketRecord = __countBracket(text);
		
		util::log(fmt(test::toString(bracketRecord)));
		
		//bracketed expression
		if(std::count(bracketRecord.begin(),bracketRecord.end(),0)==1 && text.size()!=1)
		{
			util::log("bracketed expression");
			return __getValue(__removeBracket(text),history);
		}
		
		//single expression
		auto isSingleExpression = [&]()
		{
			for(std::size_t i = 0;i < text.size();i ++)
			{
				if(i==0 && text[i]=='-')
				{
					continue;
				}
				if(keys::operatorChar_noBracket.has(text[i]))
				{
					return false;
				}
			}
			return true;
		};
		if(isSingleExpression())
		{
			util::log("single expression");
			return __getSingleValue(text,history);
		}
		
		//multiple expression
		util::log("multiple expression");
		std::list<std::size_t> operatorSplit = __splitByOperator(text,bracketRecord);
		operatorSplit.push_back(text.size());
		std::list<math::RationalNumber> valueSplit;
		
		//getting subvalue
		{
			std::size_t begin = 0;
			std::size_t end {};
			for(auto index : operatorSplit)
			{
				end = index;
				valueSplit.push_back(__getValue(text.substr(begin,end-begin),history));
				begin = end + 1;
			}
		}
		operatorSplit.pop_back();
		
		auto processWith = [&](auto _operator,char _operator_char)
		{
			auto nowOperator = operatorSplit.begin();
			auto nowValue = valueSplit.begin();
			for(;nowOperator!=operatorSplit.end() && nowValue!=valueSplit.end();nowOperator++,nowValue++)
			{
				util::log(fmt(*nowOperator));
				util::log(fmt(*nowValue));
				util::log(fmt(text[*nowOperator]));
				util::log(fmt(operatorSplit));
				util::log(fmt(valueSplit));
				if(text[*nowOperator] != _operator_char)
				{
					continue;
				}
				math::RationalNumber result = _operator(*nowValue,*std::next(nowValue));
				*std::next(nowValue) = std::move(result);
				
				nowOperator = std::prev(operatorSplit.erase(nowOperator));
				nowValue = std::prev(valueSplit.erase(nowValue));
				
				util::log(fmt(operatorSplit));
				util::log(fmt(valueSplit));
			}
		};
		processWith([](auto a,auto b){return a / b;},'/');
		processWith([](auto a,auto b){return a * b;},'*');
		processWith([](auto a,auto b){return a + b;},'+');
		processWith([](auto a,auto b){return a - b;},'-');
		
		return valueSplit.front();
	}
	
	math::RationalNumber __getSingleValue(std::string_view text,const status::ValueHistory& history)
	{
		util::log(nowInfo,fmt(text));
		
		if(text.size() == 0)
		{
			throw exception::NullInputException{nowInfo};
		}
		
		int base = 1;
		
		if(text.front() == '-')
		{
			util::log("negative detected");
			text = text.substr(1,text.size()-1);
			base = -1;
		}
		if(text.size() == 0)
		{
			throw exception::NullInputException{nowInfo};
		}
		
		auto content = std::string(text);
		
		if(__isNumeric(text))
		{
			return math::RationalNumber(content) * math::RationalNumber(base,1);
		}
		else
		{
			if(history.has(content))
			{
				return history.at(content) * math::RationalNumber(base,1);
			}
			else
			{
				throw exception::UnknownVarException{test::toString(content)};
			}
		}
	}
	
	bool __isNumeric(std::string_view text)
	{
		if(text.size() == 0)
		{
			throw exception::NullInputException{nowInfo};
		}
		for(auto e : text)
		{
			if(!isdigit(e))
			{
				return false;
			}
		}
		return true;
	}
	
	std::list<std::size_t> __splitByOperator(std::string_view text,const std::vector<std::size_t>& bracketRecord)
	{
		std::list<std::size_t> _split {};
		for(std::size_t i = 0;i < text.size();i ++)
		{
			if(text[i] == '-')
			{
				if(i==0)
				{
					continue;
				}
				if(_split.size()>0 && _split.back()+1==i)
				{
					continue;
				}
			}
			if(keys::operatorChar_noBracket.has(text[i]) && bracketRecord[i]==0)
			{
				_split.push_back(i);
			}
		}
		return _split;
	}
	
	std::vector<std::size_t> __countBracket(std::string_view text)
	{
		int bracketCount = 0;
		std::vector<std::size_t> bracketCountRecord;
		for(std::size_t i = 0;i < text.size();i ++)
		{
			const char& c = text[i];
			if(c == '(')
			{
				bracketCount ++;
			}
			if(c == ')')
			{
				bracketCount --;
			}
			if(bracketCount < 0)
			{
				throw exception::BracketMismatchException{test::toString(text)};
			}
			bracketCountRecord.push_back(bracketCount);
		}
		if(bracketCount != 0)
		{
			throw exception::BracketMismatchException{test::toString(text)};
		}
		return bracketCountRecord;
	}
	
	std::string_view __removeBracket(std::string_view text)
	{
		return text.substr(1,text.size()-2);
	}
	
	void __checkValidName(std::string_view text)
	{
		if(text.size() == 0)
		{
			throw exception::InvalidNameException{test::toString(text)};
		}
		if(!keys::validFirstChar.has(text.front()))
		{
			throw exception::InvalidNameException{test::toString(text)};
		}
		for(auto c : text)
		{
			if(!keys::validNameChar.has(c))
			{
				throw exception::InvalidNameException{test::toString(text)};
			}
		}
	}
}
