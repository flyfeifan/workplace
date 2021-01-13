#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "ListNodes.h"


#define LNODEPTR  Node<int>*

using namespace std;


int main()
{
    srandom(time(NULL));
    LNODEPTR head = NULL;
    //无序链表
    /*
    for (int d = 100; d < 150; d++ )
    {
        //std::cout << "add: " << d << std::endl;
        addNode<int>(&head, d);
    }
    */

    for (int i = 100; i < 150; i++ )
    {
        //std::cout << "add: " << d << std::endl;
        int d = random() % 1000;
        addPostiveNode<int>(&head, d);
    }






    if (NULL == head )
    {
        std::cout <<" NULL HEAD " << endl;
        return 0;
    }
    LNODEPTR curN = head;
    do
    {
        std::cout << "out: " << curN->GetData() << endl;
        curN = curN->Next();
    }while(curN != NULL);

    std::cout <<" reverSalNode " << endl;
    reverSalNode<int>(&head);
    curN = head;
    do
    {
        std::cout << "out: " << curN->GetData() << endl;
        curN = curN->Next();
    }while(curN != NULL);

  
    return 0;
}