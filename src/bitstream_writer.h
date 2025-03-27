#pragma once

#include <string>
#include <vector>
#include <fstream>

class BitStreamWriter
{
public:
    BitStreamWriter(std::string outFileName);

    ~BitStreamWriter();

    void Write(const std::vector<bool>& bits);
    void Write(const std::string& val);
    void Write(uint8_t val);

    void Flush();

private:
    void WriteBit(bool bit);

    int bitCount;
    uint8_t buffer;

    std::ofstream outFile;
};