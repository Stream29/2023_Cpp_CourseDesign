#include "ValueHistory.h"

namespace status
{
	bool ValueHistory::has(key_type key) const
	{
		return this->find(key) != this->end();
	}
}
