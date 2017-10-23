#pragma once
#include <iostream>

class Fraction
{
private:
	long long m_numerator;
	long long m_denominator;
	void multiplyFractions(long long num_rhs, long long denom_rhs);
	void shortenFraction(long long& num, long long& denom);
public:
	Fraction();
	Fraction(const Fraction& other);
	Fraction(long long l);
	Fraction(long long numerator, long long denominator);

	Fraction& operator=(const Fraction& rhs);
	Fraction& operator=(const long long& rhs);

	Fraction& operator+=(const Fraction& rhs);
	Fraction& operator+=(const long long& rhs);

	Fraction& operator+(const Fraction& rhs);
	Fraction& operator+(const long long& rhs);

	Fraction& operator-=(const Fraction& rhs);
	Fraction& operator-=(const long long& rhs);

	Fraction& operator-(const Fraction& rhs);
	Fraction& operator-(const long long& rhs);

	Fraction& operator*=(const Fraction& rhs);
	Fraction& operator*= (const long long& rhs);

	Fraction& operator*(const Fraction& rhs);
	Fraction& operator*(const long long& rhs);

	Fraction& operator/=(const Fraction& rhs);
	Fraction& operator/=(const long long& rhs);

	Fraction& operator/(const Fraction& rhs);
	Fraction& operator/(const long long& rhs);

	void sf();

	friend std::ostream& operator<<(std::ostream& s, const Fraction& f);
};