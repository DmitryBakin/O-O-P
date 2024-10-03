#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#pragma once
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
class Fraction
{
public:
	Fraction();
	Fraction(int Numerator, int Denominator);
	void SetNumerator(int);
	void SetDenominator(int);
	int Numerator() const;
	int Denominator() const;
	Fraction operator+(Fraction b);
	Fraction operator-(Fraction b);
	Fraction operator*(Fraction b);
	Fraction operator/(Fraction b);
	bool operator>(Fraction b);
	bool operator<(Fraction b);
	bool operator==(Fraction b);
	bool operator!=(Fraction b);
	Fraction operator^(int n);
	bool denBigger(Fraction b);
	void fractionReduction();
	void inputFraction();
	void outputFraction();
private:
	int m_Numerator = 1;
	int m_Denominator = 1;
};
Fraction Fraction::operator+(Fraction b)
{
	Fraction c;
	c.SetNumerator(m_Numerator * b.m_Denominator + m_Denominator * b.m_Numerator);
	c.SetDenominator(m_Denominator * b.m_Denominator);
	return c;
}
Fraction Fraction::operator-(Fraction b)
{
	Fraction c;
	c.SetNumerator(m_Numerator * b.m_Denominator - m_Denominator * b.m_Numerator);
	c.SetDenominator(m_Denominator * b.m_Denominator);
	return c;
}
Fraction Fraction::operator*(Fraction b)
{
	Fraction c;
	c.SetNumerator(m_Numerator * b.m_Numerator);
	c.SetDenominator(m_Denominator * b.m_Denominator);
	return c;
}
Fraction Fraction::operator/(Fraction b)
{
	Fraction c;
	c.SetNumerator(m_Numerator * b.m_Denominator);
	c.SetDenominator(m_Denominator * b.m_Numerator);
	return c;
}
bool Fraction::operator>(Fraction b)
{
	if (m_Numerator * b.m_Denominator > b.m_Numerator * m_Denominator)
		return true;
	else
		return false;
}
bool Fraction::operator<(Fraction b)
{
	if (m_Numerator * b.m_Denominator < b.m_Numerator * m_Denominator)
		return true;
	else
		return false;
}
bool Fraction::operator==(Fraction b)
{
	if (m_Numerator * b.m_Denominator == b.m_Numerator * m_Denominator)
		return true;
	else
		return false;
}
bool Fraction::operator!=(Fraction b)
{
	if (m_Numerator * b.m_Denominator != b.m_Numerator * m_Denominator)
		return true;
	else
		return false;
}
Fraction Fraction::operator^(int n)
{
	Fraction b;
	if (n > 0)
		for (int i = 0; i < n; i++)
		{
			b.SetNumerator(b.m_Numerator * m_Numerator);
			b.SetDenominator(b.m_Denominator * m_Denominator);
		}
	if (n < 0)
	{
		swap(m_Numerator, m_Denominator);
		n = -n;
		for (int i = 0; i < n; i++)
		{
			b.SetNumerator(b.m_Numerator * m_Numerator);
			b.SetDenominator(b.m_Denominator * m_Denominator);
		}
	}
	return b;

}
bool Fraction::denBigger(Fraction b) 
{
	if (m_Denominator > b.m_Denominator)
		return true;
	else
		return false;
}
void Fraction::fractionReduction()
{
	while (true)
	{
		int NOD = 1;
		for (int i = 1; i <= min(abs(m_Numerator), abs(m_Denominator)); ++i)
			if (m_Numerator % i == 0 && m_Denominator % i == 0)
				NOD = i;
		if (NOD == 1)
			break;
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
	cout << "Enter numerator this fraction: ";
	cin >> m_Numerator;
	cout  << "Enter denominator this fraction: ";
	cin >> m_Denominator;
	if (m_Denominator == 0)
	{
		cout << "Denominator cannot be == 0" << endl;
		m_Numerator = 0;
		m_Denominator = 1;
	}
}
void Fraction::outputFraction()
{
	cout << m_Numerator << "/" << m_Denominator << endl;
}
int main()
{
	Fraction a, b, sum, difference, product, quotient; int degree;
	a.inputFraction();
	a.fractionReduction();
	a.outputFraction();
	b.inputFraction();
	b.fractionReduction();
	b.outputFraction();

	sum = a + b;
	sum.fractionReduction();
	cout << "a + b = ";
	sum.outputFraction();

	difference = a - b;
	difference.fractionReduction();
	cout << "a - b = ";
	difference.outputFraction();

	product = a * b;
	product.fractionReduction();
	cout << "a * b = ";
	product.outputFraction();

	quotient = a / b;
	quotient.fractionReduction();
	cout << "a / b = ";
	quotient.outputFraction();

	if (a > b)
		cout << "a > b" << endl;

	if (a < b)
		cout << "a < b" << endl;

	if (a == b)
		cout << "a == b" << endl;

	if (a != b)
		cout << "a != b" << endl;

	if (a.denBigger(b))
		cout << "a.denominator > b.Denominator" << endl;
	if (a.denBigger(b) == false)
		cout << "a.denominator <= b.Denominator" << endl;

	cout << "Enter the degree: ";
	cin >> degree;
	a = a ^ degree;
	cout << "a ^ " << degree << " = ";
	a.outputFraction();
	return 0;
}
Fraction::Fraction()
{
}
Fraction::Fraction(int Numerator, int Denominator)
{
	if (Denominator == 0)
	{
		cout << "Denominator cannot be == 0" << endl;
		m_Numerator = 0;
		m_Denominator = 1;
	}
	else 
	{
		m_Numerator = Numerator;
		m_Denominator = Denominator;

	}
}
void Fraction::SetNumerator(int Numerator)
{
	m_Numerator = Numerator;
}
void Fraction::SetDenominator(int Denominator)
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