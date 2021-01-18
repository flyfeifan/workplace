#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "BinaryTree.h"

#define  BITREEPTR   BtNode<int>*

using namespace std;

void printSpace(int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << " ";
    }
    return;
}

void printTree(int num)
{
    int totalNum = 2 * num;
}




int main()
{
    srandom(time(NULL));

    BITREEPTR root = NULL;
    for (int i = 100; i < 110; i++ )
    {
        int d = i;
        //genRandTree<int>(&root, d);
        d = random() % 100;
        getSortTree<int>(&root, d);
        //getSortTree<int>(&root, d);
    }
    levelShow<int>(root);
    //showTrees<int>(root, 20);
    return 0;
}


