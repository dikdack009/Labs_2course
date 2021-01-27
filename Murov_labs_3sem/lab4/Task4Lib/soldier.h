#ifndef SOLDIER
#define SOLDIER

#include <sstream>
#include "../Custom_List/custom_list.h"
#include "military.h"

namespace task_4
{
	class Soldier : virtual public Military		// Солдат
	{
	public:
		Soldier();
		Soldier(std::string, Rank, unsigned int, Specialization);
		Specialization				GetSpecialization() const { return specialization; }
		const custom_list::List<Command>	GetCommands()		const { return commands; };
		void Print(std::ostream&) const;
		void Read(std::istream&);
		virtual std::string	 GetHTML();
	private:
		Specialization		specialization;
		custom_list::List<Command> commands;
	};
}

#endif // !SOLDIER
