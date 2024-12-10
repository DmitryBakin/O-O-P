﻿
class Fraction
{
public:
	Fraction();
	Fraction(int numerator, int denominator);
	void setNumerator(int numerator);
	void setDenominator(int denominator);
	int numerator() const;
	int denominator() const;
	Fraction operator+(Fraction const b) const;
	Fraction operator-(Fraction const b) const;
	Fraction operator*(Fraction const b) const;
	Fraction operator/(Fraction const b) const;
	bool operator>(Fraction const b) const;
	bool operator<(Fraction const b) const;
	bool operator==(Fraction const b) const;
	bool operator!=(Fraction const b) const;
	Fraction operator^(int n);
	bool denBigger(Fraction const b) const;
	void reduce();
	void input();
	void output();
private:
	int m_numerator = 1;
	int m_denominator = 1;
};