#include "TemplateArray.h"

template<class T>
TemplateArray<T>::TemplateArray(const TemplateArray& otherArray)
{
	m_realLen = otherArray.m_realLen;
	m_maxLem = otherArray.m_maxLen;

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

