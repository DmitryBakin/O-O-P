#include "Array.h"
#include <iostream>
void main()
{
	Array array(5);
	std::cout << "input array: ";
	array.input();
	array.insert(34, 4);
	array.output();
}