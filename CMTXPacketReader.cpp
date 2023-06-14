#include "CMTXPacketReader.h"
#include <iostream>

void CMTXPacketReader::open(const char* filename) {
	fin.open(filename);
	if (!fin.is_open())
		cout << "File open error: " << filename << endl;
	fin >> packetSize;
}

CMTXPacketReader::~CMTXPacketReader() {
	fin.close();
}