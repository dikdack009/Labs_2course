#include "pch.h"
#include "soldier.h"
using namespace task_4;


Soldier::Soldier() : Military() { specialization = Specialization::Infantry; }

Soldier::Soldier(std::string name, Rank rank, unsigned int uniform_size, Specialization spec)
	: Military(name, rank, uniform_size)
{
	specialization = spec;
}

void Soldier::Print(std::ostream& out) const
{
	out << "<Soldier id:" << GetId() << " name: " << GetName() << " uniform_size:" << GetUniformSize();
	out << " rank:" << GetRank() << " specialization:" << specialization << ">";
}

void Soldier::Read(std::istream& in)
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
	
	Specialization specialization;
	in >> specialization;
	specialization = specialization;
}

std::string task_4::Soldier::GetHTML()
{
	std::ostringstream os;
	os << "\t\t<div class=\"entity\">\n";
	os << "\t\t\t<span>Soldier</span>\n";
	os << "\t\t\tName: " << this->GetName() << "<br>\n";
	os << "\t\t\tUniform size: " << this->GetUniformSize() << "<br>\n";
	os << "\t\t\tRank: " << this->GetRank() << "<br>\n";
	os << "\t\t\tSpecialization: " << this->GetSpecialization() << "<br>\n";
	os <<  "\t\t</div>\n";
	return os.str();
}
