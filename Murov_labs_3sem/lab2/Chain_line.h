#pragma once
#ifndef _CHAIN_H_
#define _CHAIN_H_
#include <cmath>

namespace Chain {

	// ��������� Point ����� ���������� ����� �� ��������� 
	struct Point {
		double x, y; // ���������� ����� �� ���������
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	};
	//-----------------------------------------------------//
	// ����� Chain ���������� ������ �����
	class Chain {
	private:
		double a;	// �������� ������ �����
	public:
		Chain(double x = 1); // ������ � ���������������� �����������
		double get_a() const { return a; } // ������ ��� ������ ��������� ��������� � 
		Chain& set_a(double x); // ������ ��� ������ ��������� �
		// ��������� ������
		double perimetr(double x1, double x2) const { return a * (sinh(x2 / a) - sinh(x1 / a)); } // ����� ���� ������ ����� 
		double radius(double x) const { return a * cosh(x / a) * cosh(x / a); } // ������ �������� ������ ����� 
		double area(double x1, double x2) const { return a * a * (sinh(x2 / a) - sinh(x1 / a)); } // ������� ������������� �������� ������������ ������ ������	
		Point center(double x)const; // ���������� ������ 
		double f(double x)const { return a * cosh(x / a); }; // �������� ������� � ����� 
		// ��������������� ������
		Point get_proj() const; // ������ �� �������� ������ �������� �� ��� ������
		void paint()const; // ������ ������

	};
}
#endif