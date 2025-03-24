#pragma once

#include <fstream>
#include <string>
#include <vector>

class BitStream
{
public:
    BitStream(std::string inFileName, std::string outFileName);

//    ~BitStream();

    void Write(std::vector<bool> bits);
    std::vector<bool> Read();

private:
    void WriteBit(bool bit);
    bool ReadBit(bool& bit);

    int bitCount;
    uint8_t buffer;

    std::ifstream inFile;
    std::ofstream outFile;
};