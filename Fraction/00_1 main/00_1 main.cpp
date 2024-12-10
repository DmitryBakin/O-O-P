#include <iostream>
#include "..\Fraction\Fraction.h"
int main()
{
	Fraction a, b, sum, difference, product, quotient, deg;
	int degree;
	a.input();
	a.reduce();
	a.output();
	b.input();
	b.reduce();
	b.output();

	sum = a + b;
	sum.reduce();
	std::cout << "a + b = ";
	sum.output();

	difference = a - b;
	difference.reduce();
	std::cout << "a - b = ";
	difference.output();

	product = a * b;
	product.reduce();
	std::cout << "a * b = ";
	product.output();

	quotient = a / b;
	quotient.reduce();
	std::cout << "a / b = ";
	quotient.output();

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
	deg.output();
	return 0;
}