#include "big.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
namespace Prog3_1 {

	Big_Dec::Big_Dec()
	{
		for (int i = 0; i < SZ+1; ++i) dec[i] = '0';
		n = 1;
	}

	Big_Dec::Big_Dec(long int a) :Big_Dec()
	{
		int count = 0;
		long int ab = a;
		dec[0] = a < 0 ? '9' : '0';
		ab = a < 0 ? -a : a;
		int i = 10, k = 1;
		while (ab / i > 0) {
			i *= 10;
			k++;
		}
		for (int l = 1; l <= SZ - k + 1; l++)
			dec[l] = '0';
		for (int l = SZ; l >= SZ - k + 1; l--) {
			dec[l] = (char)(((int)'0') + ab % 10);
			ab /= 10;
			++count;
		}
		n = count;
	}

	Big_Dec::Big_Dec(const char* str) :Big_Dec()
	{
		if (str == nullptr)
			throw - 1;
		bool zero = true;
		int l = strlen(str), z = 0;
		n = l;
		if (l > SZ)
			throw "Overflow";
		if (str[0] == '-') {
			dec[0] = '9';
			z++;
			l--;
		}
		else dec[0] = '0';
		if (l != strspn(str + (dec[0] == '9' ? 1 : 0), "0123456789"))
			throw "Data error!";
		for (int k = 1; k <= SZ - l; k++) {
			dec[k] = '0';
		}
		for (int k = SZ - l + 1; k <= SZ; k++) {
			dec[k] = str[z];
			z++;
			if (zero && dec[k] != '0')
				zero = false;
		}
		if (zero)
			dec[0] = '0';

	}

	const Big_Dec Big_Dec::operator~() const
	{
		if (dec[0] == '0')
			return *this;
		bool pr = true;//"запас" перенос +1 в след 
		Big_Dec res;
		for (int i = SZ; i >= 0; i--) {
			if (pr && dec[i] != '0') {
				res.dec[i] = (char)10 - (dec[i] - '0') + '0';
				pr = false;
			}
			else if (!pr)
				res.dec[i] = (char)9 - (dec[i] - '0') + '0';
		}
		if (dec[SZ] == '0') res.dec[SZ] = '0';
		res.dec[0] = '9';
		return res;
	}

	std::ostream& operator <<(std::ostream& c, const Big_Dec& the)
	{
		if (the.dec[0] == '9')
			c << "-";
		bool print = false;
		for (int i = 1; i <= the.SZ; i++) {
			if (!print && the.dec[i] != '0')
				print = true;
			if (print)
				c << the.dec[i];
		}
		if (!print)
			c << '0';
		c << std::endl;
		return c;
	}

	std::istream& operator>>(std::istream& i, Big_Dec& the)
	{
		char n[the.SZ + 1];
		i >> n;
		bool zero = true;
		int l = strlen(n), z = 0;
		the.n = l;
		if (l > the.SZ)
			throw "Overflow";
		if ((l - (n[0] == '-' ? 1 : 0)) != strspn(n + (n[0] == '-' ? 1 : 0), "0123456789"))
			throw "Data error!";
		if (n[0] == '-') {
			the.dec[0] = '9';
			z++;
			l--;
		}
		else the.dec[0] = '0';
		for (int k = 1; k <= the.SZ - l; k++) {
			the.dec[k] = '0';
		}
		for (int k = the.SZ - l + 1; k <= the.SZ; k++) {
			the.dec[k] = n[z];
			z++;
			if (zero && the.dec[k] != '0')
				zero = false;
		}
		if (zero)
			the.dec[0] = '0';
	}
	
	Big_Dec operator+(const Big_Dec& o, const Big_Dec& t)
	{
		bool prInd = (o.dec[0] == t.dec[0]);
		Big_Dec slg1(~o), slg2(~t);
		int pr = 0;
		for (int i = o.SZ; i >= 0; i--) {
			if (slg1.dec[i] - '0' + slg2.dec[i] - '0' + pr < 10) {
				slg1.dec[i] = (char)slg1.dec[i] - '0' + slg2.dec[i] - '0' + pr + '0';
				pr = 0;
			}
			else {
				slg1.dec[i] = (char)slg1.dec[i] - '0' + slg2.dec[i] - '0' + pr + '0' - 10;
				pr = 1;
			}
		}
		if (pr > 0 && prInd && slg1.dec[1] == '0')
			throw - 1;
		slg1 = ~slg1;
		slg1.n = slg1.n > slg2.n ? slg1.n : slg2.n;
		//std::cout << slg1.n << '\n';
		return slg1;

	}

	const Big_Dec Big_Dec::operator-() const {
		Big_Dec res = *this;
		for (int i = 0; i <= SZ; i++) {
			if (dec[i] != '0') {
				res.dec[0] = dec[0] == '0' ? '9' : '0';
				break;
			}
		}
		res.n = n;
		return res;
	}

	Big_Dec Big_Dec::mult() const
	{
		Big_Dec t;
		//std::cout << n << '\n';
		if (dec[1] != '0')
			throw  1;
		for (int i = SZ - n; i < SZ; i++)
			t.dec[i] = dec[i + 1];
		t.dec[SZ] = '0';
		t.dec[0] = dec[0];
		t.n = n + 1;
		bool check = true;
		for (int i = 1; i < SZ + 1; ++i) if (t.dec[i] != '0') check = false;
		if (check) (t.n)--;
		//std::cout << t.n << '\n';
		return t;
	}

	Big_Dec Big_Dec::div() const
	{
		Big_Dec res;
		bool zero = true;
		for (int i = SZ; i >= SZ + 1 - n; i--) {
			res.dec[i] = dec[i - 1];
			if (zero && (dec[i] != '0' || dec[i - 1] != '0'))
				zero = false;
		}
		res.dec[0] = dec[0];
		res.dec[1] = '0';
		if (zero)
			 res.dec[0] = '0';
		res.n = n - 1;
		bool check = true;
		for (int i = 1; i < SZ + 1; ++i) if (res.dec[i] != '0') check = false;
		if (check) res.n++;
		//std::cout << res.n << '\n';
		return res;
	}
}