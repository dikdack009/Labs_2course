#include "big.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
namespace Prog3_1 {

	Big_Dec::Big_Dec()
	{
		dec[0] = '0';
		for (int i = 1; i < SZ+1; ++i) dec[i] = '0';
		n = 1;
	}

	int Big_Dec::count(long int x) const
	{
		long z = abs(x);
		int count = 0;
		while (z)
		{
			++count;
			z /= 10;
		}
		return count;
	}

	Big_Dec::Big_Dec(long int a)
	{
		try {
			n = count(a);
			long int ab = a;
			dec[0] = a < 0 ? '9' : '0';
			ab = a < 0 ? -a : a;
			int i = 10, k = 1;
			while (ab / i > 0) {
				i *= 10;
				k++;
			}
			if (k > SZ)
				throw "Overflow";
			for (int l = 1; l <= SZ - k + 1; l++)
				dec[l] = '0';
			for (int l = SZ; l >= SZ - k + 1; l--) {
				dec[l] = (char)(((int)'0') + ab % 10);
				ab /= 10;
			}
		}
		catch (...) {
			std::cout << "Your value is bigger then MaxSize." << std::endl;
		}
	}

	Big_Dec::Big_Dec(const char* str)
	{
		try {
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
		catch (const char* a) {
			if (a == "Overflow")
				std::cout << "Too big number!" << std::endl;
			if (a == "Data error!") {
				std::cout << "The number should include only '-'at the begin and '0-9' chars." << std::endl;
				dec[0] = '0';
			}
		}
		catch (...) {
			std::cout << "Nullptr" << std::endl;
		}
	}

	const Big_Dec Big_Dec::convert() const
	{
		if (dec[0] == '0')
			return *this;
		bool pr = true;//"запас" перенос +1 в след 
		Big_Dec res;
		/*std::cout <<"1:\n";
		for (int i = 0; i <= SZ; ++i)
			std::cout << dec[i];
		std::cout << std::endl;*/
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
		/*std::cout << "2:\n";
		//std::cout << "dec[SZ] = " << dec[SZ] << std::endl;
		for (int i = 0; i <= SZ; ++i)
			std::cout << res.dec[i];
		std::cout << std::endl;*/
		return res;
	}

	void Big_Dec::print() const
	{
		/*for (int i = 0; i <= SZ; ++i)
			std::cout << dec[i];
		std::cout << std::endl;*/
		if (dec[0] == '9')
			std::cout << "-";
		bool print = false;
		for (int i = 1; i <= SZ; i++) {
			if (!print && dec[i] != '0')
				print = true;
			if (print)
				std::cout << dec[i];
		}
		if (!print)
			std::cout << '0';
		std::cout << std::endl;
	}

	Big_Dec Big_Dec::input() const
	{
		try {
			//char buf[SZ + 1];
			char* ptr = (char*)malloc(1);
			char buf[81];
			int n;
			unsigned int len = 0;
			*ptr = '\0';
			do
			{
				n = scanf_s("%80[^\n]", buf, 81);
				if (n < 0)
				{
					free(ptr);
					ptr = NULL;
					continue;
				}
				if (n == 0)
					scanf_s("%*c");
				else
				{
					len += strlen(buf);
					ptr = (char*)realloc(ptr, len + 1);
					strcat_s(ptr, len + 1, buf);
				}
			} while (n > 0);
			if (strlen(ptr) > SZ + 1)
			{
				std::cout << "Too big number!" << std::endl;
				Big_Dec b("0");
				return b;
			}
			Big_Dec a(ptr);
			return a;
		}
		catch (const char* a) {
			if (a == "Overflow")
				std::cout << "Too big number!" << std::endl;
			if (a == "Data error!") {
				std::cout << "The number should include only '-'at the begin and '0-9' chars." << std::endl;
			}
		}
		catch (...) {
			std::cout << "Nullptr" << std::endl;
		}
	}
	
	Big_Dec Big_Dec::sum( Big_Dec &t)const 
	{
		try {
			bool prInd = (dec[0] == t.dec[0]);
			Big_Dec slg1 = *this, slg2(t.convert()); 
			slg1 = slg1.convert();
			
			slg1.n = n;
			int pr = 0;
			for (int i = SZ; i >= 0; i--) {
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
			slg1 = slg1.convert();
			return slg1;
		}
		catch (...) {
			std::cout << "Overflow!!!" << std::endl;
			return '0';
		}
	}

	Big_Dec Big_Dec::dif(Big_Dec t) const
	{
		Big_Dec res = t, r = *this;
		for (int i = 0; i <= SZ; i++) {
			if (dec[i] != '0') {
				if (t.dec[0] == '0') res.dec[0] = '9';
				else res.dec[0] = '0';
				break;
			}
		}
		r = r.sum(res);
		bool check = false;
		for (int i = 0; i <= SZ; i++) if (dec[i] != '0') check = true;
		if (!check) { r.dec[0] = '9'; return r; }
		check = false;
		for (int i = 1; i <= SZ; i++) if (res.dec[i] != '0') check = true;
		if (!check) r = *this;
		return r;
	}
	Big_Dec Big_Dec::mult() const
	{
		try{
			Big_Dec t;
			if (dec[1] != '0')
				throw  1;
			for (int i = 2; i < SZ; i++)
				t.dec[i] = dec[i + 1];
			t.dec[SZ] = '0';
			t.dec[0] = dec[0];
			t.n = n + 1;
			return t;
		}
		catch (...) {
			std::cout << "Overflow!!!!" << std::endl;
			return *this;
		}
	}
	Big_Dec Big_Dec::div() const
	{
		Big_Dec res;
		int n = 0;
		bool zero = true;
		for (int i = SZ; i > 1; i--) {
			res.dec[i] = dec[i - 1];
			if (zero && (dec[i] != '0' || dec[i - 1] != '0'))
				zero = false;
		}
		res.dec[0] = dec[0];
		res.dec[1] = '0';
		if (zero)
			 res.dec[0] = '0';
		return res;
	}
}