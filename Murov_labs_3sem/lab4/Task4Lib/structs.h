#ifndef STRUCTS
#define STRUCTS

#include <string>
#include <iostream>

namespace task_4
{

	bool TryParseUint(std::string& input, unsigned int& output);
	bool TryParse(std::string& input, int& output);
	void GetInt(int& a, const char* msg, std::istream& in = std::cin);
	void GetUInt(unsigned int& a, const char* msg, std::istream& in = std::cin);
	

	class Command			// Команда
	{
	public:
		std::string GetCommand() const { return text; }
		friend std::istream& operator>>(std::istream&, Command&);
	private:
		std::string text;
	};

	class Instruction		// Инструкция
	{
	public:
		std::string		GetInstruction() const { return text; }
		unsigned int	GetId() { return id; }
		friend std::ostream& operator<<(std::ostream&, const Instruction&);
		friend std::istream& operator>>(std::istream&, Instruction&);
	private:
		unsigned int	id;
		std::string		text;
	};

	enum class Rank
	{
		Rank1,
		Rank2,
		Rank3
	};

	enum class Specialization {
		Infantry,		// Пехота
		SpecialForces,	// Спецназ
		Scout,			// Разведчик
		Sniper,			// Снайпер
		Sapper,			// Сапёр
		RCBP,			// РХБЗ
		Orderly,		// Санитар
		RadioOperator	// Радист
	};

	enum class Health
	{
		Healhy,
		Wounded,
		Dead,
		Lost
	};

	std::ostream& operator<< (std::ostream&, Rank);

	std::ostream& operator<< (std::ostream&, Health);

	std::ostream& operator<< (std::ostream&, Specialization);

	std::istream& operator>>(std::istream&, Rank&);
	std::istream& operator>>(std::istream&, Health&);
	std::istream& operator>>(std::istream&, Specialization&);


}
#endif // !STRUCTS
