#include <string>
#pragma once
using namespace std;

class CMatrix
{
	unsigned rows = 0;
	unsigned cols = 0;
	unsigned notNulls = 0;
	double** data;
public:
	CMatrix(unsigned rows, unsigned cols, unsigned notNulls);
	void setValue(unsigned, unsigned, double);
	unsigned getRows() { return rows; }
	unsigned getCols() { return cols; }
	double getValue(unsigned, unsigned);
	string toSparseString();
	string toCommonString();
	string toLppString();
	~CMatrix();
};

