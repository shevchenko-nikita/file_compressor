#pragma once

#include "bitstream_reader.h"
#include "bitstream_writer.h"

#include <unordered_map>

namespace Decoder
{
    template<typename T>
    T ReadByte(const std::vector<bool>& bits, size_t& curBitPos, int numBits);
    uint32_t ReadFourBytes(const std::vector<bool>& bits, size_t& curBitPos);

    std::unordered_map<std::string, unsigned char>
    GetHuffmanTable(const std::vector<bool>& bits, size_t& curBitPos);

    std::string GetExtension(const std::vector<bool>& bits, size_t& curBitPos);

    void
    WriteDecodedData(
            const std::vector<bool>& bits,
            size_t& curBitPos,
            std::unordered_map<std::string, unsigned char>& table,
            BitStreamWriter& out);

    void DecodeFile(const std::string& filePath);
}