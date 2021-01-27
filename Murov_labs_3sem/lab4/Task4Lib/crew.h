#ifndef CREW
#define CREW

#include "military.h"
#include "table.h"
#include <sstream>

namespace task_4
{
	class Crew				// Подразделение
	{
	public:
		void			ChangeStatus(unsigned int, Health);
		Table&			GetTable() { return militaries; } 
		void			SetTable(Table);
		std::string		GetPlace() const { return place; }
		void			SetPlace(std::string);
		friend std::ostream& operator<<(std::ostream&, const Crew&);
		std::string		GetHTML(unsigned int);
	private:
		Table			militaries;
		std::string		place = "";

	};
}

#endif // !CREW
