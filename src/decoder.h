#pragma once

#include "bitstream_reader.h"
#include "bitstream_writer.h"

#include <unordered_map>

namespace Decoder
{
    uint8_t ReadByte(const std::vector<bool>& bits, size_t& curBitPos);
    uint32_t ReadFourBytes(const std::vector<bool>& bits, size_t& curBitPos);

    std::vector<bool> ConvertToVector(std::string code);

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