#include "CMTXLppReader.h"

CMatrix* CMTXLppReader::readMatrix() {
	CMatrix* matrix;
	unsigned rows, cols;
	double value;
	char _buf[1024];

	fin >> rows >> cols;
	cols++;
	matrix = new CMatrix(rows, cols, rows * cols);
	for (unsigned row = 0; row < rows; row++)
		for (unsigned col = 0; col < cols; col++) {
			fin >> value;
			matrix->setValue(row, col, value);
		}
	fin.getline(_buf, 1024);
	fin.getline(_buf, 1024);
	return matrix;
}

void CMTXLppReader::skip() {
	unsigned rows, cols;
	char _buf[1024];

	fin >> rows >> cols;
	fin.getline(_buf, 1024);
	for (unsigned i = 0; i < rows+1; i++)
		fin.getline(_buf, 1024);
}

CMatrix* CMTXLppReader::readMatrixByID(unsigned id) {
	CMatrix* matrix;
	unsigned rows, cols;
	double value;
	char _buf[1024];

	for (unsigned i = 0; i < id; i++)
		skip();

	fin >> rows >> cols;
	cols++;
	matrix = new CMatrix(rows, cols, rows * cols);
	for (unsigned row = 0; row < rows; row++)
		for (unsigned col = 0; col < cols; col++) {
			fin >> value;
			matrix->setValue(row, col, value);
		}
	fin.getline(_buf, 1024);
	fin.getline(_buf, 1024);
	return matrix;
}