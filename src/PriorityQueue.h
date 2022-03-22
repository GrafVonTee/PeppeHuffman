#pragma once

struct QueueNode {
    HuffNode *value = nullptr;
    QueueNode *next = nullptr;
};

struct PriorityQueue {
    QueueNode *head = nullptr;
    int size = 0;
};

using namespace std;

void pushToQueue(PriorityQueue &queue, HuffNode value);
HuffNode *getTopFromQueue(PriorityQueue &queue);
void popFromQueue(PriorityQueue &queue);
PriorityQueue getAllSymbols(string &input);
void printQueue(QueueNode *qq, string outf);
