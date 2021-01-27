#include "pch.h"
#include "crew.h"

using namespace task_4;

void Crew::ChangeStatus(unsigned int id, Health state)
{
	if (militaries.GetHealth(id) == Health::Dead)
		throw (((std::out_of_range("Military is dead"))));
	militaries.GetHealth(id) = state;
}

void Crew::SetTable(Table tbl)
{
	delete& militaries;
	militaries = tbl;
}

void Crew::SetPlace(std::string location)
{
	//delete& place;
	place = location;
}

std::string task_4::Crew::GetHTML(unsigned int number)
{
	std::ostringstream os;
	os << "\t<div class=\"entity\">\n\t\t<span>Crew" << number << "</span>\n";
	os << militaries.GetHTML();
	os << "\t</div>\n";
	return os.str();
}

std::ostream& task_4::operator<<(std::ostream& out, const Crew& crew)
{
	out << "<Crew place:" << crew.place << ">\n" << crew.militaries << "\n</Crew>";
	return out;
}
