#ifndef TRAINING
#define TRAINING

#include "../Custom_List/custom_list.h"
#include "commander.h"
#include <sstream>

namespace task_4
{
	class Training
	{
	public:
		Training(std::string, std::string, Commander*, Commander*);
		Military&		GetMilitary(size_t);
		unsigned int	Count();				// TODO: +2 ?
		unsigned int	Count(bool first);
		unsigned int	Count(Rank);
		void			Add(Military*, Health, bool);	// bool is true for "To the first crew" and false otherwise
		void			Delete(unsigned int militaryId);
		void			ResetCrew(unsigned int militaryId, bool first);
		void			ChangeStatus(unsigned int, Health);
		std::string		GetHTML(unsigned int);
		friend std::ostream& operator<<(std::ostream&, const Training&);
	private:
		Commander*		commander1;
		Commander*		commander2;
		std::string		place;
		std::string		length;
	};


	class TrainingDescriptor 
	{
	public:
		custom_list::List<Training> trainingList;
		std::string GetHTML();
	};
}

#endif // !TRAINING
