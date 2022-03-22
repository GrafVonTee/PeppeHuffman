#pragma once

using namespace std;

void getTableInfix(HuffNode *tree, std::string code);
void getTableFromFile(string path);
void printTable(string path);
void printNewTable(string path);

string getTableElem(char elem);
char getNewTableElem(string elem);
bool elemIsExistsInNewTable(string elem);