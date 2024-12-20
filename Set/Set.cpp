﻿#include "Set.h"

Set::Set()
    :BoolVector(charSize)
{}

Set::Set(const char* array, int const size)
    :BoolVector(charSize)
{
    for (int i = 0; i < size; i++)
        m_add(array[i]);
}

Set::Set(const BoolVector& other)
    :BoolVector(other)
{}

char Set::maxElement() const
{
    for (int i = charSize - 1; i >= 0; i--)
        if (bitValue(i))
            return i;
    return 0;
}

char Set::minElement() const
{
    for (int i = 0; i < charSize; i++)
        if (bitValue(i))
            return i;
    return 0;
}

bool Set::containsElement(const char ch) const
{
    return bitValue(ch);
}

const int Set::power() const
{
    return weight();
}

bool Set::operator==(const Set& other) const
{
    for (int i = 0; i < charSize; i++)
        if (bitValue(i) != other.bitValue(i))
            return false;
    return true;
}

bool Set::operator!=(const Set& other) const
{
    return !(operator==(other));
}

Set Set::operator|(const Set& other) const
{
    Set setCopy(BoolVector::operator|(other));
    return setCopy;
}

Set& Set::operator|=(const Set& other)
{
    operator|(other).swap(*this);
    return *this;
}

Set Set::operator&(const Set& other) const
{
    Set setCopy(BoolVector::operator&(other));
    return setCopy;
}

Set& Set::operator&=(const Set& other)
{
    operator&(other).swap(*this);
    return *this;
}

Set Set::operator/(const Set& other) const
{
    Set setCopy(BoolVector::operator&(~other));
    return setCopy;
}

Set& Set::operator/=(const Set& other)
{
    operator/(other).swap(*this);
    return *this;
}

Set Set::operator~() const
{
    Set setCopy(BoolVector::operator~());
    return setCopy;
}

Set Set::operator+(const char ch) const
{
    Set setCopy(*this);
    setCopy.m_add(ch - start);
    return setCopy;
}

Set& Set::operator+=(const char ch)
{
    operator+(ch).swap(*this);
    return *this;
}

Set Set::operator-(const char ch) const
{
    Set setCopy(*this);
    setCopy.m_remove(ch - start);
    return setCopy;
}

Set& Set::operator-=(const char ch)
{
    operator-(ch).swap(*this);
    return *this;
}

void Set::m_add(const char ch)
{
    setBitValue(ch, true);
}

void Set::m_remove(const char ch)
{
    setBitValue(ch, false);
}

std::ostream& operator<<(std::ostream& os, const Set& other)
{
    os << "{";
    bool first = true;
    for (int i = 0; i < other.charSize; i++)
        if (other.bitValue(i))
        {
            if (!first)
                os << ", ";
            os << static_cast<char>(i + other.start);
            first = false;
        }
    os << "}" << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Set& other)
{
    other.setValue(false);
    std::string input;
    is >> input;
    char c;
    for (int i = 0; i < input.size(); i++)
    {
        c = input[i];
        other.m_add(c - other.start);
    }
    return is;
}