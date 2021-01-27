#include "pch.h"
#include "table_element.h"
using namespace task_4;

TableElement::TableElement(Military* mil, Health health)
{
	id		= mil->GetId();
	state	= health;
	person	= mil;
}

std::string task_4::TableElement::GetHTML()
{
	std::ostringstream os;
	os << "\t\t<div class=\"entity\">\n";
	// os << "\t\t\t<span>Table Element</span>\n";
	os << "\t\t\tHealth: " << this->state << "<br>\n";
	os << "\t\t\tMilitary: " << id << "</span>\n";
	os << person->GetHTML();
	os << "\t</div>\n";
	return os.str();
}

std::ostream& task_4::operator<<(std::ostream& out, const TableElement& el)
{
	out << "<TableElement " << el.id << " "<< *el.person << " " << el.state << ">";
	return out;
}