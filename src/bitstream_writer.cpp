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

void BitStreamWriter::Write(const std::vector<bool>& bits)
{
    for(auto bit : bits)
    {
        WriteBit(bit);
    }
}

void BitStreamWriter::Write(uint16_t val)
{
    outFile.write(reinterpret_cast<char*>(&val), sizeof(val));
}

void BitStreamWriter::Write(uint8_t val)
{
    outFile.write(reinterpret_cast<char*>(&val), sizeof(val));
}

void BitStreamWriter::Write(const std::string& val)
{
    Write(static_cast<uint8_t>(val.size()));
    outFile.write(val.c_str(), val.size());
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