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
	char* m_letters = nullptr;

	int m_len = 0;
	int m_letterLen = sizeof(char);
	int m_vectorLen = m_len * m_letterLen;

	void indexAdmissable(int index);
	void getPosition(int& symbolsNum, int& mask, int index);
};