#include "CMTXArrayReader.h"

CArray* CMTXArrayReader::readArray() {
	CArray* array;
	unsigned rows, cols;
	double value;

	fin >> rows >> cols;
	array = new CArray(rows);
	for (unsigned line = 0; line < rows; line++) {
		fin >> value;
		array->setValue(line, value);
	}
	return array;
}

void CMTXArrayReader::skip() {
	unsigned rows, cols;
	char _buf[1024];

	fin >> rows >> cols;
	fin.getline(_buf, 1024);
	for (unsigned i = 0; i < rows; i++)
		fin.getline(_buf, 1024);
}

CArray* CMTXArrayReader::readArrayByID(unsigned id) {
	CArray* array;
	unsigned rows, cols;
	double value;

	for (unsigned i = 0; i < id; i++)
		skip();

	fin >> rows >> cols;
	array = new CArray(rows);
	for (unsigned line = 0; line < rows; line++) {
		fin >> value;
		array->setValue(line, value);
	}
	return array;
}