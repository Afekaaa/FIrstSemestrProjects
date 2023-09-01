#include "Array.h"


Array::Array()
{
	m_maxLen = m_additionInLength;
	m_realLen = 0;
	m_mas = new int[m_maxLen];
}

Array::Array(const int len)
{
	m_maxLen = len + m_additionInLength;
	m_realLen = len;
	m_mas = new int[m_maxLen];
}

Array::Array(const int* mas, const int len)
{
	m_realLen = len;
	m_maxLen = m_realLen + m_additionInLength;
	m_mas = new int[m_maxLen];

	for (int i = 0; i < m_realLen; ++i)
		m_mas[i] = mas[i];
}

Array::Array(const Array& otherMas)
{
	m_realLen = otherMas.m_realLen;
	m_maxLen = m_realLen + m_additionInLength;
	m_mas = new int[m_maxLen];

	for (int i = 0; i < m_realLen; ++i)
		m_mas[i] = otherMas.m_mas[i];
}

Array::~Array()
{
	delete [] m_mas;
}

void Array::sort()
{
	hoarSort(m_mas, 0, m_realLen - 1);
}

void Array::insert(const int index, const int num)
{
	if (!indexAdmissible(index))
		throw std::out_of_range("Index out of range");

	if (m_realLen < m_maxLen)
	{
		rightShiftAndInsert(index, num);
	} 
	else
	{
		m_maxLen = m_realLen + m_additionInLength;

		int* tmpArr = new int[m_maxLen];

		for (int i = 0; i < m_realLen; ++i)
			tmpArr[i] = m_mas[i];

		delete [] m_mas;
		m_mas = tmpArr;

		rightShiftAndInsert(index, num);
	}
}

void Array::erase(const int index)
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

		int* tmpArr = new int[m_maxLen];

		for (int i = 0; i < m_realLen; ++i)
			tmpArr[i] = m_mas[i];

		delete [] m_mas;
		m_mas = tmpArr;
	}
}

void Array::leftShiftAndErase(const int index)
{
	for (int i = index; i < m_realLen - 1; ++i)
		m_mas[i] = m_mas[i + 1];
	m_realLen--;
}

int Array::find(const int num) const
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
	if (!notEmpty())
		throw std::logic_error("Отправлен запрос на получение минимального элемента из пустого массива.");

	int minElem = m_mas[0];

	for (int i = 1; i < m_realLen; ++i)
		if (m_mas[i] < minElem)
			minElem = m_mas[i];

	return minElem;
}

int Array::getMaxElem() const
{
	if (!notEmpty())
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

void Array::rightShiftAndInsert(const int index, const int num)
{
	for (int i = m_realLen; i > index; --i)
		m_mas[i] = m_mas[i - 1];

	m_mas[index] = num;
	m_realLen++;
}

bool Array::remove(const int num)
{
	for (int i = 0; i < m_realLen; ++i)
	{
		if (m_mas[i] == num)
		{
			erase(i);
			return true;
		}
	}

	return false;
}

void Array::rightShift(int index, int step)
{
	if (step == 0)
		return;

	if (!indexAdmissible(index) or index == m_realLen)
		throw std::out_of_range("index is out of range of array");

	if (index + step >= m_realLen)
		for (int i = index; i < m_realLen; ++i)
			m_mas[i] = 0;
	else
	{
		for (int i = m_realLen - 1; i - step >= index; --i)
			m_mas[i] = m_mas[i - step];

		for (int i = index; i < index + step; ++i)
			m_mas[i] = 0;
	}
}

void Array::leftShift(int index, int step)
{
	if (step == 0)
		return;

	if (!indexAdmissible(index) or index == m_realLen)
		throw std::out_of_range("index is out of range of array");

	step = std::abs(step);

	if (index + step >= m_realLen)
		for (int i = index; i < m_realLen; ++i)
			m_mas[i] = 0;
	else
	{
		for (int i = index; i + step < m_realLen; ++i)
			m_mas[i] = m_mas[i + step];
		for (int i = m_realLen - step; i < m_realLen; ++i)
			m_mas[i] = 0;
	}
}

void Array::randomArray()
{
	srand(time(0));

	for (int i = 0; i < m_realLen; ++i)
		m_mas[i] = -100 + rand() % 201;
}

void Array::randomArrayToUp()
{
	srand(time(0));

	m_mas[0] = -100 + rand() % 201;

	for (int i = 1; i < m_realLen; ++i)
		m_mas[i] = m_mas[i - 1] + rand() % 20;
}

void Array::randomArrayToDown()
{
	srand(time(0));

	m_mas[0] = -100 + rand() % 201;

	for (int i = 1; i < m_realLen; ++i)
		m_mas[i] = m_mas[i - 1] + rand() % 20;
}

std::ostream& operator << (std::ostream& masOut, Array arr)
{
	for (int i = 0; i < arr.m_realLen; ++i)
		masOut << arr.m_mas[i] << " ";

	return masOut;
}

std::istream& operator >> (std::istream& masIn, Array &arr)
{
	std::cout << "Enter the number of elements: ";
	masIn >> arr.m_realLen;
	arr.m_maxLen = arr.m_realLen + arr.m_additionInLength;

	if (arr.notEmpty())
		delete[] arr.m_mas;

	arr.m_mas = new int[arr.m_maxLen];

	if (arr.m_realLen != 0)
		std::cout << std::endl << "Enter the number: ";

	for (int i = 0; i < arr.m_realLen; ++i)
		masIn >> arr.m_mas[i];

	std::cout << std::endl;

	return masIn;
}

int& Array::operator [] (const int index)
{
	if (indexAdmissible(index) and index != m_realLen)
		return m_mas[index];
}

Array& Array::operator -= (const int index)
{
	erase(index);
	return *this;
}

Array Array::operator - (const int num) const
{
	Array arr(*this);
	arr.remove(num);

	return arr;
}

Array& Array::operator	= (const Array& otherMas)
{
	if (*this == otherMas)
		return *this;
	
	m_realLen = otherMas.m_realLen;
	m_maxLen = otherMas.m_maxLen;

	delete[] m_mas;
	m_mas = new int[m_realLen];

	for (int i = 0; i < m_realLen; i++)
		m_mas[i] = otherMas.m_mas[i];

}

Array Array::operator + (const int num) const
{
	Array arr(*this);
	arr += num;

	return arr;
}

Array& Array::operator += (const int num)
{
	insert(m_realLen, num);

	return *this;
}

bool Array::operator == (const Array& otherMas) const
{
	if (m_realLen != otherMas.m_realLen)
		return false;

	for (int i = 0; i < m_realLen; ++i)
		if (m_mas[i] != otherMas.m_mas[i])
			return false;

	return true;
}

bool Array::operator != (const Array& otherMas) const
{
	if (*this == otherMas)
		return false;
	return true;
}

Array Array::operator + (const Array& otherMas) const
{
	Array arr(*this);
	arr += otherMas;

	return arr;
}

Array& Array::operator += (const Array& otherMas)
{
	for (int i = 0; i < otherMas.m_realLen; ++i)
		insert(m_realLen, otherMas.m_mas[i]);

	return *this;
}

bool Array::indexAdmissible(const int index) const
{
	if (index >= 0 and index <= m_realLen)
		return true;
	return false;
}

bool Array::notEmpty() const
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
	Array arr2 = *arr;

	std::cout << arr->getLen() << std::endl;
	std::cout << *arr << std::endl;
	std::cout << arr->getMaxElem() << std::endl;
	std::cout << arr->getMinElem() << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		arr->insert(i + 10, i + 10);
		std::cout << *arr << std::endl;
	}

	for (int i = 0; i < len + 6; i++)
	{
		arr->erase(0);
		std::cout << *arr << std::endl;
	}

	*arr += 2;

	std::cout << *arr + 4 + 5<< std::endl;
	std::cout << *arr + arr2 << std::endl;
	std::cout << arr2 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 << std::endl;

	/*Array arr3;

	std::cin >> arr3;
	std::cout << arr3 << std::endl;
	arr3.sort();
	std::cout << arr3 << std::endl;*/

	arr2[4] = 100;

	std::cout << arr2 << std::endl;
	arr2.remove(5);
	std::cout << arr2 << std::endl;
	arr2.remove(30);
	std::cout << arr2 << std::endl;

	Array arr4(mas, len);

	std::cout << std::endl << arr4 << std::endl;

	arr4.rightShift(3, 2);
	std::cout << arr4 << std::endl;
	arr4.leftShift(6, 2);
	std::cout << arr4 << std::endl;

	arr4.leftShift(0, 1);
	std::cout << arr4 << std::endl;
	arr4.rightShift(0, 1);
	std::cout << arr4 << std::endl;

	arr4.leftShift(arr4.getLen() - 1, 1);
	std::cout << arr4 << std::endl;
	arr4.rightShift(arr4.getLen() - 1, 1);
	std::cout << arr4 << std::endl;

	arr4.rightShift(3, 100);
	std::cout << arr4 << std::endl;
	arr4.leftShift(6, 100);
	std::cout << arr4 << std::endl;
}