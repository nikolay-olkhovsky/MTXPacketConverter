#pragma once
#include "CMTXPacketReader.h"
#include "CArray.h"

class CMTXArrayReader : public CMTXPacketReader
{
public:
    CArray* readArray();
    CArray* readArrayByID(unsigned id);
    void skip();
};

