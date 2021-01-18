#include <sstream>
#include <string>
#include <iostream>
#include <set>

using namespace std;
class YYTrieNode{
public:
    YYTrieNode(int data):m_isTail(false), m_data(data)
    {
        for(int i = 0; i< 10; i++)
        {
            m_childs[i] = NULL;
        }
    }
    ~YYTrieNode(){ }
public:
    int m_data;  //当前数据
    bool         m_isTail;
    YYTrieNode*  m_childs[10];
};


void addNum(YYTrieNode* header, long long value)
{
    stringstream ss;
    ss << value;
    string strV = ss.str();
    YYTrieNode *currNode = header;

    for(size_t pos = 0; pos < strV.length(); pos ++ )
    {
        int sValue = strV[pos] -48;
        if( (currNode->m_childs[sValue]) == NULL )
        {
            YYTrieNode* newNode = new YYTrieNode(sValue);
            currNode->m_childs[sValue] = newNode;
        }

        currNode = currNode->m_childs[sValue];
        if( pos +1 == strV.length() )
        {
            currNode->m_isTail = true;
        }
    }
}

void printALLNode(YYTrieNode* header)
{
    YYTrieNode *currNode = header;
    if (NULL != currNode )
    {
        std::cout << "data: " << currNode->m_data << endl;
        for( int i = 0; i<10; i++)
        {
            if( NULL != currNode->m_childs[i])
            {
                printALLNode(currNode->m_childs[i]);
            }
        }
        
    }
    return;
}


void getDataValue(YYTrieNode* header, long long currValue, set<long long> &outValue)
{
    YYTrieNode *currNode = header;
    if (NULL != currNode )
    {
        if( currNode->m_data != 100 )
        {
            //header 过滤掉
            currValue = currValue * 10 + currNode->m_data;
        }
        if( currNode->m_isTail )
        {
            outValue.insert(currValue);
            //std::cout << "add value: " << currValue << " outValue: " << outValue << endl;
        }
        if (outValue.size() >= 10)
        {
            return;
        }
       
        for( int i = 0; i<10; i++ )
        {
            if (outValue.size() >= 10)
            {
                break;
            }
            getDataValue(currNode->m_childs[i], currValue, outValue);
        }

    }
    return;
}



void findAll(YYTrieNode* header, long long hValue, set<long long> &outData)
{
    stringstream ss;
    ss << hValue;
    string strV = ss.str();
    YYTrieNode *currNode = header;
    long long outValue = 0;
    for (size_t pos = 0; pos < strV.length(); pos++)
    {
        uint32_t indexValue = (strV[pos] -48);
        
        if( currNode->m_childs[indexValue] != NULL )
        {
            outValue = outValue * 10 + indexValue;
            currNode = currNode->m_childs[indexValue];
        }else
        {
           break;
        }
        
    }
    
    std::cout << "last value: " << currNode->m_data << " outValue: " << outValue << endl;
    if( header == currNode)
    {
        return;
    }
    outValue = outValue /10;
    getDataValue(currNode, outValue, outData);
}


