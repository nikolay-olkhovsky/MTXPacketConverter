#pragma once
#include "CMTXPacketReader.h"
#include "CMatrix.h"

class CMTXTraceReader : public CMTXPacketReader
{
public:
    CMatrix* readTrace();
    CMatrix* readTraceByID(unsigned id);
    void skip();
};

