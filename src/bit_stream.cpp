#include "bit_stream.h"

#include <iostream>

BitStream::BitStream(std::string inFileName, std::string outFileName)
: inFile(inFileName, std::ios::binary), outFile(outFileName, std::ios::binary)
{
    bitCount = 0;
}

std::vector<bool> BitStream::Read()
{
    std::vector<bool> bits;

    bool bit;

    while(ReadBit(bit))
    {
        bits.push_back(bit);
    }

    return bits;
}

bool BitStream::ReadBit(bool& bit)
{
    if(bitCount == 0)
    {
        inFile.read(reinterpret_cast<char*>(&buffer), 1);

        if(inFile.eof())
        {
            return false;
        }

        bitCount = 8;
    }

    --bitCount;
    bit = (buffer >> bitCount) & 1;

    return true;
}