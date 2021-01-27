#ifndef TABLE
#define TABLE

#include <map>
#include "structs.h"
#include "military.h"
#include "table_element.h"

namespace task_4
{
	class Table	// таблица военных
	{
		friend class Crew;
	public:
		Military&	GetMilitary(unsigned int);
		Health&		GetHealth(unsigned int);
		void		InsertElement(Military*, Health);
		void		DeleteElement(unsigned int);
		Military*	PopElement(unsigned int);
		unsigned int		Count();
		size_t		Count(Health);
		size_t		Count(Rank);
		friend std::ostream& operator<<(std::ostream&, const Table&);
		std::string		GetHTML();

	private:
		std::map<unsigned int, TableElement> data;
	};
}

#endif // !TABLE
