#include <cassert>
#include "decoder.h"

namespace Decoder
{
    template<typename T>
    T ReadByte(const std::vector<bool>& bits, size_t& curBitPos, int numBits)
    {
        T buffer = 0;
        for(int i = 0; i < numBits; ++i)
        {
            buffer |= (bits[curBitPos] << (numBits - 1 - i));
            curBitPos += 1;
        }

        return buffer;
    }

    std::unordered_map<std::string, unsigned char>
    GetHuffmanTable(const std::vector<bool>& bits, size_t& curBitPos)
    {
        std::unordered_map<std::string, unsigned char> table;

        auto tableSz = ReadByte<uint16_t>(bits, curBitPos, 16);

        for(int i = 0; i < tableSz; ++i)
        {
            auto c = ReadByte<uint8_t>(bits, curBitPos, 8);
            auto codeSz = ReadByte<uint8_t>(bits, curBitPos, 8);
            std::string code;

            for(int j = 0; j < codeSz; ++j)
            {
                code += (bits[curBitPos] == 1) ? '1' : '0';
                curBitPos += 1;
            }

            table[code] = c;
        }

        return table;
    }

    std::string GetExtension(const std::vector<bool>& bits, size_t& curBitPos)
    {
        std::string extension;
        auto sz = ReadByte<uint8_t>(bits, curBitPos, 8);

        for(uint8_t k = 0; k < sz; ++k)
        {
            auto c = ReadByte<uint8_t>(bits, curBitPos, 8);
            extension += static_cast<char>(c);
        }

        return extension;
    }

    void
    WriteDecodedData(
            const std::vector<bool>& bits,
            size_t& curBitPos,
            std::unordered_map<std::string, unsigned char>& table,
            BitStreamWriter& out)
    {
        std::string code;
        auto originFileSize = ReadByte<uint32_t>(bits, curBitPos, 32);
        uint32_t curWrittenSize = 0;

        while(curBitPos < bits.size() && curWrittenSize != originFileSize)
        {
            code += (bits[curBitPos] == 1) ? '1' : '0';
            if(table.count(code))
            {
                auto c = table[code];
                curWrittenSize += 8;
                out.Write(static_cast<uint8_t>(c));
                code = "";
            }
            curBitPos += 1;
        }

        if(curWrittenSize != originFileSize)
        {
            assert(false);
        }
    }

    void DecodeFile(const std::string& filePath)
    {
        BitStreamReader in(filePath);
        const auto bits = in.Read();

        size_t curBitPos = 0;
        std::string outFileName = "decoded." + GetExtension(bits, curBitPos);
        BitStreamWriter out("../results/" + outFileName);

        auto table = GetHuffmanTable(bits, curBitPos);
        WriteDecodedData(bits, curBitPos, table, out);
    }
}