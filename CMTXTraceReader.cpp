#include "CMTXTraceReader.h"

CMatrix* CMTXTraceReader::readTrace() {
	CMatrix* matrix;
	unsigned rows, cols;
	double value;

	fin >> rows >> cols;
	matrix = new CMatrix(rows, cols, rows * cols);
	for (unsigned row = 0; row < rows; row++)
		for (unsigned col = 0; col < cols; col++) {
			fin >> value;
			matrix->setValue(row, col, value);
		}
	return matrix;
}

void CMTXTraceReader::skip() {
	unsigned rows, cols;
	char _buf[1024];

	fin >> rows >> cols;
	fin.getline(_buf, 1024);
	for (unsigned i = 0; i < rows; i++)
		fin.getline(_buf, 1024);
}

CMatrix* CMTXTraceReader::readTraceByID(unsigned id) {
	CMatrix* matrix;
	unsigned rows, cols;
	double value;

	for (unsigned i = 0; i < id; i++)
		skip();

	fin >> rows >> cols;
	matrix = new CMatrix(rows, cols, rows*cols);
	for (unsigned row = 0; row < rows; row++)
		for (unsigned col = 0; col < cols; col++) {
			fin >> value;
			matrix->setValue(row, col, value);
		}
	return matrix;
}