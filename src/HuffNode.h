#pragma once

struct HuffNode {
    int frequency = 0;
    char sym = '\0';
    HuffNode *left = nullptr, *right = nullptr;
};

bool operator< (const HuffNode &a, const HuffNode &b);
HuffNode mergeHuffNodes(HuffNode *node1, HuffNode *node2);