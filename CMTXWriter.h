#include <fstream>
#include "CProblem.h"
#pragma once
using namespace std;

class CMTXWriter
{
protected:
	unsigned id;
	const char* folder;
	ofstream fout;
public:
	CMTXWriter(const char* folder);
	void saveProblem(CProblem problem);
	void clearFolder();
};

