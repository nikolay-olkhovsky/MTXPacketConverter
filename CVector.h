#pragma once
#include "CArray.h"
class CVector : public CArray
{
public:
	CVector();
	CVector(unsigned length);
	CVector(const CVector& in);
	CVector(const CArray& in);
	CVector& operator=(const CVector& in);
	CVector& operator=(const CArray& in);
	CVector operator+(CVector in);
	CVector operator-(CVector in);
	double operator^(CVector in);
	CVector operator^(double in);
	CVector operator/(double in);
	double length();
	CVector norm();
};
