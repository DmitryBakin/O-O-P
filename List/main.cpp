
#include "List.h"

int main()
{
    int* array;
    array = new int[3];
    array[0] = 3;
    array[1] = 1000;
    array[2] = -10;


    List<int> list1,list2;
    //List<int>::Node* node, *node1;
    list1.addToTail(34);
    list1.addToTail(2);
    list1.addToTail(-100);
    list2.addToTail(10);
    list2.addToTail(-4);
    //list2.addToTail(0);
    //list2.addToTail(1);
    //list2.addToHead(91);
    list2.addElement(10, 45);
    list2.deleteFromTail();
    List<int> list3(array,3);
    std::cout << list2 << list1;
    //list2.sort();
    //list1 += list2;
    //List<int>::iterator it = list1.searchElement(91);
    //list2.sort();
    //list2.sort();
    //std::cout << (*it) << "\n";
    //list1.sort();
    //std::cout << list1;


    return 0;
}