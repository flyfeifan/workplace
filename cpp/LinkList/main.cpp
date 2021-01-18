#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "ListNodes.h"
#include "DuListNodes.h"


#define LNODEPTR  Node<int>*
#define DULNODEPTR  DulNode<int>*


using namespace std;

/*
int main()
{
    srandom(time(NULL));
    LNODEPTR head = NULL;
    //无序链表
    for (int d = 100; d < 150; d++ )
    {
        //std::cout << "add: " << d << std::endl;
        addNode<int>(&head, d);
    }

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
*/

int main(void)
{   
    srandom(time(NULL));
    DULNODEPTR head = NULL;
    DULNODEPTR tail = NULL;
    for (int i = 100; i < 150; i++)
    {
        //std::cout << "add: " << d << std::endl;
        int d = random() % 1000;
        //int d = i;
        std::cout << "add: " << d << std::endl;
        //addSortDuNode<int>(&head, &tail, d);
        addDuNode<int>(&head, &tail, d);
    }
    std::cout << "#######################" << std::endl;
    //asc
    DULNODEPTR cur = head;
    while(cur != NULL)
    {
        std::cout << "asc out: " << cur->GetData() << std::endl;
        cur = cur->Next();
    }

    reverDuNodes<int>(&head, &tail);
    std::cout << "after nothind: " << std::endl;

    //asc
    cur = head;
    while(cur != NULL)
    {
        std::cout << "asc out: " << cur->GetData() << std::endl;
        cur = cur->Next();
    }


    return 0;
}