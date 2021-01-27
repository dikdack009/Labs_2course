#include "pch.h"
#include "field_commander.h"

using namespace task_4;

FieldCommander::FieldCommander(std::string name, Rank rank, unsigned int uniform_size, Specialization specialization)
	: Soldier(name, rank, uniform_size, specialization), StaffMember(), Military(name, rank, uniform_size)
{
	crew = new Crew();
}

FieldCommander::FieldCommander()
	: FieldCommander("", Rank::Rank1, 0, Specialization::Infantry)
{
}

void FieldCommander::SetCrew(Crew* squad)
{
	delete crew;
	crew = squad;
}

void FieldCommander::Print(std::ostream& out) const
{
	out << "< Field Commander id: " << GetId() << " name : " << GetName() << " uniform_size:" << GetUniformSize();
	out << " rank:" << GetRank() << " specialization:" << GetSpecialization() << " >";
}

void FieldCommander::Read(std::istream& in)
{
	Soldier::Read(in);
	std::string position;
	std::cout << "staff position: ";
	in >> position;
	SetStaffPosition(position);
}

std::string task_4::FieldCommander::GetHTML()
{
	std::ostringstream os;
	os << "\t\t<div class=\"entity\">\n";
	os << "\t\t\t<span>Field Commander</span>\n";
	os << "\t\t\tName: " << GetName() << "<br>\n";
	os << "\t\t\tUniform size: " << GetUniformSize() << "<br>\n";
	os << "\t\t\tRank: " << GetRank() << "<br>\n";
	os << "\t\t\tSpecialization: " << GetSpecialization() << "<br>\n";
	os << "\t\t\tStaff Position: " << GetStaffPosition() << "<br>\n";
	os << "\t\t</div>\n";
	return os.str();
}
