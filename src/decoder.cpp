#include "decoder.h"

namespace Decoder
{
    uint8_t ReadByte(const std::vector<bool>& bits, size_t& curBitPos)
    {
        uint8_t buffer = 0;
        for(int i = 0; i < 8; ++i)
        {
            buffer |= (bits[curBitPos] << (7 - i));
            curBitPos += 1;
        }

        return buffer;
    }

    std::string GetExtension(const std::vector<bool>& bits, size_t& curBitPos)
    {
        std::string extension;
        uint8_t sz = ReadByte(bits, curBitPos);

        for(uint8_t k = 0; k < sz; ++k)
        {
            auto c = ReadByte(bits, curBitPos);
            extension += static_cast<char>(c);
        }

        return extension;
    }

    void DecodeFile(const std::string& filePath)
    {
        BitStreamReader in(filePath);
        const auto bits = in.Read();

        size_t curBitPos = 0;
        std::string outFileName = "decoded." + GetExtension(bits, curBitPos);
    }
}