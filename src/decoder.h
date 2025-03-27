#pragma once

#include "bitstream_reader.h"
#include "bitstream_writer.h"

#include <unordered_map>

namespace Decoder
{
    uint8_t ReadByte(const std::vector<bool>& bits, size_t& curBitPos);

    std::string GetExtension(const std::vector<bool>& bits, size_t& curBitPos);

    void DecodeFile(const std::string& filePath);
}