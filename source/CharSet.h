#ifndef CHARSET_H
#define CHARSET_H

#include <set>

namespace keys
{
	template <typename T = char>
	class CharSet : public std::set<T>
	{
	public:
		using std::set<T>::set;
		bool has(const T& c) const
		{
			return this->find(c) != this->end();
		}
	};
	template <typename... T>
	CharSet(T...) -> CharSet<std::common_type_t<T...>>;
}

#endif
