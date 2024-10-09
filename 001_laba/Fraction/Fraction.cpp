#include "Fraction.h"
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
Fraction Fraction::operator+(Fraction const b) const
{
	Fraction c;
	c.setNumerator(m_numerator * b.m_denominator + m_denominator * b.m_numerator);
	c.setDenominator(m_denominator * b.m_denominator);
	return c;
}
Fraction Fraction::operator-(Fraction const b) const
{
	Fraction c;
	c.setNumerator(m_numerator * b.m_denominator - m_denominator * b.m_numerator);
	c.setDenominator(m_denominator * b.m_denominator);
	return c;
}
Fraction Fraction::operator*(Fraction const b) const
{
	Fraction c;
	c.setNumerator(m_numerator * b.m_numerator);
	c.setDenominator(m_denominator * b.m_denominator);
	return c;
}
Fraction Fraction::operator/(Fraction const b) const
{
	Fraction c;
	c.setNumerator(m_numerator * b.m_denominator);
	c.setDenominator(m_denominator * b.m_numerator);
	return c;
}
bool Fraction::operator>(Fraction const b) const
{
	return (m_numerator * b.m_denominator > b.m_numerator * m_denominator);
}
bool Fraction::operator<(Fraction const b) const
{
	return (m_numerator * b.m_denominator < b.m_numerator * m_denominator);
}
bool Fraction::operator==(Fraction const b) const
{
	return (m_numerator * b.m_denominator == b.m_numerator * m_denominator);
}
bool Fraction::operator!=(Fraction const b) const
{
	return (m_numerator * b.m_denominator != b.m_numerator * m_denominator);
}
Fraction Fraction::operator^(int n)
{
	Fraction b;
	if (n < 0)
	{
		swap(m_numerator, m_denominator);
		n = -n;
	}
	for (int i = 0; i < n; i++)
	{
		b.setNumerator(b.m_numerator * m_numerator);
		b.setDenominator(b.m_denominator * m_denominator);
	}
	return b;

}
bool Fraction::denBigger(Fraction const b) const
{
	return (m_denominator > b.m_denominator);
}
void Fraction::fractionReduction()
{
	int LCD = 0;
	while (LCD != 1)
	{
		LCD = 1;
		for (int i = 2; i <= std::min(abs(m_numerator), abs(m_denominator)); ++i)
			if (m_numerator % i == 0 && m_denominator % i == 0)
				LCD = i;
		m_numerator /= LCD;
		m_denominator /= LCD;
	}
	if (m_denominator < 0)
	{
		m_numerator *= -1;
		m_denominator *= -1;
	}
}
void Fraction::inputFraction()
{
	std::cout << "Enter numerator fraction: ";
	std::cin >> m_numerator;
	std::cout << "Enter denominator fraction: ";
	std::cin >> m_denominator;
	if (m_denominator == 0)
	{
		std::cout << "Denominator cannot be == 0 ====> " << m_numerator << "/" << m_denominator << " = 0/1" << std::endl;
		m_numerator = 0;
		m_denominator = 1;
	}
}
void Fraction::outputFraction()
{
	std::cout << m_numerator << "/" << m_denominator << std::endl;
}
Fraction::Fraction()
{
}
Fraction::Fraction(int numerator, int denominator)
{
	if (denominator == 0)
	{
		std::cout << "Denominator cannot be == 0 ====> " << m_numerator << "/" << m_denominator << " = 0/1" << std::endl;
		m_numerator = 0;
		m_denominator = 1;
	}
	else
	{
		m_numerator = numerator;
		m_denominator = denominator;

	}
}
void Fraction::setNumerator(int numerator)
{
	m_numerator = numerator;
}
void Fraction::setDenominator(int denominator)
{
	m_denominator = denominator;
}
int Fraction::denominator() const
{
	return m_denominator;
}
int Fraction::numerator() const
{
	return m_numerator;
}
int main()
{
	Fraction a, b, sum, difference, product, quotient, deg;
	int degree;
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