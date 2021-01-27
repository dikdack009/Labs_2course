#ifndef TABLE_ELEMENT
#define TABLE_ELEMENT
#include <sstream>
#include "structs.h"
#include "military.h"

namespace task_4
{
	class TableElement
	{
		friend class Table;
		friend class Crew;
	public:
		TableElement(Military*, Health);
		friend std::ostream& operator<<(std::ostream&, const TableElement&);
		std::string		GetHTML();
	private:
		unsigned int	id;
		Military*		person;
		Health			state;
	};
}
#endif