#include "Array.h"
#include <iostream>
void main()
{
	Array array(5),array2(4);
	Array::iterator it,it2;
	it = array.begin(); it2 = array.end() - 3;
	std::cout << "input array: ";
	array.input();
	//array += 23;
	int size = array.size();
	array.output();
	puts("");
	array.remove(it,it2);
	array.output();
	//array.output();
	std::cout << "\nsize = " << (it2 - it);
}