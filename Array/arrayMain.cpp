#include "Array.h"
#include <iostream>
void main()
{
	Array<int> arr(10);
	Array<int> ar(arr);
	std::cout << ar;
	std::cout << "\n" << arr;
}