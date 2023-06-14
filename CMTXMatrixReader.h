#pragma once
#include "CMTXPacketReader.h"
#include "CMatrix.h"

class CMTXMatrixReader : public CMTXPacketReader
{
public:
    CMatrix* readMatrix();
    CMatrix* readMatrixByID(unsigned id);
    void skip();
};

