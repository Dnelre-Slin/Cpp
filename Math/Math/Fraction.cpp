#include "Fraction.h"

void Fraction::multiplyFractions(long long num_rhs, long long denom_rhs)
{
	shortenFraction(m_numerator, denom_rhs);
	shortenFraction(num_rhs, m_denominator);
	m_numerator *= num_rhs;
	m_denominator *= denom_rhs;
}

void Fraction::shortenFraction(long long& num, long long& denom)
{
	if (num % denom == 0)
	{
		num /= denom;
		denom = 1;
		return;
	}
	long long temp = num / denom;
	num = num % denom;
	shortenFraction(denom, num);
	num = num + temp*denom;
}

Fraction::Fraction()
{
	m_numerator = 0;
	m_denominator = 1;
}

Fraction::Fraction(const Fraction & other)
{
	m_numerator = other.m_numerator;
	m_denominator = other.m_denominator;
}

Fraction::Fraction(long long l)
{
	m_numerator = l;
	m_denominator = 1;
}

Fraction::Fraction(long long numerator, long long denominator)
{
	m_numerator = numerator;
	m_denominator = denominator;
	shortenFraction(m_numerator, m_denominator);
}

Fraction& Fraction::operator=(const Fraction & rhs)
{
	m_numerator = rhs.m_numerator;
	m_denominator = rhs.m_denominator;
	return *this;
}

Fraction & Fraction::operator=(const long long & rhs)
{
	m_numerator = rhs;
	m_denominator = 1;
	return *this;
}

Fraction & Fraction::operator+=(const Fraction & rhs)
{
	long long low_lhs = m_denominator, low_rhs = rhs.m_denominator;
	shortenFraction(low_lhs, low_rhs);
	m_numerator = m_numerator*low_rhs + rhs.m_numerator*low_lhs;
	m_denominator *= low_rhs;
	shortenFraction(m_numerator, m_denominator);
	return *this;
}

Fraction & Fraction::operator+=(const long long & rhs)
{
	m_numerator += rhs*m_denominator;
	return *this;
}

Fraction & Fraction::operator+(const Fraction & rhs)
{
	Fraction copy = *this;
	return copy += rhs;
}

Fraction & Fraction::operator+(const long long & rhs)
{
	Fraction copy = *this;
	return copy += rhs;
}

Fraction & Fraction::operator-=(const Fraction & rhs)
{
	long long low_lhs = m_denominator, low_rhs = rhs.m_denominator;
	shortenFraction(low_lhs, low_rhs);
	m_numerator = m_numerator*low_rhs - rhs.m_numerator*low_lhs;
	m_denominator *= low_rhs;
	shortenFraction(m_numerator, m_denominator);
	return *this;
}

Fraction & Fraction::operator-=(const long long & rhs)
{
	m_numerator -= rhs*m_denominator;
	return *this;
}

Fraction & Fraction::operator-(const Fraction & rhs)
{
	Fraction copy = *this;
	return copy -= rhs;
}

Fraction & Fraction::operator-(const long long & rhs)
{
	Fraction copy = *this;
	return copy -= rhs;
}

Fraction & Fraction::operator*=(const Fraction & rhs)
{
	multiplyFractions(rhs.m_numerator, rhs.m_denominator);
	return *this;
}

Fraction & Fraction::operator*=(const long long & rhs)
{
	long long rhs_num = rhs;
	shortenFraction(rhs_num, m_denominator);
	m_numerator *= rhs_num;
	return *this;
}

Fraction & Fraction::operator*(const Fraction & rhs)
{
	Fraction copy = *this;
	return copy *= rhs;
}

Fraction & Fraction::operator*(const long long & rhs)
{
	Fraction copy = *this;
	return copy *= rhs;
}

Fraction & Fraction::operator/=(const Fraction & rhs)
{
	multiplyFractions(m_denominator, rhs.m_numerator);
	return *this;
}

Fraction & Fraction::operator/=(const long long & rhs)
{
	m_denominator *= rhs;
	return *this;
}

Fraction & Fraction::operator/(const Fraction & rhs)
{
	Fraction copy = *this;
	return copy /= rhs;
}

Fraction & Fraction::operator/(const long long & rhs)
{
	Fraction copy = *this;
	return copy *= rhs;
}

void Fraction::sf()
{
	shortenFraction(m_numerator, m_denominator);
}

std::ostream & operator<<(std::ostream & s, const Fraction & f)
{
	s << f.m_numerator;
	if (f.m_denominator != 1)
		s << '/' << f.m_denominator;
	return s;
}
