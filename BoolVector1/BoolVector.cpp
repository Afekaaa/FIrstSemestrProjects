#include "BoolVector.h"


BoolVector::BoolVector()
{
	m_len = 1;
	m_letters = new char[m_len];
	m_vectorLen = m_len * m_letterLen;
}

BoolVector::BoolVector(const char* mas, const int len)
{
	if (mas or len == 0)
		throw std::invalid_argument("The vector length cannot be less than one");

	m_len = len;
	m_letters = new char[m_len];
	m_vectorLen = m_len * m_letterLen;

	for (int i = 0; i < m_len; ++i)
		m_letters[i] = mas[i];
}

BoolVector::BoolVector(const BoolVector& otherVector)
{
	m_len = otherVector.m_len;
	m_vectorLen = m_len * m_letterLen;

	m_letters = new char[m_len];

	for (int i = 0; i < m_len; ++i)
		m_letters[i] = otherVector.m_letters[i];
}

BoolVector::BoolVector(const int len, const int bitValue = 0)
{
	if (len == 0)
		throw std::invalid_argument("The vector length cannot be less than one");

	m_vectorLen = len;

	if (len % m_letterLen != 0)
		m_len = m_vectorLen / m_letterLen + 1;
	else
		m_len = m_vectorLen / m_letterLen;

	m_letters = new char[m_len];

	for (int i = 0; i < m_len; ++i)
		m_letters[i] = char(bitValue);
}

BoolVector::~BoolVector()
{
	delete[] m_letters;
}

void BoolVector::bitSet(const int index, const int bitValue) // на 4
{
	int mask = 1;
	int i = 0;
	getPosition(i, mask, index);

	if (bitValue == 0)
		m_letters[i] &= ~mask;
	else if (bitValue == 1)
		m_letters[i] |= mask;
	else
		throw std::invalid_argument("bit can be one or zero");
}

void BoolVector::inversion()
{
	for (int i = 0; i < m_vectorLen; ++i)
	{
		if (m_letters[i] == 0)
			bitSet(i, 1);
		else
			bitSet(i, 0);
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
	mask = 1;

	if (index == 0)
	{
		symbolNum = m_len - 1;
	}
	else if ((index + 1) % m_letterLen == 0)
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

std::ostream& operator << (std::ostream& vectorOut, const BoolVector& vector)
{
	for (int i = vector.m_vectorLen - 1; i >= 0; --i)
		vectorOut << vector[i] << " ";

	return vectorOut;
}

std::istream& operator>> (std::istream& vectorIn, BoolVector& vector)
{
	std::cout << "Enter the number of bits: ";
	vectorIn >> vector.m_vectorLen;
	if (vector.m_vectorLen % vector.m_letterLen != 0)
		vector.m_len = vector.m_vectorLen / vector.m_letterLen + 1;
	else
		vector.m_len = vector.m_vectorLen / vector.m_letterLen;

	delete[] vector.m_letters;

	vector.m_letters = new char[vector.m_len];
	for (int i =0; i < vector.m_len; ++i)
		vector.m_letters[i] = char(0);

	std::cout << "Enter the bits: ";

	int bit = 0;
	
	for (int i = vector.m_vectorLen - 1; i >= 0; --i)
	{
		std::cin >> bit;

		if (bit == 1)
		{
			vector.bitSet(i, bit);
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
	BoolVector vector(len);

	std::cout << vector;
	std::cin >> vector;
	std::cout << std::endl << vector << std::endl;

	std::cout << vector[0] << vector[1] << vector[2] << vector[3];
}