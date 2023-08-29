#pragma once

#include <iostream>

template <class T>
class TemplateArray
{
public:
	TemplateArray() = default;
	TemplateArray(const TemplateArray& otherArray);
	TemplateArray(T* arr, const int len);
	~TemplateArray();

	int find(T elem) const;

	friend std::ostream operator << (std::ostream arrOut, TemplateArray array);
	friend std::istream operator << (std::istream arrIn, TemplateArray array);

	void insert(int index, T elem);

	void erase(int index);
	bool remove(T elem);

	void leftShift(int index, int step);
	void rightShift(int index, int step);

	TemplateArray& operator -= (int index);
	TemplateArray operator - (T elem) const;
	T& operator [] (int index);
	TemplateArray& operator = (TemplateArray otherArray);
	TemplateArray& operator += (T elem);
	TemplateArray operator + (T elem) const;
	TemplateArray& operator += (TemplateArray otherArray);
	TemplateArray operator + (TemplateArray otherArray) const;
	bool operator == (TemplateArray otherArray) const;
	bool operator != (TemplateArray otherArray) const;

private:
	const int maxDifferenceBetweenRealLenAndMaxLen = 10;
	const int m_additionInLength = 5;

	T* m_arr = nullptr;
	int m_realLen = 0;
	int m_maxLen = m_realLen + m_additionInLength;
};

