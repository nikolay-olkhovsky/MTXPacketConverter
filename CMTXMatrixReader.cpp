#include "CMTXMatrixReader.h"

CMatrix* CMTXMatrixReader::readMatrix() {
	CMatrix* matrix;
	unsigned rows, cols, values, i, j;
	double value;

	fin >> rows >> cols >> values;
	matrix = new CMatrix(rows, cols, values);
	for (unsigned line = 0; line < values; line++)
	{
		fin >> i >> j >> value;
		matrix->setValue(i-1, j-1, value);
	}
	return matrix;
}

void CMTXMatrixReader::skip() {
	unsigned rows, cols, values;
	char _buf[1024];
	
	fin >> rows >> cols >> values;
	fin.getline(_buf, 1024);
	for (unsigned i = 0; i < values; i++)
		fin.getline(_buf, 1024);
}

CMatrix* CMTXMatrixReader::readMatrixByID(unsigned id) {
	CMatrix* matrix;
	unsigned rows, cols, values, i, j;
	double value;

	for (unsigned i = 0; i < id; i++)
		skip();

	fin >> rows >> cols >> values;
	matrix = new CMatrix(rows, cols, values);
	for (unsigned line = 0; line < values; line++)
	{
		fin >> i >> j >> value;
		matrix->setValue(i - 1, j - 1, value);
	}
	return matrix;
}