#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
class Fraction
{
public:
	Fraction();
	Fraction(int Numerator, int Denominator);
	void setNumerator(int);
	void setDenominator(int);
	int Numerator() const;
	int Denominator() const;
	Fraction operator+(Fraction const b);
	Fraction operator-(Fraction const b);
	Fraction operator*(Fraction const b);
	Fraction operator/(Fraction const b);
	bool operator>(Fraction const b);
	bool operator<(Fraction const b);
	bool operator==(Fraction const b);
	bool operator!=(Fraction const b);
	Fraction operator^(int n);
	bool denBigger(Fraction const b);
	void fractionReduction();
	void inputFraction();
	void outputFraction();
private:
	int m_Numerator = 1;
	int m_Denominator = 1;
};