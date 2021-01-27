#ifndef STAFF_MEMBER
#define STAFF_MEMBER

#include <sstream>
#include "../Custom_List/custom_list.h"
#include "structs.h"
#include "military.h"

namespace task_4
{
	class StaffMember : virtual public Military	// Штабист
	{
	public:
		StaffMember();
		StaffMember(std::string, Rank, unsigned int);
		std::string GetStaffPosition() const { return staffPosition; }
		void		SetStaffPosition(std::string);
		const custom_list::List<Instruction> GetInstructions() const { return instructions; }
		void Print(std::ostream&) const;	
		void Read(std::istream&);
		virtual std::string		GetHTML();
	private:
		std::string				staffPosition;
		custom_list::List<Instruction>	instructions;
	};
}

#endif // !STAFF_MEMBER
