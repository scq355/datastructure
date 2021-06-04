cmake_minimum_required(VERSION 3.19)
project(datastructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(datastructure main.cpp headers/tree/BiTree.h headers/list/CLinkList.h headers/common/Constants.h headers/list/DuLinkList.h headers/tree/HuffmanTree.h headers/list/LinkList.h headers/queue/LinkQueue.h headers/stack/LinkStack.h headers/list/SqList.h headers/queue/SqQueue.h headers/stack/SqStack.h headers/string/SString.h sources/list/CLinkList.cpp sources/list/DuLinkList.cpp sources/list/LinkList.cpp sources/list/SqList.cpp sources/queue/LinkQueue.cpp sources/queue/SqQueue.cpp sources/stack/LinkStack.cpp sources/stack/SqStack.cpp sources/string/SString.cpp sources/tree/BiTree.cpp sources/tree/HuffmanTree.cpp)