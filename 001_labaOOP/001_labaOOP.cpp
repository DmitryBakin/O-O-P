﻿#include <iostream>
#include "pch.h"
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
	c.SetNumerator(a.Numerator() * b.Denimonator() + a.Denimonator * b.Numerator);
	c.SetDenominator(a.Denimonator() * b.Denimonator());
	return c;
}

int main()
{
	Fraction a, b;
	cin >> a.SetNumerator;
	puts();
	cin >> a.SetDenominator;
	puts();
	cin >> b.SetNumerator;
	puts();
	cin >> b.SetDenominator;
	cout << a;
}