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

template <class T>
TemplateArray<T>::TemplateArray(T* arr, int len, int addition, int maxDifference)
{
	m_realLen = len;
	m_additionInLength = addition;
	m_maxDifferenceBetweenRealLenAndMaxLen = maxDifference;
	m_maxLen = m_realLen + m_additionInLength;

	m_arr = new T[m_maxLen];

	for (int i = 0; i < m_realLen; ++i)
		m_arr[i] == arr[i];
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
std::ostream operator << (std::ostream& arrOut, TemplateArray<T> array)
{
	for (int i = 0; i < array.m_reelLen; ++i)
		arrOut << array.m_arr[i] << " ";

	return arrOut;
}

template<class T>
std::istream operator << (std::istream& arrIn, TemplateArray<T> &array)
{
	std::cout << "Enter the number of elements: ";
	std::cin >> array.m_realLen;
	array.m_maxLen = array.m_realLen + array.m_additionInLength;

	if (array.notEmpty())
		delete[] array.m_mas;

	array.m_mas = new int[array.m_maxLen];

	if (array.m_realLen != 0)
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
	if (!notEmpty())
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

template<class T>
void TemplateArray<T>::swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
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

template<class T>
void TemplateArray<T>::rightShift(int index, int step)
{
	if (step == 0)
		return;

	if (index + step >= m_realLen)
		step = step % (m_realLen - index);

	if (!indexAdmissible(index) or index == m_realLen)
		throw std::out_of_range("index is out of range of array");

	T* tmpArr = new T[m_maxLen];

	for (int i = 0; i < index; ++i)
		tmpArr[i] = m_arr[i];

	for (int i = m_realLen - 1, j = m_realLen - step - 1; j >= index; --i, --j)
		tmpArr[i] = m_arr[j];

	for (int i = index, j = m_realLen - step; j < m_realLen; ++i, ++j)
		tmpArr[i] = m_arr[j];

	delete[] m_arr;
	m_arr = tmpArr;
}

template<class T>
void TemplateArray<T>::leftShift(int index, int step)
{

	if (step == 0)
		return;

	if (index + step >= m_realLen)
		step = step % (m_realLen - index);

	if (!indexAdmissible(index) or index == m_realLen)
		throw std::out_of_range("index is out of range of array");

	T* tmpArr = new T[m_maxLen];

	for (int i = 0; i < index; ++i)
		tmpArr[i] = m_arr[i];

	for (int i = index, j = index + step; j < m_realLen; ++i, ++j)
		tmpArr[i] = m_arr[j];

	for (int i = m_realLen - step, j = index; i < m_realLen; ++i, ++j)
		tmpArr[i] = m_arr[j];

	delete[] m_arr;
	m_arr = tmpArr;
}

template<class T>
T TemplateArray<T>::max() const
{
	if (!notEmpty())
		throw std::logic_error("Отправлен запрос на получение максимального элемента из пустого массива.");

	T maxElem = m_arr[0];

	for (int i = 1; i < m_realLen; ++i)
		if (m_arr[i] > maxElem)
			maxElem = m_arr[i];

	return maxElem;
}

template<class T>
T TemplateArray<T>::min() const
{
	if (!notEmpty())
		throw std::logic_error("Отправлен запрос на получение минимального элемента из пустого массива.");

	int minElem = m_arr[0];

	for (int i = 1; i < m_realLen; ++i)
		if (m_arr[i] < minElem)
			minElem = m_arr[i];

	return minElem;
}

template <class T>
void TemplateArray<T>::sort()
{
	bool notSwap;
	for (int i = 0; i < m_realLen - 1; ++i)
	{
		notSwap = true;
		for (int j = i; j < m_realLen; ++j)
		{
			if (m_arr[i] > m_arr[j])
			{
				swap(m_arr[i], m_arr[j]);
				notSwap = false;
			}
		}

		if (notSwap)
			break;
	}
}

template <class T>
bool TemplateArray<T>::indexAdmissible(const int index) const
{
	if (index >= 0 and index <= m_realLen)
		return true;
	return false;
}

template <class T>
bool TemplateArray<T>::notEmpty() const
{
	if (m_realLen)
		return true;
	return false;
}

template <class T>
TemplateArray<T>& TemplateArray<T>::operator -= (int index)
{
	erase(index);
	return *this;
}

template <class T>
TemplateArray<T> TemplateArray<T>::operator - (T elem) const
{
	remove(elem);
	return *this;
}

template <class T>
T& TemplateArray<T>::operator [] (int index)
{
	if (!notEmpty())
		throw std::logic_error("Попытка получить элемент из пустого массива");

	if (!indexAdmissible(index))
		throw std::invalid_argument("Попытка получить элемент за пределами массива");
	return m_arr[index];
}

template <class T>
TemplateArray<T>& TemplateArray<T>::operator = (const TemplateArray& otherArray)
{
	if (*this == otherArray)
		return *this;

	m_realLen = otherArray.m_realLen;
	m_maxLen = otherArray.m_maxLen;

	delete[] m_arr;

	m_arr = new T[m_maxLen];

	for (int i = 0; i < m_realLen; ++i)
		m_arr[i] = otherArray.m_arr[i];

	return this*;
}

template <class T>
TemplateArray<T>& TemplateArray<T>::operator += (T elem)
{
	insert(m_realLen, elem);

	return *this;
}

template <class T>
TemplateArray<T> TemplateArray<T>::operator + (T elem) const
{
	TemplateArray arr(m_arr);
	return arr += elem;;
}

template <class T>
TemplateArray<T>& TemplateArray<T>::operator += (const TemplateArray& otherArray)
{
	for (int i = 0; i < otherArray.m_realLen; ++i)
		m_arr += otherArray.m_arr[i];
}

template <class T>
TemplateArray<T> TemplateArray<T>::operator + (const TemplateArray& otherArray) const
{
	TemplateArray arr(m_arr);
	return arr += otherArray;
}

template <class T>
bool TemplateArray<T>::operator == (const TemplateArray& otherArray) const
{
	if (m_realLen != otherArray.m_realLen)
		return false;

	for (int i = 0; i < m_realLen; ++i)
		if (m_arr[i] != otherArray.m_arr[i])
			return false;

	return true;
}

template <class T>
bool TemplateArray<T>::operator != (const TemplateArray& otherArray) const
{
	if (*this == otherArray)
		return false;
	return true;
}