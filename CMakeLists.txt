cmake_minimum_required(VERSION 3.20)
project(Huffman)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Huffman
        src/main.cpp
        src/HuffNode.cpp
        src/HuffNode.h
        src/PriorityQueue.cpp
        src/PriorityQueue.h
        src/HuffmanTree.cpp
        src/HuffmanTree.h
        src/Tables.cpp
        src/Tables.h
        src/CompressFiles.cpp
        src/CompressFiles.h
)
