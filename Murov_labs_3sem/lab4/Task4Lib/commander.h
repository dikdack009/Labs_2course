#ifndef COMMANDER
#define COMMANDER

#include "staff_member.h"
#include "crew.h"
#include <sstream>

namespace task_4
{
	class Commander : virtual public StaffMember
	{
	public:
		Commander();
		Commander(std::string, Rank, unsigned int);
		Crew* GetCrew() { return crew; }
		void SetCrew(Crew*);
		void Print(std::ostream&) const;
		void Read(std::istream&);
		virtual std::string	GetHTML(unsigned int);
		virtual std::string GetHTML();
	private:
		Crew* crew;
	};
}

#endif // !COMMANDER
