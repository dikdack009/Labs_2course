#pragma once

#ifndef _BIG_DEC_
#define _BIG_DEC_

#include <iostream>
namespace Prog3_1 {
	class Big_Dec {
	private:
		static const int SZ = 47;
		char dec[SZ + 1];
		int n;
	public:
		Big_Dec(); // пустой конструктор
		Big_Dec(long int x); // конструктор с инициализацией значением целого длинного (типа long)
		Big_Dec(const char* str); // конструктор с инициализацией значением числа как строки символов
		const Big_Dec operator~() const; // перегрузка оператора (перевод в доп код)
		friend std::ostream& operator <<(std::ostream& c, const Big_Dec&); // вывод
		friend std::istream& operator >> (std::istream& i, Big_Dec&); // ввод
		friend Big_Dec operator +(const Big_Dec&, const Big_Dec&); // перегрузка оператора суммы
		const Big_Dec operator-() const; // меняет знак числа 
		friend Big_Dec operator -(const Big_Dec& a, const Big_Dec& b) { return a + (-b); }; // возвращает разность двух чисел 
		friend Big_Dec& operator +=(Big_Dec& left, const Big_Dec& right) { left = left + right; return left; };
		friend Big_Dec& operator -=(Big_Dec& left, const Big_Dec& right) { left = left + (-right); return left; };
		Big_Dec mult() const; // умножение (без перегрузки)
		Big_Dec div() const; // деление (без перегрузки)
	};
}
#endif
