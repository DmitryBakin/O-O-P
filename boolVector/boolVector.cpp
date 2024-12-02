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

void BoolVector::swap(BoolVector& other) {
	std::swap(m_cells, other.m_cells);
	std::swap(m_cellCount, other.m_cellCount);
	std::swap(m_length, other.m_length);
}

bool BoolVector::bitValue(int index) const {
	assert(index >= 0 && index < m_length);
	Cell mask = _mask(index);
	return m_cells[index / CellSize] & mask;
}

void BoolVector::setBitValue(int index, bool value)
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

BoolVector& BoolVector::operator=(const BoolVector& other)
{
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
	assert(m_cell != nullptr);
	assert(m_mask > 0);
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
std::istream& operator<<(std::istream& is, BoolVector boolVector)
{
	for (int i = 0; i < boolVector.length(); i++)
	return is;
}

std::ostream& operator<<(std::ostream& os, BoolVector boolVector)
{
	for (int i = 0; i < boolVector.length(); i++)
		os << boolVector[i];
	return os;
}




/*Необходимые методы класса :
-конструкторы(по умолчанию, с параметрами(размер и значение - одно и то же для всех разрядов), конструктор из массива const char*, конструктор копирования);
-деструктор;
-длина(количество бит) вектора;
-обмен содержимого с другим вектором(swap);
-ввод / вывод в консоль(потоковый);
-инверсия всех компонент вектора;
-инверсия i - ой компоненты;
-установка в 0 / 1 i - ой компоненты;
-установка в 0 / 1 k компонент, начиная с i - ой;
-установка в 0 / 1 всех компонент вектора;
-вес вектора(количество единичных компонент).

Необходимые перегрузки :
-получение компоненты([], см.примечание ниже);
-побитовое умножение(&, &=);
-побитовое сложение(| , |=);
-побитовое исключающее ИЛИ(^, ^=);
-побитовые сдвиги(<< , >> , <<=, >>=);
-побитовая инверсия(~);
-присваивание(= ).

Примечание: получение компоненты подразумевается только на чтение(т.е., возвращается значение бита в виде int / char / bool, а записать значение в бит нельзя - для этого можно использовать соответствующую функцию).Однако есть способ реализовать данный оператор с возможностью записи значения в соответствующий разряд.Для решения этой задачи предлагается следующий подход :
Оператор[i] возвращает объект некоторого нового класса(далее "класс BoolRank"), который :
	1. Имеет доступ к ячейке, содержащей i - ую компоненту;
2. Содержит информацию о позиции компоненты в ячейке.
Т.о., используя битовую маску, объект класса BoolRank может изменять значения нужного бита.
Всё, что после этого будет нужно реализовать - перегрузки стандартных операций(присваивание, битовое сложение, умножение, инверсия, исключающее ИЛИ.Рекомендуется также определить операции сравнения и присваивание, как между объектами класса BoolRank, так и с одним из базовых типов(int / bool / char), а также конвертацию типа Rank в один из базовых типов.
*/

