#ifndef MILITARY
#define MILITARY

#include <string>
#include "structs.h"

namespace task_4
{
	class Military					// Военный
	{
	public:
		Military();
		Military(std::string, Rank, unsigned int);
		virtual std::string		GetName() const { return name; }
		void			SetName(std::string);
		unsigned int	GetUniformSize() const { return uniformSize; }
		void			SetUniformSize(unsigned int);
		Rank			GetRank() const { return rank; }
		void			SetRank(const Rank);
		virtual unsigned int	GetId() const { return id; }
		virtual void	Print(std::ostream&) const = 0;
		virtual void	Read(std::istream&) = 0;
		virtual std::string		GetHTML() = 0;

	private:
		std::string		name;
		Rank			rank;
		unsigned int	uniformSize;
		unsigned int	id;
		static unsigned int new_id;
	protected:
		friend std::ostream& operator<< (std::ostream&, const Military&);
		friend std::istream& operator>> (std::istream&, Military&);
	};
}

#endif // !MILITARY
