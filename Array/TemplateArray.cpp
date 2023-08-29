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
		std::cout << array.m_arr[i] << " ";

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
		std::cin >> array.m_mas[i];

	return arrIn;
}

template<class T>
void TemplateArray<T>::insert(int index, T elem)
{
	if (!indexAdmissible(index))
		throw std::out_of_range("Index out of range");

	if (m_realLen < m_maxLen)
	{
		rightShiftAndInsert(index, elem);
	}
	else
	{
		m_maxLen = m_realLen + m_additionInLength;

		T* tmpArr = new T[m_maxLen];

		for (int i = 0; i < m_realLen; ++i)
			tmpArr[i] = m_arr[i];

		delete[] m_arr;
		m_arr = tmpArr;

		rightShiftAndInsert(index, elem);
	}
}

template<class T>
void TemplateArray<T>::erase(const int index)
{
	if (!masAdmissible())
		throw std::logic_error("Попытка удалить элемент из пустого массива");

	if (!indexAdmissible(index))
		throw std::invalid_argument("Попытка удалить элемент за пределами массива");

	if (m_maxDifferenceBetweenRealLenAndMaxLen > m_maxLen - m_realLen)
		leftShiftAndErase(index);
	else
	{
		leftShiftAndErase(index);

		m_maxLen = m_realLen + m_additionInLength;

		T* tmpArr = new T[m_maxLen];

		for (int i = 0; i < m_realLen; ++i)
			tmpArr[i] = m_arr[i];

		delete[] m_arr;
		m_arr = tmpArr;
	}
}

template <class T>
void TemplateArray<T>::rightShiftAndInsert(const int index, const T elem)
{
	for (int i = m_realLen; i > index; --i)
		m_arr[i] = m_arr[i - 1];

	m_arr[index] = elem;
	m_realLen++;
}

template <class T>
void TemplateArray<T>::leftShiftAndErase(const int index)
{
	for (int i = index; i < m_realLen - 1; ++i)
		m_arr[i] = m_arr[i + 1];
	m_realLen--;
}

template <class T>
bool TemplateArray<T>::remove(T elem)
{
	int index = find(elem);

	if (elem != -1)
	{
		erase(index);
		return true;
	}

	return false;
}

template <class T>
bool TemplateArray<T>::indexAdmissible(const int index) const
{
	if (index >= 0 and index <= m_realLen)
		return true;
	return false;
}

template <class T>
bool TemplateArray<T>::masAdmissible() const
{
	if (m_realLen)
		return true;
	return false;
}