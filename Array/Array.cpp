#include "Array.h"
#include <iostream>
#include <algorithm>
#include <assert.h>

Array::Array()
{
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = 0;
	}
}
Array::Array(int size)
{
	if (size < 0)
		size = -size;
	m_size = size;
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = 0;
	}
}
Array::Array(const Array & other) 
	: m_size(other.m_size)
{
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = other.m_array[i];
	}
}
Array::Array(Array&& other)
	: m_size(other.m_size)
{
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = other.m_array[i];
	}
	other.m_array = nullptr;
}
Array::~Array()
{
	delete[] m_array;
}

void Array::output()
{
	for (int i = 0; i < m_size; i++)
	{
		std::cout << m_array[i] << " ";
	}
}
void Array::input()
{
	for (int i = 0; i < m_size; i++)
	{
		std::cin >> m_array[i];
	}
}

int Array::size() const
{
	return m_size;
}

void Array::swap(Array& other)
{
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
}
int Array::search(int const value) const
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_array[i] == value)
			return i;
	}
	return -1;
}
void Array::sort()
{
	int L = 0, R = m_size - 1;
	while (L <= R)
	{
		for (int i = L; i < R; i++)
			if (m_array[i] > m_array[i + 1])
				std::swap(m_array[i], m_array[i + 1]);
		R--;
		for (int i = R; i > L; i--)
			if (m_array[i] < m_array[i - 1])
				std::swap(m_array[i], m_array[i - 1]);
		L++;
	}
}
bool Array::insert(int const value, int const index)
{
	if (index < 0 || index >= m_size)
	{
		return false;
	}
	int* newArray;
	newArray = new int[m_size + 1];
	for (int i = 0; i < index; i++)
	{
		newArray[i] = m_array[i];
	}
	newArray[index] = value;
	for (int i = index + 1; i < m_size + 1; i++)
	{
		newArray[i] = m_array[i - 1];
	}
	delete[] m_array;
	m_array = newArray;
	m_size++;
	return true;
}
bool Array::remove(int const index)
{
	if (index < 0 || index >= m_size)
	{
		return false;
	}
	int* newArray;
	newArray = new int[m_size - 1];
	for (int i = 0; i < index; i++)
	{
		newArray[i] = m_array[i];
	}
}

int& Array::operator[](int index)
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}
const int& Array::operator[](int index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}
Array& Array::operator=(const Array& other)
{
	if (m_size == other.m_size)
	{
		for (int i = 0; i < m_size; ++i)
		{
			m_array[i] = other.m_array[i];
		}
	}
	else
	{
		Array copy(other);
		swap(copy);
	}
	return *this;
}
Array& Array::operator=(Array&& other)
{
	{
		swap(other);
		return *this;
	}
}



/*Необходимые методы класса:
- конструкторы+ (по умолчанию+, конструктор из обычного массива+, конструктор копирования+);
- деструктор+;
- получение размера+ (количества хранимых элементов в настоящий момент);
- обмен содержимого с другим массивом (swap)+;
- поиск элемента (возвращает индекс первого совпавшего элемента, либо -1, если совпадений нет)+;
- ввод/вывод в консоль (потоковый)+;
- сортировка элементов (любым алгоритмом)+;
- вставка элемента по индексу. Если индекс некорректный, вернуть false+;
- удаление элемента по индексу. Если индекс некорректный, вернуть false;
- удаление элемента по значению (первое вхождение). Если элемент отсутствует в массиве, вернуть false;
- удаление всех элементов с заданным значением;
- поиск максимального/минимального элемента;
- получение итераторов на начало/конец массива (методы должны называться begin и end. Метод end должен возвращать итератор не на последний элемент, а за позицию после него);
- вставка элемента перед итератором;
- удаление элемента или диапазона элементов с помощью итераторов.

Необходимые перегрузки:
- получение ссылки на элемент по индексу ([ ]);
- присваивание (=);
- добавление элемента в конец массива (+ и +=);
- сложение (конкатенация) с другим массивом (здесь имеется в виду другим объектом нашего класса, а не стандартные массивы) (+ и +=);
- сравнение (== и !=).*/