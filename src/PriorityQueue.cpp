#include <iostream>
#include <fstream>
#include <string>
#include "HuffNode.h"
#include "PriorityQueue.h"

using namespace std;

void pushToQueue(PriorityQueue &queue, HuffNode value) {
    if (queue.size == 0) {
        auto *node = new QueueNode;
        node->value = new HuffNode;
        *(node->value) = value;
        queue.head = node;
        queue.size++;
        return;
    }

    QueueNode *temp_node = queue.head;
    while ((temp_node->next != nullptr)
           && (*(temp_node->next->value) < value))
        temp_node = temp_node->next;

    auto *node = new QueueNode;
    node->value = new HuffNode;
    *(node->value) = value;
    if (value < *(queue.head->value)) {
        node->next = queue.head;
        queue.head = node;
    } else {
        node->next = temp_node->next;
        temp_node->next = node;
    }
    queue.size++;
}

HuffNode *getTopFromQueue(PriorityQueue &queue) {
    return queue.head->value;
}

void popFromQueue(PriorityQueue &queue) {
    //QueueNode *node = queue.head;
    queue.head = queue.head->next;
    queue.size--;
    //free(node->value);
    //free(node);
}

PriorityQueue getAllSymbols(string &input) {
    HuffNode symbols[255];
    for (int i = 0; i < 255; ++i)
        symbols[i].sym = (char) i;
    for (auto s : input)
        symbols[s].frequency += 1;
    PriorityQueue current_symbols;
    for (auto &symbol : symbols)
        if (symbol.frequency != 0)
            pushToQueue(current_symbols, symbol);
    return current_symbols;
}

void printQueue(QueueNode *qq, string outf) {
    std::ofstream output(outf);
    while (qq != nullptr) {
        HuffNode *sym = qq->value;
        if (outf.empty())
            std::cout << sym->sym << " : " << sym->frequency << std::endl;
        else
            output << sym->sym << " : " << sym->frequency << "\\" << std::endl;
        qq = qq->next;
    }
    std::cout << std::endl;
}