#pragma once

#include <string>
#include <unordered_map>

struct HuffmanNode
{
    HuffmanNode(unsigned char data_, int freq_)
    : data(data_), freq(freq_), left(nullptr), right(nullptr)
    {
    }

    unsigned char data;
    int freq;

    HuffmanNode* left;
    HuffmanNode* right;
};

struct Compare
{
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs)
    {
        return lhs->freq > rhs->freq;
    }
};

class HuffmanTree
{
public:
    HuffmanTree() = default;

    ~HuffmanTree();

    void BuildTree(const std::unordered_map<unsigned char, int>& frequency);

    HuffmanNode* GetTreeRoot() const;
    std::unordered_map<unsigned char, std::string> GetEncodingMap();

private:
    void DeleteTree(HuffmanNode* node);
    void GenerateCodes(HuffmanNode* node, std::string code);

    HuffmanNode* root;
    std::unordered_map<unsigned char, std::string> encodingMap;
};