#include "HuffNode.h"

bool operator< (const HuffNode &a, const HuffNode &b) {
    return a.frequency < b.frequency;
}

HuffNode mergeHuffNodes(HuffNode *node1, HuffNode *node2) {
    HuffNode root;
    root.frequency = node1->frequency + node2->frequency;
    if (node1 < node2) {
        root.left  = node1;
        root.right = node2;
    } else {
        root.left  = node2;
        root.right = node1;
    }
    return root;
}