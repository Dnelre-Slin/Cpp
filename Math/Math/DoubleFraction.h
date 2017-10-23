#pragma once

class DoubleFraction
{
private:
	double m_numerator;
	double m_denominator;

	bool doubleToDoubleFraction(const double& d1, DoubleFraction &ans);

public:
	DoubleFraction(const double& num, const double& denom = 1);
	DoubleFraction();

	DoubleFraction& operator=(const DoubleFraction& other);
	DoubleFraction& operator=(const double& nr);

	DoubleFraction& operator+=(const DoubleFraction& rhs);
	DoubleFraction& operator+=(const double& rhs);

	DoubleFraction& operator+(const DoubleFraction& rhs);
	DoubleFraction& operator+(const double& rhs);
	friend const DoubleFraction operator+(const double& d, const DoubleFraction& rhs);

	DoubleFraction& operator-=(const DoubleFraction& rhs);
	DoubleFraction& operator-=(const double& rhs);

	DoubleFraction& operator-(const DoubleFraction& rhs);
	DoubleFraction& operator-(const double& rhs);

	DoubleFraction& operator*=(const DoubleFraction& rhs);
	DoubleFraction& operator*=(const double& rhs);

	DoubleFraction& operator*(const DoubleFraction& rhs);
	DoubleFraction& operator*(const double& rhs);

	DoubleFraction& operator/=(const DoubleFraction& rhs);
	DoubleFraction& operator/=(const double& rhs);

	DoubleFraction& operator/(const DoubleFraction& rhs);
	DoubleFraction& operator/(const double& rhs);

	DoubleFraction& operator^=(const DoubleFraction& rhs);
	DoubleFraction& operator^=(const double& rhs);

	DoubleFraction& operator^(const DoubleFraction& rhs);
	DoubleFraction& operator^(const double& rhs);


	friend std::ostream& operator<<(std::ostream& s, const DoubleFraction& d);
	friend std::istream& operator>>(std::istream& s, DoubleFraction& d);

	double toDouble() const;
	void doPrint() const;

	explicit operator std::string() const;
	operator double() const;
};