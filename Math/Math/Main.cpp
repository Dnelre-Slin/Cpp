#include <iostream>
#include <string>
#include "DoubleFraction.h"
#include "Fraction.h"

void test(double d)
{
	d++;
}

void test1()
{
	std::cout << 3.0 / 4.0 << '\n';
	try
	{
		DoubleFraction f(2, 3);
		f = (2.0 / 3.0);

		f.doPrint();

		f ^= 2;

		f.doPrint();

		f += 2;

		f.doPrint();

		f += 1.23456789;

		f.doPrint();

		f -= 1.23456789;

		f.doPrint();

		double d1 = f;

		test(f);

		std::string s1 = (std::string)f;

		std::cout << "Double: " << d1 << '\n';


		if (d1 == f)
		{
			std::cout << s1 << "SNAPP!!!\n";
		}
		DoubleFraction f2(2, 1);

		f = 3;
		std::cout << "-> " << 4.0 + f << '\n';
		f2 = 3.0 + 4.0 + f;
		std::cout << '\n' << f2 << '\n';
	}
	catch (std::exception e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
}

void test2()
{
	Fraction f(2, 3);

	std::cout << f << '\n';

	Fraction f2(5, 6);

	f *= f2;
	std::cout << f << '\n';

	f *= 3;

	std::cout << f << '\n';


}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}