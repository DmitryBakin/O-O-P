#include "Array.h"
#include <iostream>
void main()
{
	Array array(5),array2(4);
	std::cout << "input array: ";
	array.input();
	array += 23;
	int size = array.size();
	array.output();
	std::cout << "\nsize = " << (array != array2);

	
}