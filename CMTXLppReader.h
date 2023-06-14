#pragma once
#include "CMTXPacketReader.h"
#include "CMatrix.h"

class CMTXLppReader : public CMTXPacketReader
{
public:
    CMatrix* readMatrix();
    CMatrix* readMatrixByID(unsigned id);
    void skip();
};

