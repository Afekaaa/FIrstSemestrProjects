#include "..\Array\TemplateArray.h"
#include <iostream>


class BoolVector
{
public:
	BoolVector();
	BoolVector(const char* mas, const int len);
	BoolVector(const BoolVector otherBoolVector);
	BoolVector(const int len);
	~BoolVector() = default;

	friend std::ostream operator << (std::ostream vectorOut, BoolVector vector);
	friend std::istream operator >> (std::istream vectorIn, BoolVector vector);

	void inversion();
	void bitInvertion(int index);

	void bitSet(int index, int value);
	void bitReplacment(int index, int value);
	void vectorReplacement(int value);

	int vectorWeight() const;

	int operator [](int index);
	BoolVector operator & (const BoolVector otherVector) const;
	BoolVector& operator &= (const BoolVector otherVector);
	BoolVector operator | (const BoolVector otherVector) const;
	BoolVector& operator &= (const BoolVector otherVector);
	BoolVector operator ^ (const BoolVector otherVector) const;
	BoolVector& operator ^= (const BoolVector otherVector);
	BoolVector operator << (const int step) const;
	BoolVector& operator  <<= (const int step);
	BoolVector operator >> (const int step) const;
	BoolVector& operator >>= (const int step);
	BoolVector& operator ~ ();
	BoolVector& operator = (const BoolVector otherVector);

private:
	const int m_additionInLength = sizeof(char);

	TemplateArray<char> m_bits;
	int m_realLen = 0;
	int m_maxLen = m_realLen + m_additionInLength;

	bool indexAdmissable(int index);
	
};