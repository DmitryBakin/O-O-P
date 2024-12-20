#pragma once
#include <iostream>
#include <string>
#include "..\boolVector\boolVector.h"

class Set : public BoolVector
{
public:

    static const int stop = 127;
    static const int start = 33;
    static const int charSize = stop - start;

    Set();
    Set(const char* array, const int size);
    Set(const Set& other) = default;
    Set(const BoolVector& other);
    ~Set() = default;

    char maxElement() const;
    char minElement() const;

    bool containsElement(const char ch) const;
    const int power() const;

    Set& operator=(const Set& other) = default;

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
