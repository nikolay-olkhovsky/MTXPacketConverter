#pragma once
#include "CVector.h"
#include <random>
using namespace std;
class CRandom
{
	default_random_engine generator;
	normal_distribution<double> distribution;
public:
	CRandom();
	double getRandomValue();
	CVector getRandomVector(unsigned dimensions);
};

