#include "CRandom.h"

CRandom::CRandom() {
	distribution.param(normal_distribution<double>::param_type(0.));
}

double CRandom::getRandomValue() {
	double randomValue = distribution(generator);
	if (randomValue < 0.) randomValue = -randomValue;
	
	return randomValue;
}

CVector CRandom::getRandomVector(unsigned dimensions) {
	CVector randomVector(dimensions);
	double randomValue;
//	double summ = 0.0;
	for (unsigned i = 0; i < dimensions; i++) {
		randomValue = this->getRandomValue();
		randomVector.setValue(i, randomValue);
//		summ += randomValue * randomValue;
	}
//	summ = sqrt(summ);
//	for (unsigned i = 0; i < dimensions; i++) {
//		randomVector.setValue(i, randomVector.getValue(i) / summ);
//		randomVector->setValue(i, 1. - randomVector->getValue(i) / summ);
//	}
	return randomVector.norm();
}