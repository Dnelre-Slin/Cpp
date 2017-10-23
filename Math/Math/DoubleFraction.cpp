#include <stdexcept>
#include <iostream>
#include "DoubleFraction.h"

bool DoubleFraction::doubleToDoubleFraction(const double& d1, DoubleFraction &ans)
{
	if ((long long)d1 != d1)
	{
		int i1 = 2;
		double d2 = d1 * i1;
		while (d2 < 1000000 && i1 < 1000000)
		{
			if (round(d2) == d2)
			{
				ans.m_numerator = (long long)(d1 * i1);
				ans.m_denominator = i1;
				return true;
			}
			d2 = d1 * ++i1;
		}
		ans.m_numerator = d1;
		ans.m_denominator = 1;
		return false;
	}
	ans.m_numerator = (long long)d1;
	ans.m_denominator = 1;
	return true;
}

DoubleFraction::DoubleFraction(const double& num, const double& denom)
{
	if (denom == 0) { throw std::invalid_argument("zero valued denominator"); }
	m_numerator = num;
	m_denominator = denom;
	doubleToDoubleFraction(toDouble(), *this);
}
DoubleFraction::DoubleFraction() : DoubleFraction::DoubleFraction(0, 1) {}

DoubleFraction& DoubleFraction::operator=(const DoubleFraction &other)
{
	m_numerator = other.m_numerator;
	m_denominator = other.m_denominator;
	return *this;
}
DoubleFraction& DoubleFraction::operator=(const double& nr)
{
	doubleToDoubleFraction(nr, *this);
	return *this;
}

DoubleFraction& DoubleFraction::operator+=(const DoubleFraction& rhs)
{
	doubleToDoubleFraction((toDouble() + rhs.toDouble()), *this);
	return *this;
}
DoubleFraction& DoubleFraction::operator+=(const double& rhs)
{
	!doubleToDoubleFraction((toDouble() + rhs), *this);
	return *this;
}

DoubleFraction& DoubleFraction::operator+(const DoubleFraction& rhs)
{
	DoubleFraction f(*this);
	f += rhs;
	return f;
}
DoubleFraction& DoubleFraction::operator+(const double& rhs)
{
	DoubleFraction f(*this);
	f += rhs;
	return f;
}

DoubleFraction& DoubleFraction::operator-=(const DoubleFraction& rhs)
{
	!doubleToDoubleFraction((toDouble() - rhs.toDouble()), *this);
	return *this;
}
DoubleFraction& DoubleFraction::operator-=(const double& rhs)
{
	!doubleToDoubleFraction((toDouble() - rhs), *this);
	return *this;
}

DoubleFraction& DoubleFraction::operator-(const DoubleFraction& rhs)
{
	DoubleFraction f(*this);
	f -= rhs;
	return f;
}
DoubleFraction& DoubleFraction::operator-(const double& rhs)
{
	DoubleFraction f(*this);
	f -= rhs;
	return f;
}

DoubleFraction& DoubleFraction::operator*=(const DoubleFraction& rhs)
{
	!doubleToDoubleFraction((toDouble() * rhs.toDouble()), *this);
	return *this;
}
DoubleFraction& DoubleFraction::operator*=(const double& rhs)
{
	!doubleToDoubleFraction((toDouble() * rhs), *this);
	return *this;
}

DoubleFraction& DoubleFraction::operator*(const DoubleFraction& rhs)
{
	DoubleFraction f(*this);
	f *= rhs;
	return f;
}
DoubleFraction& DoubleFraction::operator*(const double& rhs)
{
	DoubleFraction f(*this);
	f *= rhs;
	return f;
}

DoubleFraction& DoubleFraction::operator/=(const DoubleFraction& rhs)
{
	!doubleToDoubleFraction((toDouble() / rhs.toDouble()), *this);
	return *this;
}
DoubleFraction& DoubleFraction::operator/=(const double& rhs)
{
	!doubleToDoubleFraction((toDouble() / rhs), *this);
	return *this;
}

DoubleFraction& DoubleFraction::operator/(const DoubleFraction& rhs)
{
	DoubleFraction f(*this);
	f /= rhs;
	return f;
}
DoubleFraction& DoubleFraction::operator/(const double& rhs)
{
	DoubleFraction f(*this);
	f /= rhs;
	return f;
}

DoubleFraction& DoubleFraction::operator^=(const DoubleFraction& rhs)
{
	!doubleToDoubleFraction(pow(toDouble(), rhs.toDouble()), *this);
	return *this;
}
DoubleFraction& DoubleFraction::operator^=(const double& rhs)
{
	!doubleToDoubleFraction(pow(toDouble(), rhs), *this);
	return *this;
}

DoubleFraction& DoubleFraction::operator^(const DoubleFraction& rhs)
{
	DoubleFraction f(*this);
	f ^= rhs;
	return f;
}
DoubleFraction& DoubleFraction::operator^(const double& rhs)
{
	DoubleFraction f(*this);
	f ^= rhs;
	return f;
}


const DoubleFraction operator+(const double& d, const DoubleFraction& rhs)
{
	DoubleFraction f(1, 2);
	//return (d + rhs.toDouble());
	return f;
}

std::ostream& operator<<(std::ostream& s, const DoubleFraction& f)
{
	s << f.m_numerator;
	if (f.m_denominator != 1)
		s << "/" << f.m_denominator;
	return s;
}

std::istream& operator>>(std::istream & s, DoubleFraction & d)
{
	char c;
	s >> d.m_numerator >> c >> d.m_denominator;
	return s;
}


double DoubleFraction::toDouble() const
{
	return (double)m_numerator / (double)m_denominator;
}

void DoubleFraction::doPrint() const
{
	std::cout << m_numerator;
	if (m_denominator != 1)
	{
		std::cout << '/' << m_denominator;
	}
	std::cout << '\n';
}

DoubleFraction::operator std::string() const
{
	return "FRACTION!!!!";
}

DoubleFraction::operator double() const
{
	return toDouble();
}