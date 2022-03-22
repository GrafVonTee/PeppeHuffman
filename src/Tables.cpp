#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include "HuffNode.h"
#include "Tables.h"

using namespace std;

std::map<char, string> table;
std::map<string, char> new_table;

string getTableElem(char elem) {
    return table[elem];
}

char getNewTableElem(string elem) {
    return new_table[elem];
}

bool elemIsExistsInNewTable(string elem) {
    return new_table.find(elem) != new_table.end();
}

void getTableInfix(HuffNode *tree, std::string code) {
    if (tree->left == tree->right) {
        table[tree->sym] = code;
        return;
    }

    string left_code  = code + "0";
    string right_code = code + "1";
    if (tree->left)
        getTableInfix(tree->left, left_code);
    if (tree->right)
        getTableInfix(tree->right, right_code);
}

void printTable(string path) {
    std::ofstream output(path);
    for (auto &t: table) {
        if (path.empty())
            std::cout << t.first << " -- " << t.second << std::endl;
        else
            output << t.first << " -- " << t.second << "\\" << std::endl;
    }
    std::cout << std::endl;
}

void getTableFromFile(string path) {
    using namespace std;
    ifstream inf(path);
    stringstream sbuffer;
    if (!inf) {
        std::cerr << "File " << path << " not found!" << std::endl;
        inf.close();
        exit(1);
    }
    sbuffer << inf.rdbuf();
    char *normal_string = (char*) calloc(sbuffer.str().length(), sizeof(char));
    strcpy(normal_string, sbuffer.str().c_str());
    char *token = strtok(normal_string, "\\");
    while (token != nullptr) {
        char a;
        char *b = (char*) calloc(50, sizeof(char));
        sscanf(token, "%c -- %s", &a, b);
        new_table[(string) b] = a;
        token = strtok(nullptr, "\\\n");
    }
}

void printNewTable(string path) {
    std::ofstream output(path);
    for (auto &t : new_table)
        std::cout << t.first << " : " << t.second << std::endl;
    std::cout << std::endl;
}