#include "boolMatrix.h"


void main()
{
	const char** other;
	other = new const char* [4];
	for (int i = 0; i < 4; ++i)
		other[i] = new char[4];
	other[0] = "1011";
	other[1] = "1110";
	other[2] = "0000";
	other[3] = "1001";
	BoolMatrix bm(4,4,1);
	BoolMatrix bm1 = bm;
	BoolMatrix bm2(other,4);
	//BoolMatrix bmChar(other, 2);
	//bm2.swap(bmChar);
	//std::cin >> bm1;
	bm = ~bm2;
	std::cout << bm << " ";
}