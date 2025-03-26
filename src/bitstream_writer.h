#pragma once

#include <string>
#include <vector>
#include <fstream>

class BitStreamWriter
{
public:
    BitStreamWriter(std::string outFileName);

    ~BitStreamWriter();

    void Write(std::vector<bool> bits);
    void Write(std::string val);
    void Write(uint16_t val);
    void Write(uint8_t val);

    void Flush();

private:
    void WriteBit(bool bit);

    int bitCount;
    uint8_t buffer;

    std::ofstream outFile;
};