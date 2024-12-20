#pragma once
#include <iostream>
#include <algorithm>
#include <assert.h>

template <typename ItemType>
class Array
{
public:
	typedef ItemType* iterator;
	typedef ItemType value_type;
	typedef ItemType& reference;
	typedef ItemType* pointer;
	typedef ItemType difference_type;
public:
	Array();
	Array(int size);
	Array(const Array& other);
	Array(Array&& other);
	~Array();

	void output();
	void input();
	
	iterator begin();
	iterator end();
	const iterator begin() const;
	const iterator end() const;

	int size() const;

	void swap(Array& other);
	int search(ItemType const value) const;
	void sort();

	bool insert(int const index, ItemType const value);
	bool insert(iterator const index, ItemType const value);

	bool remove(int const index);
	bool remove(iterator const index);
	bool remove(iterator const itBegin,iterator const itEnd);
	bool removeValue(ItemType const value);
	void removeAllValue(ItemType const value);

	int maxIndex() const;
	int minIndex() const;

	ItemType& operator[](int const index);
	const ItemType& operator[](int const index) const;
	Array& operator=(const Array& other);
	Array& operator=(Array&& other);
	Array operator+(const ItemType value);
	Array& operator+=(const ItemType value);
	Array operator+(const Array& other);
	Array& operator+=(const Array& other);
	friend std::ostream& operator<<(std::ostream& r,const Array<ItemType>& other);
	friend std::istream& operator>>(std::istream& r, Array<ItemType>& other);

	bool operator==(const Array& other) const;
	bool operator!=(const Array& other) const;
private:
	ItemType* m_array = nullptr;
	int m_size = 1;
};

template <typename ItemType>
Array<ItemType>::Array()
{
	m_array = new ItemType[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = 0;
	}
}

template <typename ItemType>
Array<ItemType>::Array(int size)
{
	if (size < 0)
		size = -size;
	m_size = size;
	m_array = new ItemType[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = 0;
	}
}

template <typename ItemType>
Array<ItemType>::Array(const Array& other)
	: m_size(other.m_size)
{
	m_array = new ItemType[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = other.m_array[i];
	}
}

template <typename ItemType>
Array<ItemType>::Array(Array&& other)
	: m_size(std::move(other.m_size))
	, m_array(std::move(other.m_array))
{
}

template <typename ItemType>
Array<ItemType>::~Array()
{
	delete[] m_array;
}

template <typename ItemType>
void Array<ItemType>::output()
{
	for (int i = 0; i < m_size; i++)
	{
		std::cout << m_array[i] << " ";
	}
}

template <typename ItemType>
void Array<ItemType>::input()
{
	for (int i = 0; i < m_size; i++)
	{
		std::cin >> m_array[i];
	}
}

template <typename ItemType> typename
Array<ItemType>::iterator Array<ItemType>::begin()
{
	return m_array;
}

template <typename ItemType> typename
Array<ItemType>::iterator Array<ItemType>::end()
{
	return m_array + m_size;
}

template <typename ItemType>
const typename Array<ItemType>::iterator Array<ItemType>::begin() const
{
	return m_array;
}

template <typename ItemType>
const typename Array<ItemType>::iterator Array<ItemType>::end() const
{
	return m_array + m_size;
}

template <typename ItemType>
int Array<ItemType>::size() const
{
	return m_size;
}

template <typename ItemType>
void Array<ItemType>::swap(Array& other)
{
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
}

template <typename ItemType>
int Array<ItemType>::search(ItemType const value) const
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_array[i] == value)
			return i;
	}
	return -1;
}

template <typename ItemType>
void Array<ItemType>::sort()
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

template <typename ItemType>
bool Array<ItemType>::insert(int const index, ItemType const value)
{
	if (index < 0 || index >= m_size)
	{
		return false;
	}
	insert(begin() + index, value);
	return true;
}

template <typename ItemType>
bool Array<ItemType>::insert(iterator const index, ItemType const value)
{
	if (index < begin() || index > end())
	{
		return false;
	}
	int i = 0;
	ItemType* newArray = new ItemType[m_size + 1];
	for (iterator it = begin(); it != index; it++, i++)
	{
		newArray[i] = (*it);
	}
	newArray[i] = value;
	for (iterator it = index; it != end(); it++, i++)
	{
		newArray[i + 1] = (*it);
	}
	delete[] m_array;
	m_array = newArray;
	m_size++;
	return true;
}

template <typename ItemType>
bool Array<ItemType>::remove(int const index)
{
	if (index < 0 || index >= m_size)
	{
		return false;
	}
	remove(begin() + index);
	return true;
}

template <typename ItemType>
bool Array<ItemType>::remove(iterator const index)
{
	if (index < begin() || index >= end())
	{
		return false;
	}
	remove(index, index);
	return true;
}

template <typename ItemType>
bool Array<ItemType>::remove(iterator const itBegin, iterator const itEnd)
{
	if (itBegin < begin() || itBegin >= end() || itEnd < begin() || itEnd >= end() || itBegin > itEnd)
	{
		return false;
	}
	int i = 0;
	ItemType* newArray = new ItemType[m_size - (itEnd - itBegin) - 1];
	for (iterator it = begin(); it != itBegin; it++, i++)
	{
		newArray[i] = (*it);
	}
	for (iterator it = itEnd + 1; it != end(); it++, i++)
	{
		newArray[i] = (*it);
	}
	delete[] m_array;
	m_array = newArray;
	m_size -= (itEnd - itBegin) + 1;
	return true;
}

template <typename ItemType>
bool Array<ItemType>::removeValue(ItemType const value)
{
	int index = search(value);
	if (index == -1)
		return false;
	ItemType* newArray;
	newArray = new ItemType[m_size - 1];
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

template <typename ItemType>
void Array<ItemType>::removeAllValue(ItemType const value)
{
	while (removeValue(value));
}

template <typename ItemType>
int Array<ItemType>::maxIndex() const
{
	int max_index = 0;
	for (int i = 1; i < m_size; i++)
		if (m_array[i] > m_array[max_index])
			max_index = i;
	return max_index;
}

template <typename ItemType>
int Array<ItemType>::minIndex() const
{
	int min_index = 0;
	for (int i = 1; i < m_size; i++)
		if (m_array[i] < m_array[min_index])
			min_index = i;
	return min_index;
}

template <typename ItemType>
ItemType& Array<ItemType>::operator[](int const index)
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

template <typename ItemType>
const ItemType& Array<ItemType>::operator[](int const index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator=(const Array<ItemType>& other)
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
		Array<ItemType> copy(other);
		swap(copy);
	}
	return *this;
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator=(Array<ItemType>&& other)
{
	swap(other);
	return *this;
}

template <typename ItemType>
Array<ItemType> Array<ItemType>::operator+(const ItemType value)
{
	Array<ItemType> result(m_size + 1);
	for (int i = 0; i < m_size; ++i)
	{
		result[i] = m_array[i];
	}
	result[m_size] = value;
	return result;
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator+=(const ItemType value)
{
	operator+(value).swap(*this);
	return *this;
}

template <typename ItemType>
Array<ItemType> Array<ItemType>::operator+(const Array<ItemType>& other)
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

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator+=(const Array<ItemType>& other)
{
	operator+(other).swap(*this);
	return *this;
}

template <typename ItemType>
std::ostream& operator<<(std::ostream& r,const Array<ItemType>& other)
{
	for (int i = 0; i < other.size(); i++)
		r << other[i] << " ";
	return r;
}

template <typename ItemType>
std::istream& operator>>(std::istream& r, Array<ItemType>& other)
{
	for(int i = 0; i < other.size(); i++)
		r >> other[i];
	return r;
}

template <typename ItemType>
bool Array<ItemType>::operator==(const Array<ItemType>& other) const
{
	if (m_size != other.m_size)
		return false;
	for (int i = 0; i < m_size; i++)
		if (m_array[i] != other.m_array[i])
			return false;
	return true;
}

template <typename ItemType>
bool Array<ItemType>::operator!=(const Array<ItemType>& other) const
{
	return !(operator==(other));
}
