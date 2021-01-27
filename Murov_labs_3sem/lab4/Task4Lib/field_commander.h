#ifndef FIELD_COMMANDER
#define FIELD_COMMANDER

#include <sstream>
#include "soldier.h"
#include "staff_member.h"
#include "crew.h"

namespace task_4
{
	class FieldCommander : virtual public StaffMember, virtual public Soldier	// Полевой командир
	{
	public:
		// TODO: constructors
		FieldCommander();
		FieldCommander(std::string, Rank, unsigned int, Specialization);
		Crew GetCrew() const { return *crew; }
		void SetCrew(Crew*);
		void Print(std::ostream&) const;			// TODO
		void Read(std::istream&);
		std::string		GetHTML(); 
	private:
		Crew* crew;
	};
}

#endif // !FIELD_COMMANDER
