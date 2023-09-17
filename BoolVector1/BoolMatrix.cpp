#include "BoolMatrix.h"


BoolMatrix::BoolMatrix() :  m_columns{1}, m_rows{1}
{
	m_matrix = new BoolVector[m_rows];

	for (int i = 0; i < m_rows; ++i)
		m_matrix[i];
}

BoolMatrix::BoolMatrix(int rows, int colomns)
{
	m_columns = colomns;
	m_rows = rows;

	m_matrix = new BoolVector[m_rows];
}

BoolMatrix(const char** bitMatrix, int rows, int colomn);
BoolMatrix(const BoolMatrix& otherMatrix);