#include "CMatrix.h"
#include <sstream>
#include <iomanip>

CMatrix::CMatrix(unsigned rows, unsigned cols, unsigned notNulls) {
	this->rows = rows;
	this->cols = cols;
	this->notNulls = notNulls;
	this->data = new double* [rows];
	for (unsigned i = 0; i < rows; i++)
		data[i] = new double[cols]();
}

void CMatrix::setValue(unsigned i, unsigned j, double value) {
	this->data[i][j] = value;
}

double CMatrix::getValue(unsigned i, unsigned j) {
	return this->data[i][j];
}

string CMatrix::toSparseString() {
	stringstream ss;
	ss << rows << '\t' << cols << '\t' << notNulls << endl;
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			if (data[i][j] != 0)
				ss << i + 1 << '\t' << j + 1 << '\t' << setprecision(14) << data[i][j] << endl;
	return ss.str();
}

string CMatrix::toCommonString() {
	stringstream ss;
	ss << rows << '\t' << cols << endl;
	ss << fixed << showpoint;
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++)
			ss << setprecision(14) << data[i][j] << '\t';
		ss << endl;
	}
	return ss.str();
}

string CMatrix::toLppString() {
	stringstream ss;
	ss << rows << '\t' << cols-1 << endl;
	ss << fixed << showpoint;
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++)
			ss << setprecision(14) << data[i][j] << '\t';
		ss << endl;
	}
	return ss.str();
}

CMatrix::~CMatrix() {
	for (unsigned i = 0; i < rows; i++)
		delete[] data[i];
	delete[] data;
}