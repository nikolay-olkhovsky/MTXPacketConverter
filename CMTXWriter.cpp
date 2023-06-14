#include "CMTXWriter.h"
#include "CMTXFilename.h"
#include <iostream>
#include <filesystem>
using namespace std;

CMTXWriter::CMTXWriter(const char* folder){
	this->folder = folder;
	this->id = 0;
}

void CMTXWriter::clearFolder() {
	filesystem::path path;
	path.assign(folder);
	if (filesystem::exists(path))
		filesystem::remove_all(path);
	filesystem::create_directory(path);
}

void CMTXWriter::saveProblem(CProblem problem) {
	filesystem::path path(folder);
	filesystem::path file;
	path.append(CMTXFilename::folderName(id++));
	filesystem::create_directory(path);
	
	file.assign(CMTXFilename::A());
	fout.open(path/file);
	fout << problem.A->toSparseString() << endl;
	fout.close();

	file.assign(CMTXFilename::b());
	fout.open(path / file);
	fout << problem.b->to_string() << endl;
	fout.close();

	file.assign(CMTXFilename::c());
	fout.open(path / file);
	fout << problem.c->to_string() << endl;
	fout.close();

	file.assign(CMTXFilename::lo());
	fout.open(path / file);
	fout << problem.lo->to_string() << endl;
	fout.close();

	file.assign(CMTXFilename::hi());
	fout.open(path / file);
	fout << problem.hi->to_string() << endl;
	fout.close();

	file.assign(CMTXFilename::tr());
	fout.open(path / file);
	fout << problem.tr->toCommonString() << endl;
	fout.close();

	file.assign(CMTXFilename::lpp());
	fout.open(path / file);
	fout << problem.lpp->toLppString();
	fout << problem.c->to_line(problem.lpp->getCols() - 1) << endl;
	fout.close();
}