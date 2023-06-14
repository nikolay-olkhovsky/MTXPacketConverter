#pragma once
#include "CMTXWriter.h"

class CMTXPacketWriter : public CMTXWriter
{
	unsigned packetSize;
	ofstream outA;
	ofstream outb;
	ofstream outc;
	ofstream outlo;
	ofstream outhi;
	ofstream outtr;
	ofstream outlpp;
public:
	CMTXPacketWriter(const char* folder, unsigned size);
	void open();
	void close();
	void addProblem(CProblem problem);
};

