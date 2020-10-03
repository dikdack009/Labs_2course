#include <strstream>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#define graphic(x,a) (a*cosh(x / a)) //график который будет строится

#include "Chain_line.h"

namespace Chain {
	// при задании цепной линии параметр а не должен равняться 0, в противном случае - исключение
	Chain::Chain(double x)
	{
		if (x == 0)
			throw std::exception("invalid param a");
		a = x;
	}
	Chain& Chain::set_a(double x)
	{
		if (x == 0)
			throw std::exception("invalid param a");
		a = x;
		return *this;
	}
	Point Chain::center(double x) const
	{
		double y = f(x);
		double y1 = sinh(x / a);
		double y2 = f(x) / (a * a);
		Point res;
		res.x = x - (y1 * (1 + y1 * y1) / y2);
		res.y  = y + ((1 + y1 * y1) / y2);
		return res;
	}
	Point Chain::get_proj() const
	{
		Point res;
		double x1, x2;
		std::cout << "Enter x1 and x2 (suspension abscesses):  ";
		std::cin >> x1;
		std::cin >> x2;
		if (x2 > x1){
			res.x = x2;
			res.y = x1;
		}
		else {
			res.x = x1;
			res.y = x2;
		}
		return res;
	}
	void Chain::paint()const
	{
		float x;
		HDC hDC = GetDC(GetConsoleWindow());
		HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
		SelectObject(hDC, Pen);
		MoveToEx(hDC, 0, 85, NULL);
		LineTo(hDC, 200, 85);
		MoveToEx(hDC, 100, 0, NULL);
		LineTo(hDC, 100, 170);
		for (x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - center
		{
			MoveToEx(hDC, 10 * x + 100, -15 * graphic(x, a) + 85, NULL);//10 - scale
			LineTo(hDC, 10 * x + 100, -15 * graphic(x, a) + 85);
		}
	}
}	