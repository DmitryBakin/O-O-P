#include "Set.h"

int main()
{
    Set set;
    std::cout << "set = ";
    std::cin >> set;
    Set set1;
    //set1 /= set;
    Set set2;
    set2 += '4';
    set2 += '*';
    set2 /= set;
    std::cout << "set2 = ";
    //std::cin >> set2;
    std::cout << set2;
    //std::cout << (set2 / set);
    //std::cout << ~set1;
    //std::cout << set1;
}