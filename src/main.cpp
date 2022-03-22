#include <string>
#include "HuffNode.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include "Tables.h"
#include "CompressFiles.h"

int main() {
    string input = getInputFromFile("../Lorem Compressus1.txt");
    PriorityQueue queue_of_symbols = getAllSymbols(input);
    printQueue(queue_of_symbols.head, "../priority_list.txt");

    HuffNode *tree = createHuffmanTree(queue_of_symbols);
    getTableInfix(tree, "");
    printTable("../compress_values.txt");

    compressFile("../Lorem Compressus.txt", input);
    string compress_file = readCompressFile("../Lorem Compressus.txt");

    getTableFromFile("../compress_values.txt");
    printNewTable("");

    uncompressFile("../Lorem Compressus1.txt", compress_file);

    return 0;
}
