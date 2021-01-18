#include <stdlib.h>
#include <iostream>
#include <map>
#include <iomanip>
#include <queue>

using namespace std;

template <class DATA>
class BtNode
{
public:
    BtNode(DATA data)
    :m_data(data)
    ,m_left(NULL)
    ,m_right(NULL)
    {
    }

    BtNode* Left()
    {
        return m_left;
    }

    BtNode* Right()
    {
        return m_right;
    }

    BtNode Data(){
        return m_data;
    }
public:
    DATA      m_data;
    BtNode<DATA>*  m_left;
    BtNode<DATA>*  m_right;
};

template<class DATA>
void allNodesInArray(BtNode<DATA> *node, int row, int colum, map<int, int> &resValue)
{
    if( NULL == node )
    {
        return;
    }
    //resArr[row][colum] = node->m_data;

   // *((int*)resArr+50*row+colum) = node->m_data;
    resValue[row*10000+colum] = node->m_data;
    if( node->m_left != NULL)
    {
        int pos = (row+1) * 10000 + colum - 1;
        resValue[pos] = -1;
        allNodesInArray<DATA>(node->m_left, row + 2, colum -2, resValue);
    }
    
    if( node->m_right != NULL )
    {
        int pos = (row+1) * 10000 + colum  + 1;
        resValue[pos] = -2;
        allNodesInArray<DATA>(node->m_right, row + 2, colum + 2, resValue);
    }
    return;
}


template<class DATA>
void showTrees(BtNode<DATA> *root, int datalen = 50)
{
    map<int,int> resValue;
    allNodesInArray<DATA>(root, 0, datalen/2, resValue);
    cout << " map size: " << resValue.size() << endl;
    //打印
    for (int i = 0; i < 2 * datalen; i++)
    {
        for (int j = 0; j < 2 * datalen; j++)
        {
            int pos = i * 10000 + j;
            if(resValue.find(pos) == resValue.end() )
            {
                cout << setw(2) << internal  << ' ';
            }
            else{
                if( resValue[pos] == -1 )
                {
                    cout << setw(2) << internal  << '/';
                }
                else if ( resValue[pos] == -2 )
                {
                    cout << setw(2) << internal  << '\\';
                }
                else{
                    cout << setw(2) << internal  << resValue[pos];
                }
                
            }



            /*
            //string printOut = ""; 
            int printRes = 0;
            if(resValue.find(pos) != resValue.end() )
            {
                printRes = 1;
               // stringstream ss;
               // ss << resValue[pos];
               // printOut = ss.str();
            }
            if( i > 0 && j > 0 )
            {
                int topRight = (i-1) * 10000 + j + 1;
                int nextLeft = (i+1) * 10000 + j - 1;
                if(resValue.find(topRight) != resValue.end() && resValue.find(nextLeft) != resValue.end())
                {
                    printRes = 2;
                    //printOut = "/";
                }


                int topLeft = (i-1) * 10000 + j - 1;
                int nextRight = (i+1) * 10000 + j + 1;
                if(resValue.find(topLeft) != resValue.end() && resValue.find(nextRight) != resValue.end())
                {
                    printRes = 3;
                    //printOut = "\\";
                }

            }
            if( 0 == printRes )
            {
                cout << setw(2) << internal  << ' ';
            }else if ( 1== printRes)
            {
                cout << setw(2) << internal  << resValue[pos];
            }
            else  if ( 2 == printRes )
            {
                 cout << setw(2) << internal  << '/';
            }else if ( 3 == printRes )
            {
                cout << setw(2) << internal  << '\\';
            }
            */
            /*
            if(resValue.find(pos) == resValue.end() )
            {
                cout << " ";
            }
            else{
                cout << setw(6) << right << resValue[pos];
            }
            */
        }
        cout << endl;
    }
}



template<class DATA>
void genRandTree(BtNode<DATA> **root, DATA d)
{
    BtNode<DATA> *newNode = new BtNode<DATA>(d);
    if( NULL == *root )
    {
        //无根节点
        *root = newNode;
        cout << "add root: " << d << endl;
        return;
    }
    BtNode<DATA> *curNode = *root;
    

    for( ; ;){
        bool toLeft =  0 == random() % 2;
        if( toLeft ){
            if( curNode->m_left != NULL )
            {
                curNode = curNode->m_left;
            }
            else
            {
                cout << "add node: " << curNode->m_data << " left data: " << d << endl;
                curNode->m_left = newNode;
                break;
            }
        }
        else
        {
            if( curNode->m_right != NULL )
            {
                curNode = curNode->m_right;
            }
            else
            {
                cout << "add node: " << curNode->m_data << " right data: " << d << endl;
                curNode->m_right = newNode;
                break;
            }
        } 
    }
    return;
}


template<class DATA>
void getSortTree(BtNode<DATA> **root, DATA d)
{
    BtNode<DATA> *newNode = new BtNode<DATA>(d);
    if( NULL == *root )
    {
        //无根节点
        *root = newNode;
        cout << "add root: " << d << endl;
        return;
    }
    BtNode<DATA> *curNode = *root;
    do{
        if(curNode->m_data > d )
        {
            //放左边
            if( curNode->m_left == NULL)
            {
                curNode->m_left = newNode;
                cout << "add data: " << curNode->m_data << " left:" << d << endl;
                break;
            }
            else
            {
                curNode = curNode->m_left;
            }
        }
        else
        {
            //放右边
            if( curNode->m_right == NULL)
            {
                curNode->m_right = newNode;
                cout << "add data: " << curNode->m_data << " right:" << d << endl;
                break;

            }
            else
            {
                curNode = curNode->m_right;
            }
            
        }
    }while(true);
    return;
}




template<class  DATA>
void levelShow(BtNode<DATA> *root)
{
    if (NULL == root )
    {
        return;
    }
    queue<BtNode<DATA>* > q;
    queue<int> levelQ;
    int level = 0;
    q.push(root);
    levelQ.push(1);
    while( !q.empty() )
    {
        BtNode<DATA>* tmp = q.front();
        //cout << "data: " <<tmp->m_data   << endl;
        int newLevel = levelQ.front();
        if( newLevel != level )
        {
            cout << endl;
            cout << "level " << newLevel;
            level = newLevel;
        }
        cout << " " <<tmp->m_data << " ";  
        q.pop();
        levelQ.pop();

        if( tmp->m_left )
        {
            q.push(tmp->m_left);
            levelQ.push(newLevel+1);
        }

        if( tmp->m_right)
        {
            q.push(tmp->m_right);
            levelQ.push(newLevel+1);
        }
    }
    return;
}



