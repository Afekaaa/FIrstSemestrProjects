#pragma once

#include "BoolVector.h"
#include <iostream>

class BoolMatrix
{
public:
	BoolMatrix();
	BoolMatrix(int rows, int colomns);
	BoolMatrix(const char** bitMatrix, int rows, int columns);
	BoolMatrix(const BoolMatrix & other);
	~BoolMatrix();

	friend std::ostream operator << (std::ostream& matrixOut, BoolMatrix& matrix);
	friend std::istream operator >> (std::istream& matrixIn, BoolMatrix& matrix);

	int weight() const;
	BoolVector conjunction() const;

	BoolMatrix& operator = (const BoolMatrix& other);
	BoolVector& operator [] (int index);
	BoolMatrix& operator & (BoolMatrix& other) const;
	BoolMatrix& operator | (BoolMatrix& other) const;


private:
	BoolVector* m_matrix = nullptr;

	int m_columns = 0;
	int m_rows = 0;

	void rowsAndColumnAdmissable(int rows, int columns);
};

