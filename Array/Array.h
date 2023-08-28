#pragma once

#include "C:\Users\Zykov Vladimir\source\repos\HoarSort\HoarSort\HoarSort.cpp"
#include <iostream>

class Array
{
public:
	Array();
	Array(const int len);
	Array(const int* mas, const int len);

	Array(const Array& otherMas);
	~Array();

	void sort(); 
	void insert(const int index, const int num);
	void erase(const int index);

	int getIndexElem(const int num) const;
	int getMinElem() const;
	int getMaxElem() const;
	int getLen() const;

	bool masAdmissible() const;

	bool remove(const int num);

	void rightShift(int index, int step);
	void leftShift(int index, int step);

	friend std::ostream& operator << (std::ostream& masOut, Array arr);
	friend std::istream& operator >> (std::istream& masIn, Array arr);

	int& operator [] (const int index);
	Array& operator -= (const int index);
	Array operator - (const int num);
	Array& operator	= (const Array& otherMas);
	Array operator	+ (const int num) const;
	Array& operator	+= (const int num);

	Array operator + (const Array& otherMas) const;
	Array& operator	+= (const Array& otherMas);

	bool operator == (const Array& otherMas) const;
	bool operator != (const Array& otherMas) const;

private:
	const int maxDifferenceBetweenRealLenAndMaxLen = 10;
	const int m_additionInLength = 5;

	int* m_mas = nullptr;
	int m_realLen = 0;
	int m_maxLen = m_realLen + m_additionInLength;

	bool indexAdmissible(const int index) const;
	void rightShifftAndInsert(const int index, const int num);
	void leftShiftAndErase(const int index);

};

