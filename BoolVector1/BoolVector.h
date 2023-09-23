#include <iostream>


class BoolVector
{
public:
	BoolVector();
	BoolVector(const char* mas, const int vectorLen);
	BoolVector(const BoolVector& otherBoolVector);
	BoolVector(const int len, const int bitValue);
	~BoolVector();

	friend std::ostream& operator << (std::ostream& vectorOut, const BoolVector& vector);
	friend std::istream& operator >> (std::istream& vectorIn, BoolVector& vector);

	void inverse();
	void inverseBit(int index);

	int weight() const;

	void setBit(const int index, const int bitValue = 0);

	int operator [](int index) const;
	BoolVector& operator = (const BoolVector& otherVector);
	BoolVector operator & (const BoolVector& otherVector) const;
	BoolVector& operator &= (const BoolVector& otherVector);
	BoolVector operator | (const BoolVector& otherVector) const;
	BoolVector& operator |= (const BoolVector& otherVector);
	BoolVector operator ^ (const BoolVector& otherVector) const;

private:
	char* m_letters = nullptr;

	int m_len = 0;
	const int m_letterLen = sizeof(char) * 8;
	int m_vectorLen = m_len * m_letterLen;

	void indexAdmissable(int index) const;
	void getPosition(int& symbolsNum, int& mask, int index) const;
};