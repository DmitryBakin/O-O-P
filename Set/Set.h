#pragma once
#include <iostream>
#include <string>
#include "..\boolVector\boolVector.h"

const int charSize = 128;

class Set : public BoolVector
{
public:
	Set();
	Set(const char* array, const int size);
	Set(const Set& other);
	~Set() = default;

	const char maxElement() const;
	const char minElement() const;

	bool containsElement(const char ch);
	const int power() const;

	Set& operator=(const Set& other);

	bool operator==(const Set& other) const;
	bool operator!=(const Set& other) const;

	Set operator|(const Set& other) const;
	Set& operator|=(const Set& other);
	Set operator&(const Set& other) const;
	Set& operator&=(const Set& other);
	Set operator/(const Set& other) const;
	Set& operator/=(const Set& other);
	Set operator~() const;
	Set operator+(const char ch) const;
	Set& operator+=(const char ch);
	Set operator-(const char ch) const;
	Set& operator-=(const char ch);


	friend std::ostream& operator<<(std::ostream& os, const Set& other);
	friend std::istream& operator>>(std::istream& is, Set& other);

private:
	void m_add(const char ch);
	void m_remove(const char ch);
}; 
