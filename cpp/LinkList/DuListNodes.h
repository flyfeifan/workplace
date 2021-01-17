template <class DATA>
class DulNode
{
public:
    DulNode(DATA data)
    :m_data(data)
    ,m_prev(NULL)
    ,m_next(NULL)
    {
    }

    DulNode* Prev()
    {
        return m_prev;
    }

    DulNode* Next()
    {
        return m_next;
    }

    DATA GetData(){
        return m_data;
    }

    bool isTail(){
        return m_next == NULL;
    }
public:
    DATA      m_data;
    DulNode*  m_prev;
    DulNode*  m_next;
};

//product
template <class DATA>
void addDuNode(DulNode<DATA> **headPtr, DulNode<DATA> **tailPtr, DATA data)
{
    DulNode<DATA>* newNode = new DulNode<DATA>(data);
    //当前为空List
    if( NULL == *headPtr || NULL == *tailPtr )
    {
        *headPtr = newNode;
        *tailPtr = newNode;
        return;
    }
    //当前非空
    (*tailPtr)->m_next = newNode;
    newNode->m_prev = *tailPtr;
    *tailPtr = newNode;
    return;
}

//sort list
template <class DATA>
void addSortDuNode(DulNode<DATA> **headPtr, DulNode<DATA> **tailPtr, DATA data, bool positive = true)
{
    DulNode<DATA>* newNode = new DulNode<DATA>(data);
    //当前为空List
    if( NULL == *headPtr || NULL == *tailPtr )
    {
        *headPtr = newNode;
        *tailPtr = newNode;
        return;
    }
    DulNode<DATA> *curr = *headPtr;
    if (positive)
    {   
        //找到第一个比之大
        while(curr != NULL && curr->m_data < data)
        {
            curr = curr->m_next;
        }

    }
    else
    {
        //找到第一个比之小
        while(curr != NULL && curr->m_data > data)
        {
            curr = curr->m_next;
        }
    }
    //到最后也没找到,插入尾部
    if (NULL == curr)
    {
        (*tailPtr)->m_next = newNode;
        newNode->m_prev = *tailPtr;
        *tailPtr = newNode;
        return;
    }
    //插入最小、最大
    if( curr == *headPtr )
    {   
        (*headPtr)->m_prev = newNode;
        newNode->m_next = *headPtr;
        *headPtr = newNode;
        return;
    }
    //中间,在curr之前插入
    curr->m_prev->m_next = newNode;
    newNode->m_prev = curr->m_prev;
    curr->m_prev = newNode;
    newNode->m_next = curr;
    return;
}

