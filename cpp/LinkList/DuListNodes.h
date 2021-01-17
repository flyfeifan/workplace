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

template <class DATA>
void reverDuNodes(DulNode<DATA> **headPtr, DulNode<DATA> **tailPtr)
{
    DulNode<DATA> *curr = *headPtr;
    if( NULL == curr || NULL == curr->m_next || curr == *tailPtr)
    {
        //空，或者只有一个节点则不反转。
        return;
    }

    //更改指针指向
    DulNode<DATA> *prev = curr;
    curr = curr->m_next;
    do{
        DulNode<DATA> *next =  curr->m_next;
        curr->m_next = prev;
        curr->m_prev = next;
        prev = curr;
        curr = next;
    }while(curr != NULL);

    //更改首尾
    DulNode<DATA> *head = *headPtr;
    DulNode<DATA> *tail = *tailPtr;
    head->m_next = NULL;
    tail->m_prev = NULL;
    *headPtr = tail;
    *tailPtr = head;
    return;
}
