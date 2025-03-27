#include "decoder.h"

#include "bitstream_reader.h"
#include "bitstream_writer.h"

namespace Decoder
{
    std::string GetExtension(const std::vector<bool>& bits, size_t& curBitPos)
    {
        std::string extension;
        int sz = 0;
        for(size_t i = 0; i < 8; ++i)
        {
            sz |= (bits[curBitPos] << (7 - i));
            curBitPos += 1;
        }

        return "";
    }

    void DecodeFile(const std::string& filePath)
    {
        BitStreamReader in(filePath);
        const auto bits = in.Read();

        size_t curBitPos = 0;
        auto extension = GetExtension(bits, curBitPos);
    }
}