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

BoolVector::BoolVector(const BoolVector otherVector)
{
	n_len = otherVector.m_len;

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
	for (int i = 0; i < m_len; ++i)
	{
		int mask = 1;
		for (itn j = 0; i < m_letterLen; ++j)
		{

		}
	}
}

friend std::istream operator >> (std::istream vectorIn, BoolVector? vector)
{
	std::cout << "Enter the nuber of bits: ";
	std::cin << m_realLen;
	m_maxLen = m_realLen + m_additionInLength;
	
	
}


int boolVector::operator [] (int index)
{
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

int main()
{
	const int len = 5;
	BoolVector vector;
}