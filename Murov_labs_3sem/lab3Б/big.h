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
		Big_Dec(); // ������ �����������
		Big_Dec(long int x); // ����������� � �������������� ��������� ������ �������� (���� long)
		Big_Dec(const char* str); // ����������� � �������������� ��������� ����� ��� ������ ��������
		const Big_Dec operator~() const; // ���������� ��������� (������� � ��� ���)
		friend std::ostream& operator <<(std::ostream& c, const Big_Dec&); // �����
		friend std::istream& operator >> (std::istream& i, Big_Dec&); // ����
		friend Big_Dec operator +(const Big_Dec&, const Big_Dec&); // ���������� ��������� �����
		const Big_Dec operator-() const; // ������ ���� ����� 
		friend Big_Dec operator -(const Big_Dec& a, const Big_Dec& b) { return a + (-b); }; // ���������� �������� ���� ����� 
		friend Big_Dec& operator +=(Big_Dec& left, const Big_Dec& right) { left = left + right; return left; };
		friend Big_Dec& operator -=(Big_Dec& left, const Big_Dec& right) { left = left + (-right); return left; };
		Big_Dec mult() const; // ��������� (��� ����������)
		Big_Dec div() const; // ������� (��� ����������)
	};
}
#endif
