#include "dialog.h"

using namespace task_4;
using namespace dialog;

int Dialog::NMsgs = 8;
std::string Dialog::Msgs[]{ 
	"0. Quit", "1. Show", "2. Add a training", "3. Add a military", 
	"4. Count", "5. Delete military", "6. Reset Crew", "7. Change status", "8. Get HTML" };
void (*Dialog::fptr[])(TrainingDescriptor&) { 
	nullptr, Dialog::Show, Dialog::AddTraining, Dialog::AddMilitary, 
		Dialog::CountMilitary, Dialog::DeleteMilitary, Dialog::ResetCrew, 
		Dialog::ChangeStage, Dialog::GetHTML };


void Dialog::Show(TrainingDescriptor& trainings)
{
	unsigned int i = 0;
	for (auto it = trainings.trainingList.begin(); it != trainings.trainingList.end(); ++it)
		std::cout << i++ << ". " << *it << std::endl;
}

void dialog::Dialog::AddTraining(TrainingDescriptor& trainings)
{

	std::cout << "Place: ";
	std::string place;
	std::getline(std::cin, place);

	std::cout << "Duration: ";
	std::string duration;
	std::getline(std::cin, duration);

	std::cout << "Commander 1.\n";
	Commander* commander1 = new Commander();
	std::cin >> *commander1;

	std::cout << "\nCommander 2.\n";
	Commander* commander2 = new Commander();
	std::cin >> *commander2;
	
	Training training = Training(place, duration, commander1, commander2);
	trainings.trainingList.push_front(training);
}

void dialog::Dialog::AddMilitary(TrainingDescriptor& trainings)
{
	if (trainings.trainingList.size() == 0)
	{
		std::cout << "Empty training list\n";
		return;
	}
	unsigned int training_idx;
	GetUInt(training_idx, "Enter training number: ");

	if (training_idx >= trainings.trainingList.size())
	{
		std::cout << "Training number out of range.\n";
		return;
	}
	auto crew = trainings.trainingList.begin();
	unsigned int i = 0;
	while (i++ < training_idx)
		++crew;

	unsigned int class_idx;
	GetUInt(class_idx, "Select military class:\n\t0 (Soldier)\n\t1 (StaffMember)\n\t2 (Commander)\n\t3 (Field Commander)");
	if (class_idx > 3) {
		std::cout << "Class index out of range.";
		return;
	}
	
	Military* mil = nullptr;
	switch (class_idx) {
	case 0:
		mil = new Soldier();
		break;
	case 1:
		mil = new StaffMember();
		break;
	case 2:
		mil = new Commander();
		break;
	case 3:
		mil = static_cast<Soldier *>(new FieldCommander());
	}

	std::cin >> *mil;

	bool first;
	std::cout << "First crew? (0 / 1)\n";
	std::cin >> first;
	crew->Add(mil, Health::Healhy, first);
}

void dialog::Dialog::CountMilitary(TrainingDescriptor& trainings)
{
	std::cout << "Basing on what do you want to count?\n";
	// std::cout << "Count all (0)\n" "Rank(1)\n" "Crew(2)\n";
	unsigned int base;
	do {
		GetUInt(base, "Count all (0)\n" "Rank(1)\n" "Crew(2)\n");
	} while (base > 2);
	
	unsigned int num = 0;
	unsigned int Tnum = 0;
	for (auto it = trainings.trainingList.begin(); it != trainings.trainingList.end(); ++it)
	{
		switch (base) {
		case 0:
			 num = it->Count();
			break;
		case 1:
			std::cout << "Rank: \n";
			Rank rank;
			std::cin >> rank;
			num = it->Count(rank);
			break;
		case 2:
			std::cout << " ";
			unsigned int first;
			do {
				GetUInt(first, "First crew? (0/1)\n");
			} while (base > 1);
			num = it->Count((bool)first);
			break;
		}
		std::cout << "Training " << Tnum << ": " << num << std::endl;
		++Tnum;
	}
}


void dialog::Dialog::ResetCrew(TrainingDescriptor& trainings)
{
	unsigned int id, crew;
	GetUInt(id, "Enter military id");
	do {
		GetUInt(crew, "Enter new crew: ");
	} while (crew > 1);

	for (auto it = trainings.trainingList.begin(); it != trainings.trainingList.end(); ++it) {
		try {
			it->ResetCrew(id, (bool)crew);
			break;
		}
		catch (std::out_of_range) {
			continue;
		}
	}
}

void dialog::Dialog::GetHTML(TrainingDescriptor& trainings)
{
	std::string html = trainings.GetHTML();
	std::ofstream file("trainings.html");
	file << html;
	file.close();
}

void dialog::Dialog::DeleteMilitary(TrainingDescriptor& trainings)
{
	unsigned int id;
	GetUInt(id, "Enter military id");
	for (auto it = trainings.trainingList.begin(); it != trainings.trainingList.end(); ++it) {
		try {
			it->Delete(id);
			break;
		}
		catch (std::out_of_range) {
			continue;
		}
	}
}

void dialog::Dialog::ChangeStage(TrainingDescriptor& trainings)
{
	unsigned int id;
	Health stage;
	std::cout << "Enter new state: \n";
	std::cin >> stage;
	GetUInt(id, "Enter military id");
	for (auto it = trainings.trainingList.begin(); it != trainings.trainingList.end(); ++it) {
		try {
			it->ChangeStatus(id, stage);
			break;
		}
		catch (std::out_of_range) {
			continue;
		}
	}
}

int Dialog::dialog()
{
	int rc;
	do {
		for (int i = 0; i < NMsgs; i++)
			std::cout << Msgs[i] << std::endl;
		GetInt(rc, "Select dialog option: ", std::cin);
	} while (rc < 0 || rc >= NMsgs);
	return rc;
}