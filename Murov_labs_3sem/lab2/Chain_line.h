#pragma once
#ifndef _CHAIN_H_
#define _CHAIN_H_
#include <cmath>

namespace Chain {

	// Стурктура Point задаёт координаты точки на плоскости 
	struct Point {
		double x, y; // координаты точки на плоскости
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	};
	//-----------------------------------------------------//
	// класс Chain определяет цепную линию
	class Chain {
	private:
		double a;	// параметр цепной линии
	public:
		Chain(double x = 1); // пустой и инициализирующий конструктор
		double get_a() const { return a; } // геттер для чтения закрытого параматра а 
		Chain& set_a(double x); // сеттер для записи параметра а
		// остальные методы
		double perimetr(double x1, double x2) const { return a * (sinh(x2 / a) - sinh(x1 / a)); } // длина дуги цепной линии 
		double radius(double x) const { return a * cosh(x / a) * cosh(x / a); } // радиус кривизны цепной линии 
		double area(double x1, double x2) const { return a * a * (sinh(x2 / a) - sinh(x1 / a)); } // площадь криволинейной трапеции образованной цепной линией	
		Point center(double x)const; // координаты центрв 
		double f(double x)const { return a * cosh(x / a); }; // значение функции в точке 
		// вспомогательные методы
		Point get_proj() const; // вводит из входного потока проекции на ось абцисс
		void paint()const; // рисует график

	};
}
#endif