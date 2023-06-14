#include "CMTXPacketWriter.h"
#include "CMTXWriter.h"
#include "CMTXFilename.h"
#include <iostream>
#include <filesystem>
using namespace std;

CMTXPacketWriter::CMTXPacketWriter(const char* folder, unsigned size) : CMTXWriter(folder) {
	this->packetSize = size;
}

void CMTXPacketWriter::open() {
	filesystem::path path(folder);
	filesystem::path file;

	file.assign(CMTXFilename::A("", true));
	outA.open(path / file);
	outA << packetSize << endl;
	
	file.assign(CMTXFilename::b("", true));
	outb.open(path / file);
	outb << packetSize << endl;

	file.assign(CMTXFilename::c("", true));
	outc.open(path / file);
	outc << packetSize << endl;

	file.assign(CMTXFilename::lo("", true));
	outlo.open(path / file);
	outlo << packetSize << endl;

	file.assign(CMTXFilename::hi("", true));
	outhi.open(path / file);
	outhi << packetSize << endl;

	file.assign(CMTXFilename::tr("", true));
	outtr.open(path / file);
	outtr << packetSize << endl;

	file.assign(CMTXFilename::lpp("", true));
	outlpp.open(path / file);
	outlpp << packetSize << endl;
}

void CMTXPacketWriter::addProblem(CProblem problem) {
	this->id++;
	outA << this->id << '\t' << problem.A->toSparseString();
	outb << this->id << '\t' << problem.b->to_string();
	outc << this->id << '\t' << problem.c->to_string();
	outhi << this->id << '\t' << problem.hi->to_string();
	outlo << this->id << '\t' << problem.lo->to_string();
	outtr << this->id << '\t' << problem.tr->toCommonString();
	outlpp << this->id << '\t' << problem.toLppString();
}

void CMTXPacketWriter::close() {
	outA.close();
	outb.close();
	outc.close();
	outlo.close();
	outhi.close();
	outtr.close();
	outlpp.close();
}