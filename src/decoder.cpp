#include "decoder.h"

namespace Decoder
{
    std::string GetExtension(const std::vector<bool>& bits, size_t& curBitPos)
    {
        std::string extension;
        uint8_t sz = 0;
        for(size_t i = 0; i < 8; ++i)
        {
            sz |= (bits[curBitPos] << (7 - i));
            curBitPos += 1;
        }

        for(uint8_t k = 0; k < sz; ++k)
        {
            unsigned char c = 0;
            for(int i = 0; i < 8; ++i)
            {
                c |= (bits[curBitPos] << (7 - i));
                curBitPos += 1;
            }

            extension += static_cast<char>(c);
        }

        return extension;
    }

    void DecodeFile(const std::string& filePath)
    {
        BitStreamReader in(filePath);
        const auto bits = in.Read();

        size_t curBitPos = 0;
        auto extension = GetExtension(bits, curBitPos);
    }
}