#include <iostream>
#include "..\Fraction\Fraction.h"
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