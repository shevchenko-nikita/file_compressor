#pragma once

#include "bitstream_writer.h"

#include <unordered_map>

namespace Encoder
{
    std::unordered_map<unsigned char, int>
    CalcByteFrequency(const std::vector<bool>& bits);

    void
    WriteHuffmanTable(
            BitStreamWriter& out,
            const std::unordered_map<unsigned char, std::string>& encoded);

    void
    WriteEncodedData(
            BitStreamWriter& out,
            const std::vector<bool>& bits,
            const std::unordered_map<unsigned char, std::string>& encoded);

    void EncodeFile(const std::string& filePath);
}