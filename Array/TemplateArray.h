#pragma once

#include <iostream>

template <class T>
class TemplateArray
{
public:
	TemplateArray();
	TemplateArray(const TemplateArray& otherArray);
	TemplateArray(T* arr, const int len);
	TemplateArray(T* arr, int len, int addition, int maxDifference);
	~TemplateArray();

	int find(T elem) const;

	friend std::ostream& operator << (std::ostream& arrOut, const TemplateArray array);
	friend std::istream& operator << (std::istream& arrIn, TemplateArray &array);

	void insert(int index, const T elem);

	void erase(int index);
	bool remove(const T elem);

	void leftShift(int index, int step);
	void rightShift(int index, int step);

	T max() const;
	T min() const;
	void sort();

	TemplateArray& operator -= (int index);
	TemplateArray operator - (T elem) const;
	T& operator [] (int index);
	TemplateArray& operator = (const TemplateArray& otherArray);
	TemplateArray& operator += (T elem);
	TemplateArray operator + (T elem) const;
	TemplateArray& operator += (const TemplateArray& otherArray);
	TemplateArray operator + (const TemplateArray& otherArray) const;
	bool operator == (const TemplateArray& otherArray) const;
	bool operator != (const TemplateArray& otherArray) const;

private:
	const int m_maxDifferenceBetweenRealLenAndMaxLen = 10;
	const int m_additionInLength = 5;

	T* m_arr = nullptr;
	int m_realLen = 0;
	int m_maxLen = m_realLen + m_additionInLength;

	bool indexAdmissible(const int index) const;
	bool notEmpty() const;

	void rightShiftAndInsert(const int index, const T elem);
	void leftShiftAndErase(const int index);

	void swap(T& a, T& b);
};

