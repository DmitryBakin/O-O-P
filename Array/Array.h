#pragma once
#include <iostream>

class Array
{
public:
	typedef int* iterator;//
	typedef int value_type;//
	typedef int& reference;//
	typedef int* pointer;//
	typedef int difference_type;
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
	int search(int const value) const;
	void sort();
	bool insert(int const value, int const index);
	bool insert(iterator index);
	bool remove(int const index);
	bool removeValue(int const value);
	void removeAllValue(int const value);

	int max() const;
	int min() const;

	int& operator[](int index);
	const int& operator[](int index) const;
	Array& operator=(const Array& other);
	Array& operator=(Array&& other);
	Array operator+(int const value);
	Array& operator+=(int const value);
	Array operator+(const Array& other);
	Array& operator+=(const Array& other);

	bool operator==(const Array& other);
	bool operator!=(const Array& other);
private:
	int* m_array = nullptr;
	int m_size = 1;
};