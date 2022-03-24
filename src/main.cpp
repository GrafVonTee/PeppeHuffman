#include <iostream>
#include <string>
#include "HuffNode.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include "Tables.h"
#include "CompressFiles.h"

using std::string;

enum Operation {
    Compress,
    Decompress,
    Error
};

string getPath(string mode) {
    string path;
    std::cout << "Enter " << mode << " file\'s path: ";
    getline(std::cin, path);
    return path;
}

Operation getOperation() {
    string input;
    std::cout << "Choose operation (compress, decompress): ";
    std::cin >> input;
    std::cin.ignore();
    if (input == "compress")
        return Compress;
    else if (input == "decompress")
        return Decompress;
    std::cerr << "Incorrect operation!" << std::endl;
    return Error;
}

void doOperation(Operation oper, string &cur_dir) {
    string input;
    HuffNode *tree;
    string compress_file;
    PriorityQueue queue_of_symbols;
    switch (oper) {
        case Compress:
            input = getInputFromFile(cur_dir + getPath("to-compress"));
            queue_of_symbols = getAllSymbols(input);
            printQueue(queue_of_symbols.head, cur_dir + "priority_list.txt");

            tree = createHuffmanTree(queue_of_symbols);
            getTableInfix(tree, "");
            printTable(cur_dir + "compress_values.txt");

            compressFile(cur_dir + getPath("output"), input);
            std::cout << "Compress Successful!" << std::endl;
            break;
        case Decompress:
             compress_file = readCompressFile(cur_dir + getPath("to-decompress"));

            getTableFromFile(cur_dir + "compress_values.txt");
            printNewTable("");

            uncompressFile(cur_dir + getPath("output"), compress_file);
            std::cout << "Decompress Successful!" << std::endl;
            break;
        default:
            break;
    }
}

string cur_dir;

int main(int argc, char *argv[]) {
    cur_dir = argv[1];
    doOperation(getOperation(), cur_dir);
    return 0;
}
