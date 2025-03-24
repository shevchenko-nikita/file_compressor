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

    while(true)
    {
        bool bit;
        if(!ReadBit(bit))
        {
            break;
        }

        bits.push_back(bit);
    }

    return bits;
}

bool BitStream::ReadBit(bool& bit)
{
    if(bitCount == 0)
    {
        bitCount = 8;
        buffer = inFile.get();

        if(buffer == EOF)
        {
            return false;
        }
    }

    std::cout << buffer << std::endl;

    --bitCount;
    bit = (buffer >> bitCount) & 1;
    return true;
}