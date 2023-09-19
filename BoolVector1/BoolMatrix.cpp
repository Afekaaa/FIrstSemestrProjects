#include "BoolMatrix.h"


BoolMatrix::BoolMatrix() :  
	m_columns{1}, m_rows{1}
{
	m_matrix = new BoolVector[m_rows];

	for (int i = 0; i < m_rows; ++i)
		m_matrix[i] = BoolVector(m_columns, 0);
}

BoolMatrix::BoolMatrix(int rows, int colomns)
{
	m_columns = colomns;
	m_rows = rows;

	m_matrix = new BoolVector[m_rows];

	for (int i = 0; i < m_rows; ++i)
		m_matrix[i] = BoolVector(m_columns, 0);
}

BoolMatrix::BoolMatrix(const char** bitMatrix, int rows, int columns)
{
	m_rows = rows;
	m_columns = columns;

	m_matrix = new BoolVector[m_rows];

	for (int i = 0; i < m_rows; ++i)
		m_matrix[i] = BoolVector(bitMatrix[i], columns);
}

BoolMatrix::BoolMatrix(const BoolMatrix & other)
{
	m_rows = other.m_rows;
	m_columns = other.m_columns;

	m_matrix = new BoolVector[m_rows];

	for (int i = 0; i < m_rows; ++i)
		m_matrix[i] = BoolVector(other.m_matrix[i]);
}

BoolMatrix::~BoolMatrix()
{
	delete[] m_matrix;
}

int BoolMatrix::weight() const
{
	int counter = 0;

	for (int i = 0; i < m_rows; ++i)
		counter += m_matrix[i].weight();

	return counter;
}

BoolVector BoolMatrix::conjunction() const
{
	BoolVector vector = m_matrix[0];

	for (int i = 1; i < m_rows; ++i)
		vector &= m_matrix[i];

	return vector;
}

BoolMatrix& BoolMatrix::operator = (const BoolMatrix& other)
{
	if (this == &other)
		return *this;


	for (int i = 0; i < m_rows; ++i)
		delete[] m_matrix;

	delete m_matrix;

	m_columns = other.m_columns;
	m_rows = other.m_rows;

	m_matrix = new BoolVector[m_rows];

	for (int i = 0; i < m_rows; ++i)
		m_matrix[i] = BoolVector(m_columns, 0);

	return *this;
}

BoolVector& BoolMatrix::operator [] (int index)
{
	if (index >= 0 and index < m_rows)
		return m_matrix[index];
}

BoolMatrix BoolMatrix::operator & (BoolMatrix& other) const
{
	BoolMatrix matrix = BoolMatrix(*this);

	for (int i = 0; i < std::min(m_rows, other.m_rows); ++i)
		m_matrix[i] &= other.m_matrix[i];

	return matrix;
}

BoolMatrix BoolMatrix::operator | (BoolMatrix& other) const
{
	BoolMatrix matrix = BoolMatrix(*this);

	for (int i = 0; i < std::min(m_rows, other.m_rows); ++i)
		m_matrix[i] |= other.m_matrix[i];

	return matrix;
}

void BoolMatrix::rowsAndColumnAdmissable(int rows, int columns)
{
	if (rows <= 0 or columns <= 0)
		throw std::invalid_argument("the number of rows and columns should not be less than one");
}