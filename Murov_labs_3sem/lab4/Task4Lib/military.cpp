#include "pch.h"
#include <iostream>
#include "military.h"

using namespace task_4;

unsigned int Military::new_id = 0;

Military::Military()
{
	id = new_id++;
	name = "";
	rank = Rank::Rank1;
	uniformSize = 0;
}

Military::Military(std::string name, Rank rank, unsigned int uniformSize)
{
	id = new_id++;
	this->name = name;
	this->rank = rank;
	this->uniformSize = uniformSize;
}

void task_4::Military::SetName(std::string new_name)
{
	name = new_name;
}

void Military::SetUniformSize(unsigned int value)
{
	uniformSize = value;
}

void Military::SetRank(const Rank value)
{
	rank = value;
}

std::ostream& task_4::operator<<(std::ostream& out, const Military& mil)
{
	mil.Print(out);
	return out;
}

std::istream& task_4::operator>>(std::istream& in, Military& mil)
{
	mil.Read(in);
	return in;
}
