#pragma once

#include <fstream>
#include <string>
#include <vector>

class BitStreamReader
{
public:
    BitStreamReader(std::string FileName);

    std::vector<bool> Read();

private:
    bool ReadBit(bool& bit);

    int bitCount;
    uint8_t buffer;

    std::ifstream inFile;
};