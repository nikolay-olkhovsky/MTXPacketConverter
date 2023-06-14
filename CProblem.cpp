#include "CProblem.h"
#include "CRandom.h"
#include "CVector.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
void CProblem::clear() {
	A->~CMatrix();
	b->~CArray();
	c->~CArray();
	lo->~CArray();
	hi->~CArray();
	tr->~CMatrix();
	lpp->~CMatrix();
}

void CProblem::loadModelProblem(unsigned dimensions) {
	//this->clear();
	CVector random_a(dimensions);
	CVector random_c(dimensions);
	CVector z(dimensions);
	CVector g(dimensions);
	CVector y(dimensions);
	unsigned nor = dimensions + 1, noc = dimensions * 2 + 1, non = dimensions * 3 + 1;
	unsigned var = 0;
	this->dimensions = dimensions;

	A = new CMatrix(nor, noc, non);
	while (var < dimensions) {
		A->setValue(var, var, 1.0);
		A->setValue(var, var + dimensions, 1.0);
		var++;
	}

	for (unsigned col = 0; col < dimensions; col++) {
		A->setValue(var, col, 1.0);
		if (col == 0) A->setValue(var, col, 0.000001);
		if (col == 1) A->setValue(var, col, 0.000001);
		if (col == 2) A->setValue(var, col, 0.999999);
	}
	A->setValue(var, var + dimensions, 1.0);

	b = new CArray(nor);
	for (var = 0; var < dimensions; var++)
		b->setValue(var, 200.);
	b->setValue(var, 100.);
	var++;
	while (var < noc) {
		b->setValue(var, 0.);
		var++;
	}

	c = new CArray(noc);
	for (var = 0; var < dimensions; var++)
		c->setValue(var, -1.);
		//c->setValue(var, -1. * 50 * (dimensions - var));
	while (var < noc) {
		c->setValue(var, 0.);
		var++;
	}

	lo = new CArray(noc);
	hi = new CArray(noc);
	for (var = 0; var < noc; var++) {
		lo->setValue(var, 0.);
		hi->setValue(var, 1.0e+308);
	}

	lpp = new CMatrix(noc, dimensions, noc * dimensions);
	tr = new CMatrix(2, dimensions, 2 * dimensions);
	for (unsigned col = 0; col < dimensions; col++) {
		lpp->setValue(col, col, 1.0);
		lpp->setValue(dimensions, col, 1.0);
		if (col == 0) lpp->setValue(dimensions, col, 0.000001);
		if (col == 1) lpp->setValue(dimensions, col, 0.000001);
		if (col == 2) lpp->setValue(dimensions, col, 0.999999);
		lpp->setValue(col + 1 + dimensions, col, -1.0);

		for (unsigned i = 0; i < this->dimensions; i++) {
			random_a.setValue(i, A->getValue(dimensions, i));
			random_c.setValue(i, -1. * c->getValue(i));
			z.setValue(i, 100.);
		}
		
		g = z + (random_c ^ 10);
		y = g - (random_a ^ ((random_a ^ (g - z)) / (random_a ^ random_a)));

		//cout << (g - z).to_line(dimensions) << endl;
		//cout << (random_c ^ (g - z)) << endl;
		//cout << (random_c ^ random_c) << endl;

		for (unsigned i = 0; i < this->dimensions; i++) {
			tr->setValue(0, i, z.getValue(i));
			tr->setValue(1, i, y.getValue(i));
		}
	}
}

void CProblem::randomize(CArray* point) {
	double D = 0.0;
	CVector random_a = generator.getRandomVector(this->dimensions);
	CVector random_c = generator.getRandomVector(this->dimensions);
	CVector z = *point;
	CVector g = z + (random_c ^ 10);
	CVector y;

	for (unsigned i = 0; i < this->dimensions; i++) {
		A->setValue(this->dimensions, i, random_a.getValue(i));
		lpp->setValue(this->dimensions, i, random_a.getValue(i));
		D += random_a.getValue(i) * point->getValue(i);
		c->setValue(i, random_c.getValue(i) * -1.);
	}
	b->setValue(dimensions, D);
	y = g - (random_a ^ ((random_a ^ (g - z)) / (random_a ^ random_a)));
	
	//cout << (g - z).to_line(dimensions) << endl;
	//cout << (random_c ^ (g - z)) << endl;
	//cout << (random_c ^ random_c) << endl;

	for (unsigned i = 0; i < this->dimensions; i++) {
		tr->setValue(0, i, z.getValue(i));
		tr->setValue(1, i, y.getValue(i));
	}
}

string CProblem::toLppString() {
	stringstream ss;
	unsigned rows = lpp->getRows(), cols = lpp->getCols();
	ss << rows << '\t' << cols << endl;
	ss << fixed << showpoint;
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++)
			ss << setprecision(14) << lpp->getValue(i, j) << '\t';
		ss << b->getValue(i) << endl;
	}

	ss << c->to_line(this->dimensions) << endl;
	return ss.str();
}