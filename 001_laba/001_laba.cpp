#include "Fraction.h"
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

Fraction Fraction::operator+(Fraction const b)
{
	Fraction c;
	c.setNumerator(m_Numerator * b.m_Denominator + m_Denominator * b.m_Numerator);
	c.setDenominator(m_Denominator * b.m_Denominator);
	return c;
}
Fraction Fraction::operator-(Fraction const b)
{
	Fraction c;
	c.setNumerator(m_Numerator * b.m_Denominator - m_Denominator * b.m_Numerator);
	c.setDenominator(m_Denominator * b.m_Denominator);
	return c;
}
Fraction Fraction::operator*(Fraction const b)
{
	Fraction c;
	c.setNumerator(m_Numerator * b.m_Numerator);
	c.setDenominator(m_Denominator * b.m_Denominator);
	return c;
}
Fraction Fraction::operator/(Fraction const b)
{
	Fraction c;
	c.setNumerator(m_Numerator * b.m_Denominator);
	c.setDenominator(m_Denominator * b.m_Numerator);
	return c;
}
bool Fraction::operator>(Fraction const b)
{
	return (m_Numerator * b.m_Denominator > b.m_Numerator * m_Denominator);
}
bool Fraction::operator<(Fraction const b)
{
	return (m_Numerator * b.m_Denominator < b.m_Numerator * m_Denominator);
}
bool Fraction::operator==(Fraction const b)
{
	return (m_Numerator * b.m_Denominator == b.m_Numerator * m_Denominator);
}
bool Fraction::operator!=(Fraction const b)
{
	return (m_Numerator * b.m_Denominator != b.m_Numerator * m_Denominator);
}
Fraction Fraction::operator^(int n)
{
	Fraction b;
	if (n < 0)
	{
		swap(m_Numerator, m_Denominator);
		n = -n;
	}
	for (int i = 0; i < n; i++)
	{
		b.setNumerator(b.m_Numerator * m_Numerator);
		b.setDenominator(b.m_Denominator * m_Denominator);
	}
	return b;

}
bool Fraction::denBigger(Fraction const b) 
{
	return (m_Denominator > b.m_Denominator);
}
void Fraction::fractionReduction()
{
	int NOD = 0;
	while (NOD!=1)
	{
		NOD = 1;
		for (int i = 2; i <= std::min(abs(m_Numerator), abs(m_Denominator)); ++i)
			if (m_Numerator % i == 0 && m_Denominator % i == 0)
				NOD = i;
		m_Numerator /= NOD;
		m_Denominator /= NOD;
	}
	if (m_Denominator < 0)
	{
		m_Numerator *= -1;
		m_Denominator *= -1;
	}
}
void Fraction::inputFraction()
{
	std::cout << "Enter numerator fraction: ";
	std::cin >> m_Numerator;
	std::cout  << "Enter denominator fraction: ";
	std::cin >> m_Denominator;
	if (m_Denominator == 0)
	{
		std::cout << "Denominator cannot be == 0 ====> " << m_Numerator << "/" << m_Denominator << " = 0/1" << std::endl;
		m_Numerator = 0;
		m_Denominator = 1;
	}
}
void Fraction::outputFraction()
{
	std::cout << m_Numerator << "/" << m_Denominator << std::endl;
}
int main()
{
	Fraction a, b, sum, difference, product, quotient, deg; int degree;
	a.inputFraction();
	a.fractionReduction();
	a.outputFraction();
	b.inputFraction();
	b.fractionReduction();
	b.outputFraction();

	sum = a + b;
	sum.fractionReduction();
	std::cout << "a + b = ";
	sum.outputFraction();

	difference = a - b;
	difference.fractionReduction();
	std::cout << "a - b = ";
	difference.outputFraction();

	product = a * b;
	product.fractionReduction();
	std::cout << "a * b = ";
	product.outputFraction();

	quotient = a / b;
	quotient.fractionReduction();
	std::cout << "a / b = ";
	quotient.outputFraction();

	if (a > b)
		std::cout << "a > b" << std::endl;

	if (a < b)
		std::cout << "a < b" << std::endl;

	if (a == b)
		std::cout << "a == b" << std::endl;

	if (a != b)
		std::cout << "a != b" << std::endl;

	if (a.denBigger(b))
		std::cout << "a.denominator > b.Denominator" << std::endl;
	if (!a.denBigger(b))
		std::cout << "a.denominator <= b.Denominator" << std::endl;

	std::cout << "Enter degree a: ";
	std::cin >> degree;
	deg = a ^ degree;
	std::cout << "a ^ " << degree << " = ";
	deg.outputFraction();
	return 0;
}
Fraction::Fraction()
{
}
Fraction::Fraction(int Numerator, int Denominator)
{
	if (Denominator == 0)
	{
		std::cout << "Denominator cannot be == 0" << std::endl;
		m_Numerator = 0;
		m_Denominator = 1;
	}
	else 
	{
		m_Numerator = Numerator;
		m_Denominator = Denominator;

	}
}
void Fraction::setNumerator(int Numerator)
{
	m_Numerator = Numerator;
}
void Fraction::setDenominator(int Denominator)
{
	m_Denominator = Denominator;
}
int Fraction::Denominator() const
{
	return m_Denominator;
}
int Fraction::Numerator() const
{
	return m_Numerator;
}