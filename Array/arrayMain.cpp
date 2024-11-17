#include "Array.h"
#include <iostream>
void main()
{
	Array<int> fractionArr(3);
	fractionArr >> std::cin;
	fractionArr << std::cout;
}