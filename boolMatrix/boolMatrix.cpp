#include "boolMatrix.h"


BoolMatrix::BoolMatrix()
{}

BoolMatrix::BoolMatrix(int const lineCount, int const columnCount, bool value)
	: m_lineCount(lineCount)
	, m_columnCount(columnCount)
{
	BoolVector bv(columnCount, value);
	for (int i = 0; i < m_lineCount; i++)
	{
		m_matrix.insert(i, bv);
	}
}

BoolMatrix::BoolMatrix(const BoolMatrix& other)
	: m_lineCount(other.m_lineCount)
	, m_columnCount(other.m_lineCount)
{
	for (int i = 0; i < m_lineCount; i++)
		m_matrix.insert(i, other[i]);
}

BoolMatrix::BoolMatrix(const char** other, int const lineCount)
	: m_lineCount(lineCount)
{
	assert(other != nullptr);
	m_columnCount = std::strlen(other[0]);
	for (int i = 0; i < m_lineCount; i++)
	{
		BoolVector bv(other[i]);
		m_matrix.insert(i, bv);
	}
}

BoolMatrix::~BoolMatrix()
{
}

int BoolMatrix::lineCount() const
{
	return m_lineCount;
}

int BoolMatrix::columnCount() const
{
	return m_columnCount;
}

int BoolMatrix::weight() const
{
	int weight = 0;
	for (int i = 0; i < m_lineCount; i++)
		weight+=m_matrix[i].weight();
	return weight;
}

int BoolMatrix::weightLine(int const index) const
{
	assert(index >= 0 && index < m_lineCount);
	return m_matrix[index].weight();
}

void BoolMatrix::swap(BoolMatrix& other)
{
	std::swap(m_lineCount, other.m_lineCount);
	std::swap(m_columnCount, other.m_columnCount);
	m_matrix.swap(other.m_matrix);
}

void BoolMatrix::inversionComponent(int const line, int const column)
{
	assert(line >= 0 && line < m_lineCount);
	m_matrix[line].inversion(column);
}

void BoolMatrix::inversionComponents(int const line, int const column, int const k)
{
	assert(line >= 0 && line < m_lineCount);
	for(int i = 0; i < k; i++)
		m_matrix[line].inversion(column + i);
}

void BoolMatrix::setComponent(int line, int column, bool value)
{
	assert(line >= 0 && line < m_lineCount);
	m_matrix[line].setBitValue(column, value);
}

void BoolMatrix::setComponents(int line, int column, int k, bool value)
{
	assert(line >= 0 && line < m_lineCount);
	m_matrix[line].setBitValues(column, k, value);
}

BoolVector BoolMatrix::conjunctionAllLines() const
{
	BoolVector bv(m_columnCount,1);
	for (int i = 0; i < m_lineCount; i++)
		bv = bv & m_matrix[i];
	return bv;
}

BoolVector BoolMatrix::disjunctionAllLines() const
{
	BoolVector bv(m_columnCount, 1);
	for (int i = 0; i < m_lineCount; i++)
		bv = bv | m_matrix[i];
	return bv;
}

BoolVector& BoolMatrix::operator[](int const index)
{
	assert(index >= 0 && index < m_lineCount);
	return m_matrix[index];
}

const BoolVector& BoolMatrix::operator[](int const index) const
{
	assert(index >= 0 && index < m_lineCount);
	return m_matrix[index];
}

BoolMatrix& BoolMatrix::operator=(const BoolMatrix& other)
{
	BoolMatrix bm(other);
	swap(bm);
	return *this;
}

BoolMatrix BoolMatrix::operator&(const BoolMatrix& other) const
{
	BoolMatrix bmCopy(*this);
	for (int i = 0; i < m_lineCount; i++)
		bmCopy[i] = m_matrix[i] & other[i];
	return bmCopy;
}

BoolMatrix& BoolMatrix::operator&=(const BoolMatrix& other)
{
	for (int i = 0; i < m_lineCount; i++)
		m_matrix[i] &= other[i];
	return *this;
}

BoolMatrix BoolMatrix::operator|(const BoolMatrix& other) const
{
	BoolMatrix bmCopy(*this);
	for (int i = 0; i < m_lineCount; i++)
		bmCopy[i] = m_matrix[i] | other[i];
	return bmCopy;
}

BoolMatrix& BoolMatrix::operator|=(const BoolMatrix& other)
{
	for (int i = 0; i < m_lineCount; i++)
		m_matrix[i] |= other[i];
	return *this;
}

BoolMatrix BoolMatrix::operator^(const BoolMatrix& other) const
{
	BoolMatrix bmCopy(*this);
	for (int i = 0; i < m_lineCount; i++)
		bmCopy[i] = m_matrix[i] ^ other[i];
	return bmCopy;
}

BoolMatrix& BoolMatrix::operator^=(const BoolMatrix& other)
{
	for (int i = 0; i < m_lineCount; i++)
		m_matrix[i] ^= other[i];
	return *this;
}

BoolMatrix BoolMatrix::operator~() const
{
	BoolMatrix bmCopy(*this);
	for (int i = 0; i < m_lineCount; i++)
		bmCopy[i].inversion();
	return bmCopy;
}

std::ostream& operator<<(std::ostream& os, BoolMatrix& other)
{
	for (int i = 0; i < other.lineCount(); i++)
		os << other[i] << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, BoolMatrix& other)
{
	int lineCount, columnCount;
	is >> lineCount;
	is >> columnCount;

	other.m_lineCount = lineCount;
	other.m_columnCount = columnCount;
	
	for (int i = 0; i < lineCount; i++)
	{
		BoolVector bv(columnCount);
		for(int j = 0; j < columnCount;j++)
		{
			bool b;
			is >> b;
			bv.setBitValue(j,b);
		}
		other.m_matrix.insert(i,bv);
	}
	return is;
}
