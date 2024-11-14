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

Array::iterator Array::begin()
{
	return m_array;
}
Array::iterator Array::end()
{
	return m_array + m_size;
}
const Array::iterator Array::begin() const
{
	return m_array;
}
const Array::iterator Array::end() const
{
	return m_array + m_size;
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
bool Array::insert(iterator index)
{
	;
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
	for (int i = index; i < m_size; i++)
	{
		newArray[i] = m_array[i + 1];
	}
	delete[] m_array;
	m_array = newArray;
	m_size--;
	return true;
}
bool Array::removeValue(int const value)
{
	int index = search(value);
	if (index == -1)
		return false;
	int* newArray;
	newArray = new int[m_size - 1];
	for (int i = 0; i < index; i++)
	{
		newArray[i] = m_array[i];
	}
	for (int i = index; i < m_size; i++)
	{
		newArray[i] = m_array[i + 1];
	}
	delete[] m_array;
	m_array = newArray;
	m_size--;
	return true;
}
void Array::removeAllValue(int const value)
{
	while (removeValue(value))
		removeValue(value);
}
int Array::max() const
{
	int max_index = 0;
	for (int i = 1; i < m_size; i++)
		if (m_array[i] > m_array[max_index])
			max_index = i;
	return max_index;
}
int Array::min() const
{
	int min_index = 0;
	for (int i = 1; i < m_size; i++)
		if (m_array[i] < m_array[min_index])
			min_index = i;
	return min_index;
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
		swap(other);
		return *this;
}
Array Array::operator+(int const value)
{
	Array result(m_size + 1);
	for (int i = 0; i < m_size; ++i)
	{
		result[i] = m_array[i];
	}
	result[m_size] = value;
	return result;
}
Array& Array::operator+=(int const value)
{
	operator+(value).swap(*this);
	return *this;
}
Array Array::operator+(const Array& other)
{
	Array result(m_size + other.m_size);
	for (int i = 0; i < m_size; ++i)
	{
		result[i] = m_array[i];
	}
	for (int i = 0; i < other.m_size; ++i)
	{
		result[m_size + i] = other[i];
	}
	return result;
}
Array& Array::operator+=(const Array& other)
{
	operator+(other).swap(*this);
	return *this;
}

bool Array::operator==(const Array& other)
{
	if (m_size != other.m_size)
		return false;
	for (int i = 0; i < m_size; i++)
		if (m_array[i] != other.m_array[i])
			return false;
	return true;
}
bool Array::operator!=(const Array& other)
{
	if (operator==(other))
		return false;
	else
		return true;
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
- удаление элемента по индексу. Если индекс некорректный, вернуть false+;
- удаление элемента по значению (первое вхождение). Если элемент отсутствует в массиве, вернуть false+;
- удаление всех элементов с заданным значением+;
- поиск максимального/минимального элемента+;
- получение итераторов на начало/конец массива +(методы должны называться begin и end. Метод end должен возвращать итератор не на последний элемент, а за позицию после него);
- вставка элемента перед итератором;
- удаление элемента или диапазона элементов с помощью итераторов.

Необходимые перегрузки:
- получение ссылки на элемент по индексу ([ ])+;
- присваивание (=)+;
- добавление элемента в конец массива (+ и +=)+;
- сложение (конкатенация) с другим массивом +(здесь имеется в виду другим объектом нашего класса, а не стандартные массивы) (+ и +=);
- сравнение (== и !=)+.*/