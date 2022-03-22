#pragma once

using namespace std;

string getInputFromFile(std::string path);
void compressFile(string path, string &input);
string readCompressFile(string path);
void uncompressFile(string path, string &data);