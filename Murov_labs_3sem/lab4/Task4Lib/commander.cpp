#include "pch.h"
#include "string.h"
#include "commander.h"

using namespace task_4;

Commander::Commander(std::string name, Rank rank, unsigned int uniform_size)
	: StaffMember(name, rank, uniform_size), Military(name, rank, uniform_size)
{
	crew = new Crew();
}

Commander::Commander()
	: Commander("", Rank::Rank1, 0)
{

}

void task_4::Commander::SetCrew(Crew* new_crew)
{
	delete crew;
	crew = new_crew;
}

void Commander::Print(std::ostream& out) const
{
	out << "<Commander id:" << GetId() << " name: " << GetName() << " uniform_size:" << GetUniformSize();
	out << " rank:" << GetRank() << " staff_position:" << GetStaffPosition() << ">\n";
	out << "\tInstructions:\n";
	auto instruction_list = GetInstructions();
	for (auto it = instruction_list.begin(); it != instruction_list.end(); ++it)
		out << "\t\t" << *it << std::endl;
	out << "</Commander>";
}

void Commander::Read(std::istream& in)
{
	StaffMember::Read(in);
}

std::string task_4::Commander::GetHTML(unsigned int number)
{	
	std::ostringstream os;
	os << "\t\t<div class=\"entity\">\n\t\t\t<span>Commander " << number << "</span>\n";
	os << this->crew->GetHTML(number);
	os << "\t\t</div>\n";
	os << "\t\t<div class=\"container\"><span>Instructions</span>\n";
	os << "\t\t\t<ul>\n";
	auto instructions = GetInstructions();
	for (auto instruction = instructions.begin(); instruction != instructions.end(); ++instruction)
		os << "\t\t\t\t<li><b>" << instruction->GetId() << "</b> " << instruction->GetInstruction() << "</li>\n";
	os << "\t\t\t</ul>\n\t\t</div>";
	os << "\t\t</div>\n";
	return os.str();
}

std::string Commander::GetHTML()
{
	return "";
}
