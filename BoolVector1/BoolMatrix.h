#pragma once

#include "BoolVector.h"


class BoolMatrix
{
public:
	BoolMatrix();
private:
	BoolVector* m_matrix = nullptr;

	int m_columns = 0;
	int m_rows = 0;
};

