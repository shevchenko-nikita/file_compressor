#include "bitstream_writer.h"

BitStreamWriter::BitStreamWriter(std::string FileName)
: outFile(FileName, std::ios::binary)
{
    bitCount = 0;
    buffer = 0;
}

BitStreamWriter::~BitStreamWriter()
{
    Flush();
}

void BitStreamWriter::Write(std::vector<bool> bits)
{
    for(auto bit : bits)
    {
        WriteBit(bit);
    }
}

void BitStreamWriter::WriteBit(bool bit)
{
    buffer |= (bit << (7 - bitCount));

    ++bitCount;

    if(bitCount == 8)
    {
        Flush();
    }
}

void BitStreamWriter::Flush()
{
    if(bitCount > 0)
    {
        outFile.put(static_cast<char>(buffer));
        outFile.flush();
        buffer = 0;
        bitCount = 0;
    }
}