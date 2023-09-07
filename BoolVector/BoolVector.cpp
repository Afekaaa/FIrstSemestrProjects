#include "BoolVector.h"


BoolVector::BoolVector()
{
	m_additionInLength = sizeof(char);
	m_realLen = 0;
	m_maxLen = m_realLen + m_additionInLength;

	m_bits(nullptr, 0, 1, 1);
}

BoolVector::BoolVector(const char* mas, const int len)
{
	m_additionInLength = sizeof(char);
	m_realLen = 0;
	m_maxLen = m_realLen + m_additionInLength;

	m_bits(mas, len, 1, 1);
}

BoolVector::BoolVector(const BoolVector otherVector)
{
	m_additionInLength = sizeof(char);
	m_realLen = otherVector.m_realLen;
	m_maxLen = otherVector.m_maxLen;

	m_bits(otherVector.m_bits, m_realLen, 1, 1);
}

BoolVector::BoolVector(const int len)
{
	m_realLen = len;
	m_maxLen = m_realLen + m_additionInLength;
	
	m_bits(nullptr, m_realLen, 1, 1);
}
