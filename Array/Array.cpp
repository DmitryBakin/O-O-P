﻿#include "Array.h"
#include <iostream>




//(+move constructor, const, +insert/remove refactoring, +cin/cout, +min/max)
/*Необходимые методы класса:
- конструкторы+ (по умолчанию+, конструктор из обычного массива+, конструктор копирования+);
- деструктор+;
- получение размера+ (количества хранимых элементов в настоящий момент);
- обмен содержимого с другим массивом (swap)+;
- поиск элемента (возвращает индекс первого совпавшего элемента, либо -1, если совпадений нет)+;
- ввод/вывод в консоль (потоковый)+;
- сортировка элементов (любым алгоритмом)+;
- вставка элемента по индексу. Если индекс некорректный, вернуть false+;
- удаление элемента по индексу. Если индекс некорректный, вернуть false+;
- удаление элемента по значению (первое вхождение). Если элемент отсутствует в массиве, вернуть false+;
- удаление всех элементов с заданным значением+;
- поиск максимального/минимального элемента+;
- получение итераторов на начало/конец массива +(методы должны называться begin и end. Метод end должен возвращать итератор не на последний элемент, а за позицию после него);
- вставка элемента перед итератором+;
- удаление элемента или диапазона элементов с помощью итераторов+.

Необходимые перегрузки:
- получение ссылки на элемент по индексу ([ ])+;
- присваивание (=)+;
- добавление элемента в конец массива (+ и +=)+;
- сложение (конкатенация) с другим массивом +(здесь имеется в виду другим объектом нашего класса, а не стандартные массивы) (+ и +=);
- сравнение (== и !=)+.*/


