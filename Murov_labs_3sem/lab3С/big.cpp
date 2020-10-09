#include "big.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
namespace Prog3_1 {

	Big_Dec::Big_Dec()
	{
		dec = new char[2];
		n = 1;
		dec[0] = dec[1] = '0';
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
		delete[]dec;
		dec = new char[k + 1];
		n = k;
		for (int l = SZ; l >= SZ - k + 1; l--) {
			dec[l] = (char)(((int)'0') + ab % 10);
			ab /= 10;
		}
	}

	Big_Dec::Big_Dec(int a) :Big_Dec() {
		char sgn = a < 0 ? '9' : '0';
		a = a < 0 ? -a : a;
		int i = 10, k = 1;
		while (a / i > 0) {
			i *= 10;
			k++;
		}
		delete[]dec;
		dec = new char[k + 1];
		n = k;
		dec[0] = sgn;
		for (int l = k; l >= 1; l--) {
			dec[l] = (char)(((int)'0') + a % 10);
			a /= 10;
		}
	}

	Big_Dec::Big_Dec(int k, int) {
		n = k;
		if (k == 0)
			n++;
		dec = new char[n + 1];
		for (int i = 0; i <= n; i++)
			dec[i] = '0';
	}

	Big_Dec::Big_Dec(const char* str) :Big_Dec()
	{
		if (str == nullptr)
			throw - 1;
		bool zero = true;
		int l = strlen(str), z = 0;
		char znak;
		if (l > SZ)
			throw "Overflow";
		if (str[0] == '-') {
			znak = '9';
			z++;
			l--;
		}
		else znak = '0';
		if (l != strspn(str + (dec[0] == '9' ? 1 : 0), "0123456789"))
			throw "Data error!";
		while (zero && l > 0) {
			if (str[z] == '0') {
				z++;
				l--;
			}
			else zero = false;
		}
		if (!zero) {
			delete[]dec;
			dec = new char[l + 1];
			n = l;
			dec[0] = znak;
			for (int i = 1; i <= l; i++) {
				dec[i] = str[z];
				z++;
			}
		}

	}

	Big_Dec::Big_Dec(const Big_Dec& o, int m) {
		dec = new char[o.n + m + 1];
		dec[0] = o.dec[0];
		int i = 1;
		for (; i <= m; i++)
			dec[i] = '0';
		for (; i <= o.n + m; i++)
			dec[i] = o.dec[i - m];
		n = o.n + m;
	}

	Big_Dec::Big_Dec(const Big_Dec& orig) {
		try {
			n = orig.n;
			dec = new char[n + 1];
			for (int i = 0; i < n + 1; i++)
				dec[i] = orig.dec[i];
		}
		catch (...) {
			std::cout << "Empty initialization";
			n = 1;
			dec = new char[2];
			dec[0] = dec[1] = '0';
		}
	}

	const Big_Dec Big_Dec::operator~() const
	{
		if (dec[0] == '0')
			return *this;
		bool pr = true;//"запас" перенос +1 в след 
		Big_Dec res(n,1);
		for (int i = n; i > 0; i--) {
			if (pr && dec[i] != '0') {
				res.dec[i] = (char)10 - (dec[i] - '0') + '0';
				pr = false;
			}
			else if (!pr)
				res.dec[i] = (char)9 - (dec[i] - '0') + '0';
			else res.dec[i] = '0';
		}
		res.dec[0] = '9';
		return res;
	}

	std::ostream& operator <<(std::ostream& c, const Big_Dec& the)
	{
		if (the.dec[0] == '9')
			c << "-";
		//std::cout << "\nn = " << the.n << " dec[0] = " << (char)the.dec[0] << '\n';
		int i;
		if (the.dec[0] == '0') i = 1;
		else i = 0;
		for (i = 1; i <= the.n; i++)
			c << the.dec[i];
		std::cout << '\n';
		return c;
	}

	std::istream& operator>>(std::istream& i, Big_Dec& the)
	{
		char* p = new char[255];
		i >> p;
		char znak;
		bool zero = true;
		int l = strlen(p), z = 0;
		if (p[0] == '-') {
			znak = '9';
			z++;
			l--;
		}
		else znak = '0';

		if (l != strspn(p + (znak == '9' ? 1 : 0), "0123456789"))
			throw "Data error!";
		while (zero && l > 0) {
			if (p[z] == '0') {
				z++;
				l--;
			}
			else zero = false;
		}
		if (zero) {
			delete[]the.dec;
			the.n = 1;
			the.dec = new char[2];
			the.dec[0] = the.dec[1] = '0';
		}
		else {
			delete[]the.dec;
			the.dec = new char[l + 1];
			the.n = l;
			the.dec[0] = znak;
			for (int i = 1; i <= l && z <= l; i++) {
				the.dec[i] = p[z];
				z++;
			}
		}
		delete[]p;
	}

	Big_Dec& Big_Dec::operator= (const Big_Dec& ob) {
		if (this->dec != ob.dec) {
			if (dec != nullptr)
				delete[]dec;
			if (ob.n != 0) {
				n = ob.n;
				dec = new char[ob.n + 1];
				for (int i = 0; i <= n; i++)
					dec[i] = ob.dec[i];

			}
		}
		return*this;
	}

	Big_Dec& Big_Dec::operator= (Big_Dec&& ob) noexcept {
		if (dec != nullptr) {
			delete[]dec;
			dec = ob.dec;
			n = ob.n;
			ob.dec = nullptr;
		}
		return*this;
	}

	Big_Dec operator+(const Big_Dec& o, const Big_Dec& t)
	{
		Big_Dec slg1(o, o.n > t.n ? 1 : t.n - o.n + 1), slg2(~t);
		slg1 = ~slg1;
		int  pr = 0;
		for (int i = slg1.n; i > slg1.n - slg2.n; i--) {
			if (slg1.dec[i] - '0' + slg2.dec[i + slg2.n - slg1.n] - '0' + pr < 10) {
				slg1.dec[i] = (char)slg1.dec[i] - '0' + slg2.dec[i + slg2.n - slg1.n] - '0' + pr + '0';
				pr = 0;
			}
			else {
				slg1.dec[i] = (char)slg1.dec[i] - '0' + slg2.dec[i + slg2.n - slg1.n] - '0' + pr + '0' - 10;
				pr = 1;
			}
		}
		char dop = slg2.dec[0] == '0' ? '0' : '9';
		for (int i = slg1.n - slg2.n; i >= 0; i--) {
			if (slg1.dec[i] - '0' + dop - '0' + pr < 10) {
				slg1.dec[i] = (char)slg1.dec[i] + pr + dop - '0';
				pr = 0;
			}
			else {
				slg1.dec[i] = (char)slg1.dec[i] - '0' + dop - '0' + pr + '0' - 10;;
				pr = 1;
			}
		}
		slg1 = ~slg1;
		while (slg1.dec[1] == '0' && slg1.n > 1) {
			slg1.dec[0] = (slg1.dec[0] == '9' ? '9' : '0');
			for (int i = 1; i < slg1.n; i++)
				slg1.dec[i] = slg1.dec[i + 1];
			slg1.dec[slg1.n] = '\0';
			slg1.n--;
		}
		//std::cout << slg1.n << std::endl;
		Big_Dec res(slg1, 0);
		for (int i = 0; i <= res.n; ++i)
			std::cout << res.dec[i];
		std::cout << std::endl;
		return res;
	}

	const Big_Dec Big_Dec::operator-() const {
		Big_Dec res = *this;
		for (int i = 0; i <= n; i++) {
			if (dec[i] != '0') {
				res.dec[0] = dec[0] == '0' ? '9' : '0';
				break;
			}
		}
		/*for (int i = 0; i <= res.n; ++i)
			std::cout << res.dec[i];
		std::cout << std::endl;*/
		return res;
	}

	Big_Dec Big_Dec::mult() const
	{
		if (n > 1 || dec[1] != '0') {
			Big_Dec res(n + 1, 1);
			for (int i = 0; i <= n; i++)
				res.dec[i] = dec[i];
			res.dec[n + 1] = '0';
			return res;
		}
		else
			return *this;
	}

	Big_Dec Big_Dec::div() const
	{
		//int b = 0;
		bool zero = true;
		Big_Dec res(n - 1, 1);
		for (int i = 0; i < n; i++) {
			res.dec[i] = dec[i];
			if (zero && i > 0 && dec[i] != '0')
				zero = false;
		}
		if (zero) {
			res.dec[0] = '0';
			res.n = 1;
			return res;
		}
		return res;
	}

	Big_Dec::operator int() const {
		int i = 0;
		int pow = 1;
		if (n > 8)
			throw - 1;
		for (int k = n; k >= 1; k--) {
			i += (dec[k] - '0') * pow;
			pow *= 10;
		}
		i = dec[0] == '0' ? i : -i;
		return i;
	}
}