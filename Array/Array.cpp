#include "Array.h"


Array::Array()
{
	m_maxLen = m_additionInLenght;
	m_realLen = 0;
	m_mas = new int[m_realLen];
}

Array::Array(const int len)
{
	m_maxLen = len + m_additionInLenght;
	m_realLen = len;
	m_mas = new int[m_realLen];
}

//Array::Array(const int* mas)
//{
//	m_realLen = sizeof(mas) / sizeof(int);
//	m_maxLen = m_realLen + m_additionInLenght;
//
//	m_mas = new int[m_realLen];
//
//	for (int i = 0; i < m_realLen; ++i)
//		m_mas[i] = mas[i];
//
//}

Array::Array(const int* mas, const int len)
{
	m_realLen = len;
	m_maxLen = m_realLen + m_additionInLenght;
	m_mas = new int[m_realLen];

	for (int i = 0; i < m_realLen; ++i)
		m_mas[i] = mas[i];
}

Array::Array(const Array& otherMas)
{
	m_realLen = otherMas.m_realLen;
	m_maxLen = m_realLen + m_additionInLenght;
	m_mas = new int[m_maxLen];

	for (int i = 0; i < m_realLen; ++i)
		m_mas[i] = otherMas.m_mas[i];


}

Array::~Array()
{
	delete m_mas;
}

void Array::sort()
{
	hoarSort(m_mas, 0, m_realLen);
}

void Array::addElem(const int index, const int num)
{
	if (m_realLen < m_maxLen)
	{
		m_realLen++;
		setElem(index, num);
	}
	else
	{
		m_realLen++;
		m_maxLen = m_realLen + m_additionInLenght;

		int* tmpArr = new int[m_maxLen];
		delete m_mas;
		m_mas = tmpArr;

		setElem(index, num);
	}
}

void Array::deleteElem(const int index)
{
	if (!masAdmissible())
		throw std::logic_error("Попытка удалить элемент из пустого массива");

	if (!indexAdmissible(index))
		throw std::invalid_argument("Попытка удалить элемент за пределами массива");

	if (maxDifferenceBetweenRealLenAndMaxLen < m_maxLen - m_realLen)
	{
		delElem(index);
	}

	else
	{
		delElem(index);

		m_realLen--;
		m_maxLen = m_realLen + m_additionInLenght;

		int* tmpArr = new int[m_maxLen];
		delete m_mas;
		m_mas = tmpArr;
	}
}

void Array::delElem(const int index)
{
	for (int i = index; i < m_realLen - 1; ++i)
		m_mas[i] = m_mas[i + 1];
}

int Array::getIndexElem(const int num) const
{
	int index = -1;

	for (int i = 0; i < m_realLen; ++i)
	{
		if (m_mas[i] == num)
			return index = i;
	}

	return index;
}

int Array::getMinElem() const
{
	if (!masAdmissible())
		throw std::logic_error("Отправлен запрос на получение минимального элемента из пустого массива.");

	int minElem = m_mas[0];

	for (int i = 1; i < m_realLen; ++i)
		if (m_mas[i] < minElem)
			minElem = m_mas[i];

	return minElem;
}

int Array::getMaxElem() const
{
	if (!masAdmissible())
		throw std::logic_error("Отправлен запрос на получение максимального элемента из пустого массива.");

	int maxElem = m_mas[0];

	for (int i = 1; i < m_realLen; ++i)
		if (m_mas[i] > maxElem)
			maxElem = m_mas[i];

	return maxElem;
}

int Array::getLen() const
{
	return m_realLen;
}

void Array::setElem(const int index, const int num)
{
	for (int i = m_realLen; i > index; --i)
		m_mas[i] = m_mas[i - 1];

	m_mas[index] = num;
}

std::ostream& operator << (std::ostream& masOut, Array arr)
{
	for (int i = 0; i < arr.m_realLen; ++i)
		masOut << arr.m_mas[i] << " ";

	return masOut;
}

std::istream& operator >> (std::istream& masIn, Array arr)
{
	for (int i = 0; i < arr.m_realLen; ++i)
		masIn >> arr.m_mas[i];
	return masIn;
}

int& Array::operator [] (int index)
{
	if (indexAdmissible(index) and masAdmissible())
		return m_mas[index];
}

Array& Array::operator -= (const int index)
{
	deleteElem(index);
	return *this;
}

bool Array::indexAdmissible(const int index) const
{
	if (index >= 0 and index < m_realLen)
		return true;
	return false;
}

bool Array::masAdmissible() const
{
	if (m_realLen)
		return true;
	return false;
}

int main()
{
	const int len = 10;
	int* mas = new int[len];
	for (int i = 0; i < len; ++i)
		mas[i] = i;

	Array* arr = new Array(mas, len);

		std::cout << arr->getLen() << std::endl;
		std::cout << *arr;
		std::cout << arr->getMaxElem();
		std::cout << arr->getMinElem() << std::endl;

		for (int i = 0; i < 6; ++i)
		{
			arr->addElem(i, i + 10);
		}

	std::cout << *arr;
}