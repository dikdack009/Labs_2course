#include <iostream>

#include "../DialogProject/dialog.h"
#include "../Custom_List/custom_list.h"

using namespace task_4;

int main()
{
	/*
	Soldier soldier = Soldier();
	StaffMember staff_member = StaffMember();
	std::cout << soldier << std::endl;
	std::cout << staff_member << std::endl;
	Crew crew = Crew();
	return 0;
	*/

	int rc;
	TrainingDescriptor a;

	try
	{
		while (rc = dialog::Dialog::dialog())
		{
			dialog::Dialog::fptr[rc](a);
			std::cout << std::endl;
		}
	}
	catch (char* msg)
	{
		std::cout << msg;
		return 0;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
	catch (...)
	{
		std::cout << "Exit\n";
		return 0;
	}
	return 0;
}
