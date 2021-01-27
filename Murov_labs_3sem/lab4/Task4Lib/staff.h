#ifndef STAFF
#define STAFF

#include "crew.h"

namespace task_4
{
	class Staff : public Crew		// иђрс
	{
	private:
		using Crew::SetPlace;	// makes SetPlace private
	};
}

#endif // !STAFF
