#include "boolVector.h"

void main()
{
	const char* array = "1010101000";
	const char* array1 = "1100011000";
	BoolVector bv(array);
	BoolVector bv1(array1);
	//std::cout << bv1 << "\n";
	bv1.setValue(1);
	BoolVector bv2 = bv ^ bv1;
	std::cout << bv1 << "\n";
	std::cout << bv << "\n";
	std::cout << bv2 << "\n";
	//std::cout << bv1 << "; weight = " << bv1.weight();
}