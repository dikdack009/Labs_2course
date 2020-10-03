#include <iostream>
#include "big.h"

using namespace Prog3_1;

int main()
{
	long int buf = 135676, etc = -134;
	Big_Dec a("0"), b(etc), c, d;
	//a.print();
	while (true)
	{
		std::cout << "a   : ";
		a = a.input();
		//a.print();
		std::cout << "b   : ";
		b = b.input();
		//b.print();
		std::cout << '\n';
		std::cout << "a+b : ";
		c = a.sum(b);
		c.print();
		std::cout << "a-b : ";
		c = a.dif(b);
		c.print();
		std::cout << "a*10: ";
		c = a.mult();
		c.print();
		std::cout << "a/10: ";
		c = a.div();
		c.print();
		std::cout << "b*10: ";
		c = b.mult();
		c.print();
		std::cout << "b/10: ";
		c = b.div();
		c.print();
		std::cout << "\nContinue? (1 - yes, 0 - no) --> ";
		short q;
		std::cin >> q;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (q == 0) break;
	}
}