#include "TemplateArray.h"

template<class T>
TemplateArray<T>::TemplateArray(const TemplateArray& otherArray)
{
	m_realLen = otherArray.m_realLen;
	m_maxLen = otherArray.m_maxLen;

	m_arr = new T[m_maxLen];

	for (int i = 0; i < m_realLen; ++i)
		m_arr[i] = otherArray.m_arr[i];
}

template<class T>
TemplateArray<T>::TemplateArray(T* arr, const int len)
{
	m_realLen = len;
	m_maxLen = m_realLen + m_additionInLength;

	m_arr = new T[m_maxLen];

	for (int i = 0; i < m_realLen; ++i)
		m_arr[i] == arr[i];
}

template<class T>
TemplateArray<T>::~TemplateArray()
{
	delete[] m_arr;
}

template<class T>
int TemplateArray<T>::find(T elem) const
{
	for (int i = 0; i < m_realLen; ++i)
		if (m_arr[i] == elem)
			return i;
	
	return - 1;
}

template<class T>
std::ostream operator << (std::ostream arrOut, TemplateArray<T> array)
{
	for (int i = 0; i < array.m_reelLen; ++i)
		arrOut << array.m_arr[i] << " ";

	return arrOut;
}

template<class T>
std::istream operator << (std::istream arrIn, TemplateArray<T> array)
{
	std::cout << "Enter the number of elements: ";
	std::cin >> array.m_realLen;
	array.m_maxLen = array.m_realLen + array.m_additionInLength;

	delete[] array.m_mas;
	array.m_mas = new int[array.m_maxLen];

	std::cout << std::endl << "Enter the elements: ";
	for (int i = 0; i < array.m_realLen; ++i)
		arrIn >> array.m_mas[i];

	return arrIn;
}

