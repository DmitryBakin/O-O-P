#pragma once
#include <iostream>

class Array
{
public:
	Array();
	Array(int size);
	Array(const Array& other);
	Array(Array&& other);
	~Array();

	void output();
	void input();

	int size() const;

	void swap(Array& other);
	int search(int const value) const;
	void sort();
	bool insert(int const value, int const index);
	bool remove(int const index);

	int& operator[](int index);
	const int& operator[](int index) const;
	Array& operator=(const Array& other);
	Array& operator=(Array&& other);

private:
	int* m_array = nullptr;
	int m_size = 1;
};