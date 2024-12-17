#include "boolVector.h"

BoolVector::BoolVector(int length)
	:m_length(length)
{
	assert(length >= 0);
	m_cellCount = m_length / CellSize;
	if (m_length % CellSize != 0)
	{
		m_cellCount++;
	}
	m_cells = new Cell[m_cellCount];
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = 0;
	}
}

BoolVector::BoolVector(int length, bool value)
	:m_length(length)
{
	assert(length >= 0);
	m_cellCount = m_length / CellSize;
	if (m_length % CellSize != 0)
	{
		m_cellCount++;
	}
	m_cells = new Cell[m_cellCount];
	if(value)
		for (int i = 0; i < m_cellCount; i++)
		{
			m_cells[i] = ~0;
		}
	else
		for (int i = 0; i < m_cellCount; i++)
		{
			m_cells[i] = 0;
		}
}

BoolVector::BoolVector(const BoolVector& other)
{
	m_cellCount = other.m_cellCount;
	m_length = other.m_length;
	m_cells = new Cell[m_cellCount];
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = other.m_cells[i];
	}
}

BoolVector::BoolVector(const char* array)
{
	assert(array != nullptr);
	m_length = std::strlen(array);
	m_cellCount = m_length / CellSize;
	if (m_length % CellSize != 0)
	{
		m_cellCount++;
	}
	m_cells = new Cell[m_cellCount];
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = 0;
	}

	for (int i = 0; i < m_length; i++)
	{
		if (array[i] == '1')
		{
			setBitValue(i, 1);
		}
	}
}

BoolVector::~BoolVector()
{
	delete[] m_cells;
}

int BoolVector::length() const
{
	return m_length;
}

int BoolVector::weight() const
{
	int sum = 0;
	for (int i = 0; i < m_length; i++)
	{
		if (bitValue(i))
			sum++;
	}
	return sum;
}

void BoolVector::swap(BoolVector& other) {
	std::swap(m_cells, other.m_cells);
	std::swap(m_cellCount, other.m_cellCount);
	std::swap(m_length, other.m_length);
}

void BoolVector::inversion()
{
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = ~m_cells[i];
	}
}

void BoolVector::inversion(int const index)
{
	assert(index >= 0 && index < m_length);
	Cell mask = _mask(index);
	m_cells[index / CellSize] = ~(m_cells[index / CellSize] ^ ~mask);
}

bool BoolVector::bitValue(int const index) const
{
	assert(index >= 0 && index < m_length);
	Cell mask = _mask(index);
	return m_cells[index / CellSize] & mask;
}

void BoolVector::setBitValue(int const index, bool const value)
{
	assert(index >= 0 && index < m_length);
	Cell mask = _mask(index);
	if (value)
	{
		m_cells[index / CellSize] |= mask;
	}
	else
	{
		m_cells[index / CellSize] &= ~mask;
	}
}

void BoolVector::setBitValues(int const index, int const length, bool const value)
{
	assert(index >=0 && index < m_length && m_length >= length - index);
	for (int i = index; i < index + length; i++)
		setBitValue(i, value);
}

void BoolVector::setValue(bool const value)
{
	if (value)
	{
		for (int i = 0; i < m_cellCount; i++)
			m_cells[i] = ~0;
	}
	else
	{
		for (int i = 0; i < m_cellCount; i++)
			m_cells[i] = 0;
	}
}

bool BoolVector::full0() const
{
	for(int i = 0; i < m_cellCount; i++)
		if(m_cells != 0)
			return false;
	return true;
}

bool BoolVector::full1() const
{
	for (int i = 0; i < m_length; i++)
		if (!bitValue(i))
			return false;
	return true;
}


BoolVector& BoolVector::operator=(const BoolVector& other)
{
	BoolVector bvCopy(other);
	swap(bvCopy);
	return *this;
}

BoolVector BoolVector::operator&(const BoolVector& other) const
{
	BoolVector bvCopy(*this);
	for (int i = 0; i < m_cellCount; i++)
		bvCopy.m_cells[i] = m_cells[i] & other.m_cells[i];
	return bvCopy;
}

BoolVector& BoolVector::operator&=(const BoolVector& other)
{
	for (int i = 0; i < m_cellCount; i++)
		m_cells[i] &= other.m_cells[i];
	return *this;
}

BoolVector BoolVector::operator|(const BoolVector& other) const
{
	BoolVector bvCopy(*this);
	for (int i = 0; i < m_cellCount; i++)
		bvCopy.m_cells[i] = m_cells[i] | other.m_cells[i];
	return bvCopy;
}

BoolVector& BoolVector::operator|=(const BoolVector& other)
{
	for (int i = 0; i < m_cellCount; i++)
		m_cells[i] |= other.m_cells[i];
	return *this;
}

BoolVector BoolVector::operator^(const BoolVector& other) const
{
	BoolVector bvCopy(*this);
	for (int i = 0; i < m_cellCount; i++)
		bvCopy.m_cells[i] = m_cells[i] ^ other.m_cells[i];
	return bvCopy;
}

BoolVector& BoolVector::operator^=(const BoolVector& other)
{
	for (int i = 0; i < m_cellCount; i++)
		m_cells[i] ^= other.m_cells[i];
	return *this;
}

BoolVector BoolVector::operator~() const
{
	BoolVector bvCopy(*this);
	bvCopy.inversion();
	return bvCopy;
}

BoolVector BoolVector::operator>>(int const shift) const
{
	if (shift <= 0)
		return *this;
	BoolVector result(m_length);
	if (shift >= m_length)
		return result;
	for (int i = shift; i < m_length; i++)
	{
		if (bitValue(i - shift)) 
		{
			result.setBitValue(i, true);
		}
	}
	return result;
}

BoolVector& BoolVector::operator>>=(int const shift)
{
	*this = *this >> shift;
	return *this;
}

BoolVector BoolVector::operator<<(int const shift) const
{
	if (shift <= 0)
		return *this;
	BoolVector result(m_length);
	if (shift >= m_length)
		return result;
	for (int i = 0; i < m_length - shift; ++i) {
		if (bitValue(i + shift)) {
			result.setBitValue(i, true);
		}
	}

	return result;
}

BoolVector& BoolVector::operator<<=(int const shift)
{
	*this = *this << shift;
	return *this;
}

BoolVector::Rank BoolVector::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return Rank(&m_cells[index / CellSize], _mask(index));
}

int BoolVector::_excessRankCount() const
{
	return (m_cellCount * CellSize - m_length);
}

BoolVector::Cell BoolVector::_mask(int index)
{
	Cell mask = 1;
	mask <<= CellSize - 1 - (index % CellSize);
	return mask;
}

BoolVector::Rank::Rank(Cell* cell, Cell mask)
	:m_cell(cell)
	,m_mask(mask)
{
	assert(m_cell != nullptr && m_mask > 0);
}

BoolVector::Rank& BoolVector::Rank::operator=(const Rank& other)
{
	return operator=(static_cast<bool>(other));
}

BoolVector::Rank& BoolVector::Rank::operator=(bool value)
{
	if (value)
	{
		*m_cell |= m_mask;
	}
	else
	{
		*m_cell &= ~m_mask;
	}
	return *this;
}

BoolVector::Rank::operator bool() const
{
	return(*m_cell & m_mask) != 0;
}

std::istream& operator>>(std::istream& is, BoolVector& boolVector)
{
	for (int i = 0; i < boolVector.length(); i++)
	{
		bool bit;
		is >> bit;
		boolVector.setBitValue(i, bit);
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, BoolVector boolVector)
{
	for (int i = 0; i < boolVector.length(); i++)
		os << boolVector[i];
	return os;
}

