#include "CMTXReader.h"
#include "CMTXFilename.h"
#include <string>
#include <iostream>

CMTXReader::CMTXReader(const char* folder) {
	const char* filename;
	filename = CMTXFilename::A(folder, true);
	matrixReader.open(filename);
	packetSize = matrixReader.packetSize;

	filename = CMTXFilename::b(folder, true);
	bReader.open(filename);
	if (packetSize != bReader.packetSize)
		cout << "Wrong packet size (" << bReader.packetSize << ") in: " << filename << endl;
	
	filename = CMTXFilename::c(folder, true);
	cReader.open(filename);
	if (packetSize != cReader.packetSize)
		cout << "Wrong packet size (" << cReader.packetSize << ") in: " << filename << endl;
	
	filename = CMTXFilename::lo(folder, true);
	loReader.open(filename);
	if (packetSize != loReader.packetSize)
		cout << "Wrong packet size (" << loReader.packetSize << ") in: " << filename << endl;
	
	filename = CMTXFilename::hi(folder, true);
	hiReader.open(filename);
	if (packetSize != hiReader.packetSize)
		cout << "Wrong packet size (" << hiReader.packetSize << ") in: " << filename << endl;

	filename = CMTXFilename::tr(folder, true);
	trReader.open(filename);
	if (packetSize != trReader.packetSize)
		cout << "Wrong packet size (" << trReader.packetSize << ") in: " << filename << endl;

	filename = CMTXFilename::lpp(folder, true);
	lppReader.open(filename);
	if (packetSize != lppReader.packetSize)
		cout << "Wrong packet size (" << lppReader.packetSize << ") in: " << filename << endl;
}

CProblem CMTXReader::readProblem() {
	CProblem problem;
	problem.A = matrixReader.readMatrix();
	problem.b = bReader.readArray();
	problem.c = cReader.readArray();
	problem.lo = loReader.readArray();
	problem.hi = hiReader.readArray();
	problem.tr = trReader.readTrace();
	problem.lpp = lppReader.readMatrix();
	return problem;
}

CProblem CMTXReader::readProblemByID(unsigned id) {
	CProblem problem;
	problem.A = matrixReader.readMatrixByID(id);
	problem.b = bReader.readArrayByID(id);
	problem.c = cReader.readArrayByID(id);
	problem.lo = loReader.readArrayByID(id);
	problem.hi = hiReader.readArrayByID(id);
	problem.tr = trReader.readTraceByID(id);
	problem.lpp = lppReader.readMatrixByID(id);
	return problem;
}