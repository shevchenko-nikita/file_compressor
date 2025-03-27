#pragma once

#include "bitstream_reader.h"
#include "bitstream_writer.h"

namespace Decoder
{
    std::string GetExtension(const std::vector<bool>& bits, size_t& curBitPos);
    void DecodeFile(const std::string& filePath);
}