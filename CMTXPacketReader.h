#include <fstream>
#pragma once
using namespace std;

class CMTXPacketReader
{
public:
	unsigned packetSize;
	void open(const char*);

protected:
	ifstream fin;
	~CMTXPacketReader();
};

