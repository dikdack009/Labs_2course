#include "pch.h"
#include "training.h"

using namespace task_4;

Training::Training(std::string place, std::string duration, Commander* comm1, Commander* comm2)
{
	commander1	= comm1;
	commander2	= comm2;
	length		= duration;
	this->place = place;
}

Military& Training::GetMilitary(size_t idx)
{
	try {
		return commander1->GetCrew()->GetTable().GetMilitary(idx);
	}
	catch (std::out_of_range) {
		return commander2->GetCrew()->GetTable().GetMilitary(idx);
	}
}

unsigned int task_4::Training::Count()
{
	return commander1->GetCrew()->GetTable().Count() + commander2->GetCrew()->GetTable().Count() + 2;
}

unsigned int task_4::Training::Count(bool first)
{
	return (first ? commander1 : commander2)->GetCrew()->GetTable().Count() + 1;
}

unsigned int task_4::Training::Count(Rank rank)
{ 
	unsigned int num;
	num = commander1->GetCrew()->GetTable().Count(rank) + commander2->GetCrew()->GetTable().Count(rank);
	if (commander1->GetRank() == rank)
		++num;
	if (commander2->GetRank() == rank)
		++num;
	return num;
}

void task_4::Training::Add(Military* mil, Health health, bool first)
{
	Crew* crew = first ? commander1->GetCrew() : commander2->GetCrew();
	crew->GetTable().InsertElement(mil, health);
}

void task_4::Training::Delete(unsigned int militaryId)
{
	try {
		commander1->GetCrew()->GetTable().DeleteElement(militaryId);
	}
	catch (std::out_of_range)
	{
		commander2->GetCrew()->GetTable().DeleteElement(militaryId);
	}
}

void task_4::Training::ResetCrew(unsigned int militaryId, bool first)
{
	Military* element;
	element = commander1->GetCrew()->GetTable().PopElement(militaryId);
	if (element == nullptr)
		element = commander1->GetCrew()->GetTable().PopElement(militaryId);
	if (element == nullptr)
		throw (std::out_of_range("Military not found"));
	(first ? commander1 : commander2)->GetCrew()->GetTable().InsertElement(element, Health::Healhy);
}

void task_4::Training::ChangeStatus(unsigned int id, Health stage)
{
	try{
		commander1->GetCrew()->ChangeStatus(id, stage);
	}
	catch(std::out_of_range){
		commander2->GetCrew()->ChangeStatus(id, stage);
	}
}

std::string task_4::Training::GetHTML(unsigned int id)
{
	std::ostringstream os;
	os << "\t<div class=\"entity\">\n\t\t<span>Training" << id << "</span>\n";
	os << "\t\tPlace: " << this->place << "<br>\n";
	os << "\t\tDuration: " << this->length << "<br>\n";
	os << this->commander1->GetHTML(1);
	os << this->commander2->GetHTML(2);
	os << "\t</div>\n";
	return os.str();
}

std::ostream& task_4::operator<<(std::ostream& out, const Training& training)
{
	out << "<Training duration:" << training.length << "place: " << training.place << ">\n";
	out << "Commander 1: " << *training.commander1 << std::endl;
	out << "Commander 2: " << *training.commander2 << std::endl;
	out << "Crew 1:\n"	<< *training.commander1->GetCrew() << std::endl;
	out << "Crew 2:\n"	<< *training.commander2->GetCrew() << std::endl;
	out << "</Training>";
	return out;
}

std::string task_4::TrainingDescriptor::GetHTML()
{
	std::string result = "<html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"trainings_style.css\"><title>Trainings</title></head>\n";
	result += "<body>\n";
	result += "<div class=\"container\">\n<span>Trainings</span>\n";
	unsigned int id = 0;
	for (auto training = trainingList.begin(); training != trainingList.end(); ++training)
		result += training->GetHTML(id++) + std::string("\n");
	result += "</div>\n</body>\n</html>";
	return result;
}
