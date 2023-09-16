#include "BoolVector.h"


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

BoolVector::BoolVector(const BoolVector& otherVector)
{
	m_len = otherVector.m_len;

	m_letters = new char[m_len];

	for (int i = 0; i < m_len; ++i)
		m_letters[i] = otherVector.m_letters[i];
}

BoolVector::BoolVector(const int len, const int bitValue = 0)
{
	m_len = len;
	m_letters = new char[m_len];

	for (int i = 0; i < m_len; ++i)
		m_letters[i] = char(bitValue);
}

BoolVector::~BoolVector()
{
	delete[] m_letters;
}

void BoolVector::bitSet(const int index, const int bitValue)
{
	int mask = 1;
	int i = 0;
	getPosition(i, mask, index);

	if (bitValue == 0)
		m_letters[i] &= ~mask;
	else if (bitValue == 1)
		m_letters[i] |= mask;
	else
		throw std::invalid_argument("Bit may can only 1 or 0 value");
}

void BoolVector::inversion()
{

	for (int i = 0; i < m_len; ++i)
	{
		int mask = 1;
		for (int j = 0; j < m_letterLen - 1 and i * m_letterLen + j < m_vectorLen; ++j) //ToDo
		{
			m_letters[i] ^= mask;
			mask <<= 1;
		}
	}
}

void BoolVector::bitInvertion(int index)
{
	int mask = 1;
	int symbolNum = 0;
	getPosition(symbolNum, mask, index);

	m_letters[symbolNum] ^= mask;
}

int BoolVector::weight() const
{
	int count = 0;
	for (int i = 0; i < m_vectorLen; ++i)
		count += this->operator[](i);

	return count; 
}

BoolVector BoolVector::operator& (const BoolVector otherVector) const
{
	BoolVector vector(std::max(m_vectorLen, otherVector.m_vectorLen));

	for (int i = 0; i < vector.m_vectorLen; ++i)
	{
		int mask = 1;
		int j = 0;
		if (this->operator[](i) == 1 and otherVector[i] == 1)
		{
			getPosition(j, mask, i);
			vector.m_letters[j] |= mask;
		}

	}

	return vector;
}

BoolVector BoolVector::operator | (const BoolVector otherVector) const
{
	BoolVector vector(std::max(m_vectorLen, otherVector.m_vectorLen));

	for (int i = 0; i < vector.m_vectorLen; ++i)
	{
		int mask = 1;
		int j = 0;
		if (this->operator[](i) == 1 or otherVector[i] == 1)
		{
			getPosition(j, mask, i);
			vector.m_letters[j] |= mask;
		}

	}

	return vector;
}

BoolVector BoolVector::operator ^ (const BoolVector otherVector) const
{
	BoolVector vector(std::max(m_vectorLen, otherVector.m_vectorLen));

	for (int i = 0; i < vector.m_vectorLen; ++i)
	{
		int mask = 1;
		int j = 0;
		if (this->operator[](i) == otherVector[i])
		{
			getPosition(j, mask, i);
			vector.m_letters[j] |= mask;
		}
	}

	return vector;
}

void BoolVector::getPosition(int& symbolNum, int& mask, int index) const
{
	indexAdmissable(index);

	if (index == 0)
	{
		symbolNum = m_len - 1;
		mask = 1;
	}
	else if ((index + 1) % m_letterLen != 0)
	{
		symbolNum = m_len - (index + 1) / m_letterLen;
		mask <<= m_letterLen - 1;
	}
	else
	{
		symbolNum = m_len - ((index + 1) / m_letterLen) - 1;
		mask <<= index % m_letterLen;
	}
}

std::ostream& operator << (std::ostream& vectorOut, BoolVector vector)
{
	for (int i = 0; i < vector.m_vectorLen; ++i)
	{
		vectorOut << vector[i] << " ";
	}

	return vectorOut;
}

std::istream& operator>> (std::istream& vectorIn, BoolVector& vector)
{
	std::cout << "Enter the number of bits: ";

	std::cin >> vector.m_vectorLen;
	vector.m_len = vector.m_vectorLen / vector.m_letterLen;

	if (vector.m_letters)
		delete[] vector.m_letters;

	vector.m_letters = new char[vector.m_len];

	std::cout << "Enter the bits: ";

	int bit = 0;
	for (int i = 0; i < vector.m_len; ++i)
	{
		vector.m_letters[i] = char(0);

		for (int j = 0; j < vector.m_letterLen; ++j)
		{
			std::cin >> bit;
			if (bit)
			{
				bit <<= j;
				vector.m_letters[i] &= bit;
			}

		}
	}

	return vectorIn;
}

int BoolVector::operator [] (int index) const
{
	int i = 0;
	int mask = 1;
	getPosition(i, mask, index);

	if (m_letters[i] & mask)
		return 1;
	return 0;
}

void BoolVector::indexAdmissable(int index) const
{
	if (!(index >= 0 and index < m_vectorLen))
		throw std::out_of_range("Index out of range");
}

int main()
{
	const int len = 5;
	BoolVector vector;
}