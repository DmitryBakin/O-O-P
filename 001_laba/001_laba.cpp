#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
using namespace std;
#pragma once
struct Fraction
{
public:
	void SetNumerator(int);
	void SetDenominator(int);
	int Numerator() const;
	int Denimonator() const;
	Fraction sum(Fraction b);
	Fraction operator+(Fraction b);
private:
	int m_Numenator;
	int m_Denominator;
};
Fraction sum(Fraction a, Fraction b)
{
	Fraction c;
	c.SetNumerator(a.Numerator() * b.Denimonator() + a.Denimonator() * b.Numerator());
	c.SetDenominator(a.Denimonator() * b.Denimonator());
	return c;
}

int main()
{
	Fraction a, b;
	int na, da, nb, db;
	cin >> na;
	cout << "Vvedite Numerator a";
	cin >> da;
	cout << "Vvedite Denominator a";
	cin >> nb;
	cout << "Vvedite Numerator b";
	cin >> db;
	cout << "Vvedite  Denominator b";
	a.SetNumerator(na);
	a.SetDenominator(da);
	b.SetNumerator(nb);
	b.SetDenominator(db);
	return a;
}