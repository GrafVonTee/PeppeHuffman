#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bitset>
#include <string>
#include "HuffNode.h"
#include "Tables.h"
#include "CompressFiles.h"

using namespace std;

string getInputFromFile(std::string path) {
    std::ifstream inf(path);
    std::stringstream buffer;
    if (!inf) {
        std::cerr << "File " << path << " not found!" << std::endl;
        inf.close();
        exit(1);
    }
    buffer << inf.rdbuf();
    return buffer.str();
}

void compressFile(string path, string &input) {
    using namespace std;
    ofstream output(path, ios::binary);
    if (!output) {
        std::cerr << "Access to file " << path << " denied!" << std::endl;
        output.close();
        exit(1);
    }
    string total;
    std::vector<unsigned char> bin;
    char elem;
    for (int i = 0; i < input.length(); ++i) {
        elem = input[i];
        total += getTableElem(elem);
        if (total.length() >= 8) {
            bin.push_back(bitset<8>(total.substr(0, 8)).to_ulong());
            total = total.substr(8, total.length() - 8);
        }
    }
    extern string cur_dir;
    ofstream append_output(cur_dir + "compress_values.txt", ios::app);
    while (total.length() < 8) {
        total += "0";
        append_output << "0";
    }
    append_output << endl;
    append_output.close();

    bin.push_back(bitset<8>(total.substr(0, total.length())).to_ulong());
    for (auto b : bin)
        output.write((char *) & b, sizeof(char));
}

string readCompressFile(string path) {
    using namespace std;
    ifstream inf(path, ios::binary);
    if (!inf) {
        std::cerr << "File " << path << " not found!" << std::endl;
        inf.close();
        exit(1);
    }
    string temp;
    vector<char> buffer(istreambuf_iterator<char>(inf), {});
    for (auto b: buffer) {
        temp += bitset<8>(b).to_string();
    }
    return temp;
}

void uncompressFile(string path, string &data) {
    using namespace std;
    ofstream ouf(path);
    if (!ouf) {
        std::cerr << "Access to file " << path << " denied!" << std::endl;
        ouf.close();
        exit(1);
    }
    string substr;
    extern int deleted_nulls;
    for (int i = 0; i < data.length(); ++i)
        for (int j = i+1; j < data.length(); ++j) {
            if (i == data.length() - deleted_nulls) {
                ouf.close();
                return;
            }
            substr = data.substr(i, j-i);
            if (elemIsExistsInNewTable(substr)) {
                i = j;
                ouf << getNewTableElem(substr);
            }
        }
    ouf.close();
}