#pragma once
#include <iostream>
#include <assert.h>

class BoolVector
{
public: 

	class Rank;

public:

	using Cell = unsigned char;
	static const int CellSize = 8;

	BoolVector(int length = CellSize);
	BoolVector(int length, bool value);
	BoolVector(const BoolVector& other);
	BoolVector(const char* array);
	~BoolVector();

	int length() const;
	int weight() const;

	void swap(BoolVector& other);
	void inversion();
	void inversion(int index);

	bool bitValue(int index) const;
	void setBitValue(int index, bool value);
	void setBitValues(int index, int length, bool value);
	void setValue(bool value);

	friend std::istream& operator>>(std::istream& is, BoolVector& boolVector);
	friend std::ostream& operator<<(std::ostream& os, const BoolVector& boolVector);
	BoolVector& operator=(const BoolVector& other);
	Rank operator[](int index);


private:
	int _excessRankCount() const;
	static Cell _mask(int index);

private:
	Cell* m_cells = nullptr;
	int m_cellCount = 0;
	int m_length = 0;

};

class BoolVector::Rank
{
public:
	Rank() = default;
	Rank(Cell* cell, Cell mask);
	Rank& operator=(const Rank& other);
	Rank& operator=(bool value);
	operator bool() const;

private:
	Cell* m_cell = nullptr;
	Cell m_mask = 0;
};