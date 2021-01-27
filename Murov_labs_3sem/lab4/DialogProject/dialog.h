#ifndef DIALOG
#define DIALOG
#include "../Task4Lib/task_4.h"
#include <fstream>

using namespace task_4;

namespace dialog
{

	extern int NMsgs;
	extern const char* Msgs[];

	class Dialog
	{
	public:
		static std::string Msgs[];
		static int NMsgs;
		static void (*fptr[])(TrainingDescriptor&);

		static void Show(TrainingDescriptor&);
		static void AddTraining(TrainingDescriptor&);
		static void AddMilitary(TrainingDescriptor&);
		static void CountMilitary(TrainingDescriptor&);
		static void DeleteMilitary(TrainingDescriptor&);
		static void ChangeStage(TrainingDescriptor&);
		
		static void ResetCrew(TrainingDescriptor&); // TODO

		static void GetHTML(TrainingDescriptor&);
		
		static int	dialog();
	};
}

#endif // !DIALOG
