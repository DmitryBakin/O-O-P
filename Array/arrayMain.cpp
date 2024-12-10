#include "Array.h"
#include <iostream>
#include "C:/O-O-P/boolVector/boolVector.cpp"

void main()
{
	BoolVector bv(12);
	Array<BoolVector> arr(10);
	arr.insert(0,0);
	Array<BoolVector> ar(arr);
	std::cout << ar;
	std::cout << "\n" << arr;
}