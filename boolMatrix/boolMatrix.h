#pragma once
#include <iostream>
#include <assert.h>
#include "../boolVector/boolVector.h"
#include "../Array/Array.h"

class BoolMatrix 
{
public:

	BoolMatrix();
	BoolMatrix(int const lineCount, int const columnCount, bool value);
	BoolMatrix(const BoolMatrix& other);
	BoolMatrix(const char** other, int const lineCount);
	~BoolMatrix();

	int lineCount() const;
	int columnCount() const;
	int weight() const;
	int weightLine(int const index) const;

	void swap(BoolMatrix& other);
	void inversionComponent(int const line, int const column);
	void inversionComponents(int const line, int const column, int const k);

	void setComponent(int line, int column, bool value);
	void setComponents(int line, int column, int k, bool value);

	BoolVector conjunctionAllLines() const;
	BoolVector disjunctionAllLines() const;

	BoolVector& operator[](int const index);
	const BoolVector& operator[](int const index) const;

	BoolMatrix& operator=(const BoolMatrix& other);
	BoolMatrix operator&(const BoolMatrix& other) const;
	BoolMatrix& operator&=(const BoolMatrix& other);
	BoolMatrix operator|(const BoolMatrix& other) const;
	BoolMatrix& operator|=(const BoolMatrix& other);
	BoolMatrix operator^(const BoolMatrix& other) const;
	BoolMatrix& operator^=(const BoolMatrix& other);
	BoolMatrix operator~() const;

	friend std::ostream& operator<<(std::ostream& os, BoolMatrix& other);
	friend std::istream& operator>>(std::istream& is, BoolMatrix& other);

private:
	Array<BoolVector> m_matrix;
	int m_lineCount = 0;
	int m_columnCount = 0;

};
