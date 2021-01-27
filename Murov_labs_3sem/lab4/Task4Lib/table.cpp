#include "pch.h"
#include "table.h"

using namespace task_4;

Military& Table::GetMilitary(unsigned int idx)
{
	// return data[idx].person; needs a default constructor to be implemented
	return *data.at(idx).person;	// throws out_of_range exception when the key is not present
}

Health& Table::GetHealth(unsigned int idx)
{
	return data.at(idx).state;
}

void Table::InsertElement(Military* mil, Health health)
{
	std::pair<unsigned int, TableElement> pair = std::make_pair(mil->GetId(), TableElement(mil, health));
	data.insert(pair);
}

void Table::DeleteElement(unsigned int idx)
{
	std::map<unsigned int, TableElement>::iterator it = data.find(idx);
	if (it == data.end())
		throw std::out_of_range("Military not found");
	data.erase(it);
}

Military* Table::PopElement(unsigned int idx)
{
	std::map<unsigned int, TableElement>::iterator it = data.find(idx);
	if (it == data.end())
		return nullptr;
	Military* element = it->second.person;
	it->second.person = nullptr;
	data.erase(it);
	return element;
}

unsigned int Table::Count()
{
	return data.size();
}

size_t Table::Count(Health health)
{
	size_t count = 0;
	for (auto it = data.begin(); it != data.end(); ++it) {
		if (it->second.state == health)
			++count;
	}
	return count;
}

size_t Table::Count(Rank rank)
{
	size_t count = 0;
	for (auto it = data.begin(); it != data.end(); ++it) {
		if (it->second.person->GetRank() == rank)
			++count;
	}
	return count;
}

std::string task_4::Table::GetHTML()
{
	std::string result = "\t<div class=\"container\">\n";
	for (auto it = data.begin(); it != data.end(); ++it){
		result += "\t<div class=\"entity\">\n";
		result += it->second.GetHTML() + "<br>\n";
	}
	result += "\t</div>\n";
	return result;
}

std::ostream& task_4::operator<<(std::ostream& out, const Table& table)
{
	out << "Table:\n";
	for (auto it = table.data.begin(); it != table.data.end(); ++it) {
		out << "\t" << it->second << std::endl;
	}
	return out;
}