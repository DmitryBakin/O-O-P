#include "Array.h"
#include <iostream>
#include "C:/O-O-P/boolVector/boolVector.cpp"

void main()
{
	BoolVector bv(12);
	Array<int> arr(10);
	//arr.insert(0,0);
	Array<int> ar(arr);
	arr.insert(1, 1);
	std::cout << (ar != arr);
	//std::cout << "\n" << arr;
}