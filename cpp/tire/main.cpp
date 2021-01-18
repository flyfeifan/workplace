#include <sstream>
#include <string>
#include <iostream>
#include "trie.h"

using namespace std;
int main()
{
    YYTrieNode* header = new YYTrieNode(100);
    addNum(header, 1518345061);
    addNum(header, 1518345062);
    addNum(header, 1518345063);
    addNum(header, 1518345064);
    addNum(header, 1518345065);
    addNum(header, 1518345071);
    addNum(header, 1518345072);
    addNum(header, 1518345073);
    addNum(header, 1518345074);
    addNum(header, 1518345075);

    addNum(header, 1518345062);
    addNum(header, 15162);
    addNum(header, 9518345062);
    addNum(header, 951834);
    addNum(header, 95183452);
    addNum(header, 2518345062);
    addNum(header, 2518347062);
    addNum(header, 151623);
    //printALLNode(header);
    std::set<long long> allValues;
    //getDataValue(header, 0, allValues);
    findAll(header, 159, allValues);
    for(std::set<long long>::iterator sIt = allValues.begin(); sIt != allValues.end(); sIt ++)
    {
        std::cout << "the valuesis :" << *sIt << std::endl;
    }

    return 0;
}