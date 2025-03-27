#include "bitstream_reader.h"

BitStreamReader::BitStreamReader(std::string FileName)
: inFile(FileName, std::ios::binary)
{
    if(!inFile.is_open())
    {
        throw std::runtime_error("Error: File does not exist " + FileName);
    }

    bitCount = 0;
    buffer = 0;
}

std::vector<bool> BitStreamReader::Read()
{
    std::vector<bool> bits;

    bool bit;

    while(ReadBit(bit))
    {
        bits.push_back(bit);
    }

    return bits;
}

bool BitStreamReader::ReadBit(bool& bit)
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