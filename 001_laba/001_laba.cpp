﻿#include <iostream>
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
	int Denominator() const;
	Fraction sum(Fraction a, Fraction b);
	//Fraction operator+(Fraction b);
private:
	int m_Numenator;
	int m_Denominator;
};
Fraction sum(Fraction a, Fraction b)
{
	Fraction c;
	c.SetNumerator(a.Numerator() * b.Denominator() + a.Denominator() * b.Numerator());
	c.SetDenominator(a.Denominator() * b.Denominator());
	return c;
}

int main()
{
	Fraction a, b,c;
	int na, da, nb, db;
	cout << "Vvedite Numerator a ";
	cin >> na;
	cout << "Vvedite Denominator a ";
	cin >> da;
	cout << "Vvedite Numerator b ";
	cin >> nb;
	cout << "Vvedite  Denominator b ";
	cin >> db;
	a.SetNumerator(na);
	a.SetDenominator(da);
	b.SetNumerator(nb);
	b.SetDenominator(db);
	c = sum(a, b);
	cout << c.Numerator() << "/" << c.Denominator();
}

void Fraction::SetNumerator(int Numerator)
{
	m_Numenator = Numerator;
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
	return m_Numenator;
}