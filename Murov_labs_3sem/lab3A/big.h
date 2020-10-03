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
		int count(long int x) const; // метод считает кол-личество цифр в числе
		const Big_Dec convert() const;
		void print() const;
		Big_Dec input() const;
		Big_Dec sum(Big_Dec &t) const;
		Big_Dec dif(Big_Dec) const;
		Big_Dec mult() const;
		Big_Dec div() const;
	};
}
#endif
