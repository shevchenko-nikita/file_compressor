#include "huffmanTree.h"

#include <queue>

HuffmanTree::~HuffmanTree()
{
    DeleteTree(root);
}

void HuffmanTree::BuildTree(const std::unordered_map<unsigned char, int> &frequency)
{
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pt;

    for(const auto& [key, value] : frequency)
    {
        pt.push(new HuffmanNode(key, value));
    }

    while(pt.size() > 1)
    {
        auto left = pt.top();
        pt.pop();

        auto right = pt.top();
        pt.pop();

        auto node = new HuffmanNode(0, left->freq + right.freq);

        node->left = left;
        node->right = right;

        pt.push(node);
    }

    root = pt.top();
    pt.pop();
}

void HuffmanTree::DeleteTree(HuffmanNode* node)
{
    if(root)
    {
        DeleteTree(root->left);
        DeleteTree(root->right);

        delete node;
    }
}

HuffmanNode* HuffmanTree::GetTreeRoot() const
{
    return root;
}

std::unordered_map<unsigned char, std::string> HuffmanTree::GetEncodingMap()
{
    if(encodingMap.empty())
    {
        GenerateCodes(root, "");
    }

    return encodingMap;
}

void HuffmanTree::GenerateCodes(HuffmanNode *node, std::string code)
{
    if(!node)
    {
        return;
    }

    if(!node->left && !node->right)
    {
        encodingMap[node->data] = node->freq;
        return;
    }

    GenerateCodes(node->left, code + "0");
    GenerateCodes(node->right, code + "1");
}