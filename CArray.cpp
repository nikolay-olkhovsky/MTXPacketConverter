#include "CArray.h"
#include <sstream>
#include <iomanip>

CArray::CArray(unsigned size) {
	this->size = size;
	if(size)
		this->data = new double[size]();
	else 
		this->data = new double[1]();
}

CArray::~CArray() {
	delete[] data;
}

void CArray::setValue(unsigned i, double value) {
	this->data[i] = value;
}

double CArray::getValue(unsigned i) const {
	return this->data[i];
}

string CArray::to_string() {
	stringstream str;
	str << size << '\t' << 1 << endl;
	for (unsigned i = 0; i < size; i++) {
		str << data[i] << endl;
	}
	return str.str();
}

string CArray::to_line(unsigned elems) {
	stringstream str;
	str << fixed << showpoint;
	for (unsigned i = 0; i < elems; i++) {
		str << setprecision(14) << -data[i] << '\t';
	}
	return str.str();
}
