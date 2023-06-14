#pragma once
#include "CMatrix.h"
#include "CArray.h"
#include "CRandom.h"
#include <random>

using namespace std;
class CProblem
{
public:
	unsigned dimensions;
	CMatrix* A;
	CArray* b;
	CArray* c;
	CArray* lo;
	CArray* hi;
	CMatrix* tr;
	CMatrix* lpp;
	CRandom generator;
	void clear();
	void loadModelProblem(unsigned);
	void randomize(CArray* point);
	string toLppString();
};

