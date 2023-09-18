#pragma once

#include "BoolVector.h"


class BoolMatrix
{
public:
	BoolMatrix();
	BoolMatrix(int rows, int colomns);
	BoolMatrix(const char** bitMatrix, int rows, int columns);
	BoolMatrix(const BoolMatrix& otherMatrix);

private:
	BoolVector* m_matrix = nullptr;

	int m_columns = 0;
	int m_rows = 0;

	void rowsAndColumnAdmissable(int rows, int columns);
};

