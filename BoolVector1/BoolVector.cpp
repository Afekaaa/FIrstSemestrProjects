﻿#include "BoolVector.h"


BoolVector::BoolVector()
{
	m_len = 1;
	m_letters = new char[m_len];
}

BoolVector::BoolVector(const char* mas, const int len)
{
	m_len = len;
	m_letters = new char[m_len];

	for (int i = 0; i < m_len; ++i)
		m_letters[i] = mas[i];
}

BoolVector::BoolVector(const BoolVector otherVector)
{
	m_len = otherVector.m_len;

	m_letters = new char[m_len];

	for (int i = 0; i < m_len; ++i)
		m_letters[i] = otherVector.m_letters[i];
}

BoolVector::BoolVector(const int len)
{
	m_len = len;
	m_letters = new char[m_len];

	for (int i = 0; i < m_len; ++i)
		m_letters[i] = char(0);
}

BoolVector::~BoolVector()
{
	delete[] m_letters;
}

friend std::ostream operator << (std::ostream vectorOut, BoolVector vector)
{
	for (int i = 0; i < vector.m_vectorLen; ++i)
	{
		std::cout << vector[i] << " ";
	}
}

friend std::istream operator >> (std::istream vectorIn, BoolVector vector)
{
	std::cout << "Enter the nuber of bits: ";
	std::cin << vector.m_realLen;
	vector.m_maxLen = vector.m_realLen + vector.m_additionInLength;


}

void BoolVector::inversion()
{

	for (int i = 0; i < m_len; ++i)
	{
		int mask = 1;
		for (int j = 0; j < m_letterLen - 1 and i * m_letterLen + j < m_vectorLen; ++j) //ToDo
		{
			m_letters[m_i] ^= mask;
			mask <<= 1;
		}
	}
}

void BoolVector::bitInvertion(int index)
{


	int mask = 1;
	mask <<= index - 1;

}

void BoolVector::getPosition(int& symbolsNum, int& mask, int index)
{
	indexAdmissable(index);

	if (index == 0)
	{
		symbolsNum = m_len - 1;
		mask = 1;
		return;
	}

	if (index % m_letterLen != 0)
	{
		symbolsNum = index / m_letterLen;
		mask <<= index % m_letterLen - 1;
	}
	else
	{
		i = index / m_letterLen - 1;
		mask <<= index % m_letterLen - 1;
	}



}

int BoolVector::operator [] (int index)
{
	indexAdmissable(index);

	if (index == 0)
		return m_letters[m_len - 1] & 1;

	int i = 0;
	int mask = 1;

	if (index % m_letterLen != 0)
	{
		i = index / m_letterLen;
		mask <<= index % m_letterLen - 1;
	}
	else
	{
		i = index / m_letterLen - 1;
		mask <<= m_letterLen - 1;
	}

	return m_letters[m_len - i - 1] & mask;

}

void BoolVector::indexAdmissable(int index)
{
	if (!(index >= 0 and index < m_vectorLen))
		throw std::out_of_range("Index out of range");
}

int main()
{
	const int len = 5;
	BoolVector vector;
}