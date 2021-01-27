#include "pch.h"
#include "structs.h"

bool task_4::TryParse(std::string& input, int& output) {
	try {
		output = std::stoi(input);
	}
	catch (std::invalid_argument) {
		return false;
	}
	return true;
}

bool task_4::TryParseUint(std::string& input, unsigned int& output) {
	try {
		output = std::stoul(input);
	}
	catch (std::invalid_argument) {
		return false;
	}
	return true;
}

void task_4::GetInt(int& a, const char* msg, std::istream& in) {
	std::string input;

	std::cout << msg;

	if (!getline(in, input))
		throw std::exception("End of file");

	while (!TryParse(input, a))
	{
		std::cout << "Bad entry. Enter a NUMBER: ";
		if (!getline(in, input))
			throw std::exception("End of file");
	}
}

void task_4::GetUInt(unsigned int& a, const char* msg, std::istream& in) {
	std::string input;
	std::string err = "";
	std::cout << msg << std::endl;

	if (!getline(in, input))
		throw "End of file";

	while (!TryParseUint(input, a))
	{
		std::cout << err;
		if (!getline(in, input))
			throw "End of file";
		err = "Bad entry. Enter a NUMBER: \n";
	}
}

std::istream& task_4::operator>>(std::istream& in, Command& command)
{
	in >> command.text;
	return in;
}


std::ostream& task_4::operator<<(std::ostream& out, const Instruction& instruction)
{
	out << "<Instruction id:" << instruction.id << " text:\"" << instruction.text << "\">";
	return out;
}

std::istream& task_4::operator>>(std::istream& in, Instruction& instruction)
{
	std::cout << "<Instruction\n\tid:";
	in >> instruction.id;
	std::cout << "\ttext:";
	in >> instruction.text;
	std::cout << "/>";
	return in;
}

std::ostream& task_4::operator<<(std::ostream& out, Rank rank)
{
	std::string names[] = { "Rank1", "Rank2", "Rank3" };
	out << names[(int)rank];
	return out;
}

std::ostream& task_4::operator<<(std::ostream& out, Specialization specialization)
{
	std::string names[] = {
		"Infantry", "SpecialForces", "Scout", "Sniper",
		"Sapper", "RCBP", "Orderly", "RadioOperator"
	};
	out << names[(int)specialization];
	return out;
}

std::ostream& task_4::operator<<(std::ostream& out, Health health)
{
	std::string names[] = { "Healhy", "Wounded", "Dead", "Lost" };
	out << names[(int)health];
	return out;
}

std::istream& task_4::operator>>(std::istream& in, Rank& rank)
{
	unsigned int rank_idx;
	do {
		GetUInt(rank_idx, "Rank number (0-2):");
	} while (rank_idx > 2);
	rank = (Rank)rank_idx;
	return in;
}

std::istream& task_4::operator>>(std::istream& in, Health& health)
{
	unsigned int health_idx;
	do {
		GetUInt(health_idx, "Health - 0: Healthy, 1: Wounded, 2: Dead, 3: Lost:");
	} while (health_idx > 3);
	health = (Health)health_idx;
	return in;
}

std::istream& task_4::operator>>(std::istream& in, Specialization& specialization)
{
	unsigned int specialization_idx;
	do {
		GetUInt(specialization_idx, 
			"Specialization:\n\t0: Infantry\n\t1: Special Forces\n\t2: Scout\n\t3: Sniper\n\t4: Sapper\n\t5: RCBP\n\t6: Orderly\n\t7: Radio Operator");
	} while (specialization_idx > 7);
	specialization = (Specialization)specialization_idx;
	return in;
}
