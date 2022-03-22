#include <string>
#include "HuffNode.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"

HuffNode* createHuffmanTree(PriorityQueue &queue_of_symbols) {
    while (queue_of_symbols.size != 1) {
        HuffNode *node1 = getTopFromQueue(queue_of_symbols);
        popFromQueue(queue_of_symbols);
        HuffNode *node2 = getTopFromQueue(queue_of_symbols);
        popFromQueue(queue_of_symbols);
        pushToQueue(queue_of_symbols, mergeHuffNodes(node1, node2));
    }
    HuffNode *result = getTopFromQueue(queue_of_symbols);
    popFromQueue(queue_of_symbols);
    return result;
}
