#include "encoder.h"

#include "huffmanTree.h"
#include "bitstream_reader.h"

namespace Encoder
{
    std::unordered_map<unsigned char, int>
    CalcByteFrequency(const std::vector<bool>& bits)
    {
        std::unordered_map<unsigned char, int> frequency;

        uint8_t buffer = 0;
        int bitCount = 0;

        for(const auto bit : bits)
        {
            buffer |= (bit << (7 - bitCount));
            ++bitCount;

            if(bitCount == 8)
            {
                ++frequency[buffer];

                bitCount = 0;
                buffer = 0;
            }
        }

        return frequency;
    }

    std::vector<bool>
    ConvertToVector(const std::string& str)
    {
        std::vector<bool> bits;
        bits.reserve(str.size());
        for(const char& c : str)
        {
            bits.push_back((c == '1'));
        }

        return bits;
    }

    void
    WriteHuffmanTable(
            BitStreamWriter& out,
            const std::unordered_map<unsigned char, std::string>& encoded)
    {
        out.Write(static_cast<uint8_t>(encoded.size()));

        for(const auto& [key, value] : encoded)
        {
            out.Write(static_cast<uint8_t>(key));
            out.Write(static_cast<uint8_t>(value.size()));
            out.Write(ConvertToVector(value));
        }
    }

    void
    WriteEncodedData(
            BitStreamWriter& out,
            const std::vector<bool>& bits,
            const std::unordered_map<unsigned char, std::string>& encoded)
    {
        int bitCount = 0;
        uint8_t buffer = 0;

        for(auto bit : bits)
        {
            buffer |= (bit << (7 - bitCount));
            ++bitCount;

            if(bitCount == 8)
            {
                auto code = encoded.find(static_cast<unsigned char>(buffer));
                out.Write(ConvertToVector(code->second));

                bitCount = 0;
                buffer = 0;
            }
        }
    }

    void EncodeFile(const std::string& fileName)
    {
        std::string ext = fileName.substr(fileName.find_last_of('.') + 1);

        BitStreamReader in(fileName);
        auto bits = in.Read();

        if(bits.empty())
        {
            return;
        }

        BitStreamWriter out("encoded.huff");
        out.Write(ext);

        auto frequency = CalcByteFrequency(bits);

        HuffmanTree tree;
        tree.BuildTree(frequency);
        auto encoded = tree.GetEncodingMap();

        WriteHuffmanTable(out, encoded);
        WriteEncodedData(out, bits, encoded);
    }
}