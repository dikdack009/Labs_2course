//Laboratory work 2 option 16
#include <iostream>
#include "Chain_line.h"
#include <tchar.h>


int _tmain(int argc, _TCHAR* argv[])
{
	double a = 1;
	int fl1 = 1;
	int i = 20;
	for (; i > 0; --i, std::cout << std::endl);
	std::cout << "Hello!\na = 1\n";
	Chain::Chain c(a);
	while (fl1) {
		c.paint();
		Chain::Point buf = c.get_proj();
		std::cout << "area: " << c.area(buf.y, buf.x) << std::endl;
		std::cout << "perimeter: " << c.perimetr(buf.y, buf.x) << std::endl;
		std::cout << "Enter x for calculate radius and center: ";
		double x_b;
		std::cin >> x_b;
		std::cout << "radius: " << c.radius(x_b) << "\ncenter: ("<< (c.center(x_b)).x <<";"<< (c.center(x_b)).y << ")\n";
		int fl2 = 1;
		std::cin.clear();
		while (fl2) {
			std::cout << "Enter x for calculate value y(x) or press ctrl+Z to quit:  ";
			double x;
			double y;
			std::cin >> x;
			fl2 = std::cin.good();
			if (!fl2)
				continue;
			try {
				y = c.f(x);
				std::cout << "y(x) = " << y << std::endl;
			}
			catch (std::exception & ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		std::cin.clear();
		std::cout << "Enter new \"a\" to continue or press ctrl+Z to quit:  ";
		std::cin >> a;
		if (std::cin.good()) {
			try {
				c.set_a(a);
			}
			catch (std::exception & ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		else
			fl1 = 0;
	}
	std::cout << "Goodbye!\n";
	return 0;
}