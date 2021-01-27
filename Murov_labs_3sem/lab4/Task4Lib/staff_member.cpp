#include "pch.h"
#include "staff_member.h"

using namespace task_4;

StaffMember::StaffMember(std::string name, Rank rank, unsigned int uniform_size)
	: Military(name, rank, uniform_size)
{
	instructions = custom_list::List<Instruction>();
}

void task_4::StaffMember::SetStaffPosition(std::string value)
{
	staffPosition = value;
}

StaffMember::StaffMember()
	: StaffMember("", Rank::Rank1, 0)
{
	instructions = custom_list::List<Instruction>();
}

void StaffMember::Print(std::ostream& out) const
{
	out << "< Staff Member id: " << GetId() << " name : " << GetName() << " uniform_size: " << GetUniformSize();
	out << " Staff Position: " << staffPosition << " >";
	out << "\tInstructions:\n";
	auto instruction_list = GetInstructions();
	for (auto it = instruction_list.begin(); it != instruction_list.end(); ++it)
		out << "\t\t" << *it << std::endl;
	out << "</Commander>";
}

void StaffMember::Read(std::istream& in)
{
	std::string name;
	Rank rank;
	unsigned int uniform_size;
	std::cout << "Name: ";
	in >> name;
	in >> rank;
	std::cout << "Uniform size: ";
	in >> uniform_size;
	SetName(name);
	SetRank(rank);
	SetUniformSize(uniform_size);

	std::string position;
	std::cout << "Staff position: ";
	in >> position;
	SetStaffPosition(position);

	Instruction instruction;
	unsigned int instructions_number;
	GetUInt(instructions_number, "Enter the number of instructions:");
	for (unsigned int i = 0; i < instructions_number; ++i)
	{
		in >> instruction;
		instructions.push_front(instruction);
	}
	
}

std::string task_4::StaffMember::GetHTML()
{
	std::ostringstream os;
	os << "\t\t<div class=\"entity\">\n";
	os << "\t\t\t<span>Staff Member</span>\n";
	os << "\t\t\tName: " << GetName() << "<br>\n";
	os << "\t\t\tUniform size: " << GetUniformSize() << "<br>\n";
	os << "\t\t\tRank: " << GetRank() << "<br>\n";
	os << "\t\t\tStaff Position: " << GetStaffPosition() << "<br>\n";
	os << "\t\t<div class=\"container\"><span>Instructions</span>\n";
	os << "\t\t\t<ul>\n";
	for (auto instruction = instructions.begin(); instruction != instructions.end(); ++instruction)
		os << "\t\t\t\t<li><b>" << instruction->GetId() << "</b> " << instruction->GetInstruction() << "</li>\n";
	os << "\t\t\t</ul>\n\t\t</div>";
	os << "\t\t</div>\n";
	return os.str();

}

