#include "CMTXFilename.h"
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

const char* CMTXFilename::tag = "lp_dataset";
const char* CMTXFilename::suffixA = "_A";
const char* CMTXFilename::suffixb = "_b";
const char* CMTXFilename::suffixc = "_c";
const char* CMTXFilename::suffixlo = "_lo";
const char* CMTXFilename::suffixhi = "_hi";
const char* CMTXFilename::suffixtr = "_tr";
const char* CMTXFilename::extension = ".mtx";
const char* CMTXFilename::pack = ".pack";
const char* CMTXFilename::lpp_filename = "lpp.txt";

const char* CMTXFilename::folderPrefix = "lpp_";

const char* CMTXFilename::A(const char* folder, bool withPack) {
	string filename = "";
	filename += folder;
	filename += tag;
	filename += suffixA;
	filename += extension;
	if(withPack) filename += pack;
	return _strdup(filename.c_str());
}

const char* CMTXFilename::b(const char* folder, bool withPack) {
	string filename = "";
	filename += folder;
	filename += tag;
	filename += suffixb;
	filename += extension;
	if (withPack) filename += pack;
	return _strdup(filename.c_str());
}

const char* CMTXFilename::c(const char* folder, bool withPack) {
	string filename = "";
	filename += folder;
	filename += tag;
	filename += suffixc;
	filename += extension;
	if (withPack) filename += pack;
	return _strdup(filename.c_str());
}

const char* CMTXFilename::lo(const char* folder, bool withPack) {
	string filename = "";
	filename += folder;
	filename += tag;
	filename += suffixlo;
	filename += extension;
	if (withPack) filename += pack;
	return _strdup(filename.c_str());
}

const char* CMTXFilename::hi(const char* folder, bool withPack) {
	string filename = "";
	filename += folder;
	filename += tag;
	filename += suffixhi;
	filename += extension;
	if (withPack) filename += pack;
	return _strdup(filename.c_str());
}

const char* CMTXFilename::tr(const char* folder, bool withPack) {
	string filename = "";
	filename += folder;
	filename += tag;
	filename += suffixtr;
	filename += extension;
	if (withPack) filename += pack;
	return _strdup(filename.c_str());
}

const char* CMTXFilename::lpp(const char* folder, bool withPack) {
	string filename = "";
	filename += folder;
	filename += lpp_filename;
	if (withPack) filename += pack;
	return _strdup(filename.c_str());
}

const char* CMTXFilename::folderName(unsigned number) {
	stringstream ss;
	ss << folderPrefix << setw(5) << setfill('0') << number << '/';
	return _strdup(ss.str().c_str());
}