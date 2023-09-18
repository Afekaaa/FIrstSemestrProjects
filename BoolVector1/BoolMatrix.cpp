#include "BoolMatrix.h"


BoolMatrix::BoolMatrix() :  m_columns{1}, m_rows{1}
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

BoolMatrix::BoolMatrix(const BoolMatrix& otherMatrix)
{
	m_rows = otherMatrix.m_rows;
	m_columns = otherMatrix.m_columns;

	m_matrix = new BoolVector[m_rows];

	for (int i = 0; i < m_rows; ++i)
		m_matrix[i] = BoolVector(otherMatrix.m_matrix[i]);
}

void BoolMatrix::rowsAndColumnAdmissable(int rows, int columns)
{
	if (rows <= 0 or columns <= 0)
		throw std::invalid_argument("the number of rows and columns should not be less than one");
}