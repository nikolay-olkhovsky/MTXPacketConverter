#include "CMTXMatrixReader.h"
#include "CMTXArrayReader.h"
#include "CMTXTraceReader.h"
#include "CMTXLppReader.h"
#include "CProblem.h"
#pragma once
class CMTXReader
{
	CMTXMatrixReader matrixReader;
	CMTXArrayReader bReader;
	CMTXArrayReader cReader;
	CMTXArrayReader loReader;
	CMTXArrayReader hiReader;
	CMTXTraceReader trReader;
	CMTXLppReader lppReader;
public:
	unsigned packetSize = 0;
	CMTXReader(const char* folder);
	CProblem readProblem();
	CProblem readProblemByID(unsigned id);
};

