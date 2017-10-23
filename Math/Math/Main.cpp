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

double getPi1(int index, int end, double *a_doubles)
{
	double pi = a_doubles[index++];
	if (index >= end)
		return pi;
	return pi + (1 / getPi1(index, end, a_doubles));
}

double getPi2(double nr, double end)
{
	if (nr >= end)
		return 6;
	return 6 + (pow(nr, 2) / getPi2(nr + 2, end));
}

void test3()
{
	const int amount = 1000;
	int index = 0;
	int end = amount - 1;
	double *a_doubles = new double[amount];
	//double a_doubles[amount];

	a_doubles[0] = 3;
	a_doubles[1] = 7;
	a_doubles[2] = 15;
	a_doubles[3] = 1;
	a_doubles[4] = 292;

	for (int i = 5; i < amount; i++)
	{
		a_doubles[i] = 1;
	}

	double pi1 = getPi1(index, end, a_doubles);

	delete[] a_doubles;

	//std::cout << "PI = " << pi << '\n';
	printf("PI = %.40f\n", pi1);

	double pi2 = 3 + (1 / getPi2(3, 5000));

	printf("PI = %.40f\n", pi2);
}

int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}