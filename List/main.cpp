#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "List.h"

template <typename T>
void printSearchResult(const List<T>& list, const T& value)
{
    auto it = std::find(list.begin(), list.end(), value);
    std::cout << "list ";
    if (it == list.end())
    {
        std::cout << "doesn't contain ";
    }
    else
    {
        std::cout << "contains ";
    }
    std::cout << "'" << value << "' value.\n";
}

int main()
{
    int* array;
    array = new int[3];
    array[0] = 3;
    array[1] = 1000;
    array[2] = -10;


    List<int> list1,list2;
    List<int>::Node* node, *node1;
    list1.addToTail(34);
    list1.addToTail(2);
    list1.addToTail(-100);
    list2.addToTail(10);
    list2.addToTail(-4);
    list2.addToTail(0);
    list2.addToTail(1);
    list2.addToHead(91);
    List<int> list3(array,3);
    std::cout << list2 << list1;
    list2.sort();
    list1 += list2;
    node = list2.searchElement(91)->next;
    node1 = list2.searchElement(1)->prev;
    List<int>::iterator it(node);
    List<int>::iterator it1(node1);
    //list2.sort();
    //list2.sort();
    std::cout << list1;
    list1.sort();
    std::cout << list1;


    return 0;
}