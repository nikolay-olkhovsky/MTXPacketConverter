#include <string>
#pragma once
using namespace std;

class CArray
{
protected:
	unsigned size;
	double* data;
public:
	CArray(unsigned);
	~CArray();
	unsigned getSize() const { return size; }
	void setValue(unsigned, double);
	double getValue(unsigned) const;
	string to_string();
	string to_line(unsigned elems);
};

