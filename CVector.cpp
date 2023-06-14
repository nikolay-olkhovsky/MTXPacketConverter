#include "CVector.h"

CVector::CVector() : CArray(0) {

}

CVector::CVector(unsigned length) : CArray(length) {

}

CVector::CVector(const CArray& in) : CArray(in.getSize()) {
	for (unsigned i = 0; i < this->size; i++)
		this->data[i] = in.getValue(i);
}

CVector::CVector(const CVector& in) : CArray(in.getSize()) {
	for (unsigned i = 0; i < this->size; i++)
		this->data[i] = in.getValue(i);
}

CVector& CVector::operator=(const CArray& in) {
	this->size = in.getSize();
	this->data = new double[this->size]();
	for (unsigned i = 0; i < this->size; i++)
		this->data[i] = in.getValue(i);
	return *this;
}

CVector& CVector::operator=(const CVector& in) {
	this->size = in.getSize();
	this->data = new double[this->size]();
	for (unsigned i = 0; i < this->size; i++)
		this->data[i] = in.getValue(i);
	return *this;
}

CVector CVector::operator+(CVector in) {
	CVector out(this->size);
	for (unsigned i = 0; i < this->size; i++)
		out.setValue(i, this->data[i] + in.getValue(i));
	return out;
}

CVector CVector::operator-(CVector in) {
	CVector out(this->size);
	for (unsigned i = 0; i < this->size; i++)
		out.setValue(i, this->data[i] - in.getValue(i));
	return out;
}

double CVector::operator^(CVector in) {
	double result = 0.;
	for (unsigned i = 0; i < this->size; i++)
		result += this->data[i] * in.getValue(i);
	return result;
}

CVector CVector::operator^(double in) {
	CVector out(this->size);
	for (unsigned i = 0; i < this->size; i++)
		out.setValue(i, this->data[i] * in);
	return out;
}

CVector CVector::operator/(double in) {
	CVector out(this->size);
	for (unsigned i = 0; i < this->size; i++)
		out.setValue(i, this->data[i] / in);
	return out;
}

double CVector::length() {
	double summ = 0.;
	for (unsigned i = 0; i < this->size; i++)
		summ += this->data[i] * this->data[i];
	return sqrt(summ);
}

CVector CVector::norm() {
	CVector out(this->size);
	double len = this->length();
	for (unsigned i = 0; i < this->size; i++)
		out.setValue(i, this->data[i] / len);
	return out;
}