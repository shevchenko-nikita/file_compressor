#include "bitstream_writer.h"

BitStreamWriter::BitStreamWriter(std::string FileName)
: outFile(FileName, std::ios::binary)
{
    if(!outFile.is_open())
    {
        throw std::runtime_error("Error: Can't open the file");
    }

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

void BitStreamWriter::Write(uint32_t val)
{
    for(int i = 31; i >= 0; --i)
    {
        WriteBit((val >> i) & 1);
    }
}

void BitStreamWriter::Write(uint16_t val)
{
    for(int i = 15; i >= 0; --i)
    {
        WriteBit((val >> i) & 1);
    }
}

void BitStreamWriter::Write(uint8_t val)
{
    for(int i = 7; i >= 0; --i)
    {
        WriteBit((val >> i) & 1);
    }
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
//        buffer <<= (8 - bitCount);
        outFile.put(static_cast<char>(buffer));
    }

    buffer = 0;
    bitCount = 0;
}