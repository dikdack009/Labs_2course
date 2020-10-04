#include <iostream>
#include "big.h"

using namespace Prog3_1;

int main()
{
	char x[] = "-0002";
	Big_Dec* a = new Big_Dec, * b = new Big_Dec(12345);
	Big_Dec c;
	
	try {
		Big_Dec a(x);
	}
	catch (const char* k) {
		if (k == "Overflow")
			std::cout << "Too big number!" << std::endl;
		if (k == "Data error!")
		{
			std::cout << "The number should include only '-'at the begin and '0-9' chars. \"a\" inint by previous a = ";
			std::cout << *a;
		}
	}
	catch (...) {
		std::cout << "Nullptr" << std::endl;
		Big_Dec(*a);
	}
	std::cout << "a   : " << *a;
	std::cout << "b   : " << *b;
	while (true)
	{
		try {
			std::cout << "a+b : " << *a + *b;
		}
		catch (...) {
			std::cout << "Overflow!!!" << std::endl;
			continue;
		}
		std::cout << "a-b : " << *a - *b;
		std::cout << "b-a : " << *b - *a;
		try {
			std::cout << "a*10: " << (*a).mult();
		}
		catch (...) {
			std::cout << "Overflow!!!!" << std::endl;
			continue;
		}
		std::cout << "a/10: " << (*a).div();
		try {
			std::cout << "b*10: " << (*b).mult();
		}
		catch (int a) {
			std::cout << "Overflow!!!!" << std::endl;
			continue;
		}
		std::cout << "b/10: " << (*b).div();
		std::cout << "\nContinue? (1 - yes, 0 - no) --> ";
		short q;
		std::cin >> q;
		std::cin.clear();
		if (q == 0) break;
		std::cout << "\na   : ";
		try {
			std::cin >> *a;
		}
		catch (const char* k) {
			if (k == "Overflow")
				std::cout << "Too big number!" << std::endl;
			if (k == "Data error!")
			{
				std::cout << "The number should include only '-'at the begin and '0-9' chars. \"a\" inint by previous a = ";
				std::cout << *a;
			}
		}
		catch (...) {
			std::cout << "Nullptr" << std::endl;
		}
		std::cout << "b   : ";
		try {
			std::cin >> *b;
		}
		catch (const char* k) {
			if (k == "Overflow")
				std::cout << "Too big number!" << std::endl;
			if (k == "Data error!")
			{
				std::cout << "The number should include only '-'at the begin and '0-9' chars. \"b\" inint by previous b = ";
				std::cout << *b;
			}
		}
		catch (...) {
			std::cout << "Nullptr" << std::endl;
		}
		std::cin.clear();
	}
	return 0;
}