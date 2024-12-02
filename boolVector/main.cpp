#include "boolVector.h"

void main()
{
	const char* array = "0010101100";
	BoolVector bv(array);
	std::cout << bv << "\n";
	bv.setBitValues(0, 10, true);

	std::cout << bv << "; weight = " << bv.weight();
}
