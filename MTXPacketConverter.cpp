#include <iostream>
#include "inicpp.h"
#include "CMTXReader.h"
#include "CMTXPacketWriter.h"
#include "CMTXFilename.h"
#include "CVector.h"
using namespace std;

int main()
{
    ini::IniFile config;
    const char* PP_PATH;
    unsigned numberOfProblems;
    unsigned dimensions;
    CProblem problem;
    CMTXPacketWriter* writer;
    CArray* point;
    CVector a, b, c;

    config.load("config.ini");
    PP_PATH = config["general"]["PP_PATH"].as<const char*>();
    dimensions = config["general"]["PP_N"].as<unsigned>();
    numberOfProblems = config["generator"]["PP_NUMBER_OF_PROBLEMS"].as<unsigned>();

    cout << PP_PATH << endl << dimensions << endl << numberOfProblems << endl;
    
    writer = new CMTXPacketWriter(PP_PATH, numberOfProblems);
    point = new CArray(dimensions);

    problem.loadModelProblem(dimensions);
    for (unsigned i = 0; i < dimensions; i++)
        point->setValue(i, 100.);

    writer->clearFolder();
    writer->open();
    for (unsigned i = 0; i < numberOfProblems; i++) {
        problem.randomize(point);
        writer->addProblem(problem);
    }
    writer->close();
    /*
    const char* path = "C:/TEMP/";
    CMTXReader reader(path);
    CMTXWriter writer("C:/TEMP/converted/");
    CProblem problem;

    unsigned packetSize = reader.packetSize;
    for (unsigned currentProblemNumber = 0; currentProblemNumber < packetSize; currentProblemNumber++) {
        problem = reader.readProblem();
        writer.saveProblem(problem);
        problem.clear();
    }
    */
    //problem = reader.readProblemByID(0);
    //writer.saveProblem(problem);
    config.clear();
}
