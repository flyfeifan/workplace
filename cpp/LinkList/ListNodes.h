template <class DATA>
class Node
{
public:
    Node(DATA data, Node<DATA>* next)
    {
        m_data = data;
        m_next = next;
    }

    Node<DATA>* Next()
    {
        return m_next;
    }

    DATA GetData(){
        return m_data;
    }

    bool isTail(){
        return m_next == NULL;
    }

    Node<DATA>* FindTail()
    {
        Node<DATA>* currNode = this;
        while (currNode->m_next != NULL)
        {
            currNode = currNode->m_next;
        }
        return currNode;
    }


public:
    DATA  m_data;
    Node<DATA>* m_next;
};

template <class DATA>
void addNode(Node<DATA> **head, DATA data)
{
    Node<DATA>* newNode = new Node<DATA>(data, NULL);
    if( NULL == *head )
    {
        *head = newNode;
        return;
    }

    Node<DATA>* tail = (*head)->FindTail();
    tail->m_next = newNode;
    return;
}


template <class DATA>
void addPostiveNode(Node<DATA> **head, DATA data)
{
    Node<DATA>* newNode = new Node<DATA>(data, NULL);
    if( NULL == *head )
    {
        *head = newNode;
        return;
    }

    Node<DATA>* curr = *head;
    Node<DATA>* prev = NULL;
    while (curr->m_next != NULL && curr->m_data < data )
    {
        prev = curr;
        curr = curr->m_next;
    }

    if( curr->m_next == NULL )
    {
        //队尾插入
        curr->m_next = newNode;
    }
    else if ( prev == NULL) 
    {
        //队头插入
        newNode->m_next = (*head);
        *head = newNode;
    }
    else{
        //对中插入
        newNode->m_next = curr;
        prev->m_next = newNode;
    }
    return;
}

template <class DATA>
void reverSalNode(Node<DATA> **head)
{
    Node<DATA>* prev = *head;
    if( prev == NULL || prev->m_next == NULL)
    {
        //空或者只有1个
        return;
    }

    Node<DATA>* cur = prev->m_next;
    while(cur->m_next != NULL)
    {
        Node<DATA>* next = cur->m_next;
        cur->m_next = prev;
        prev = cur;
        cur = next;
    }
    cur->m_next = prev;
    (*head)->m_next = NULL;
    *head = cur;
    return;
}
/*
template <class DATA>
class DulNode
{
public:
    DulNode(DATA data, DulNode* prev, DulNode* next)
    {
        m_data = data;
        m_next = next;
    }

    DulNode* Prev()
    {
        return m_prev;
    }

    DulNode* Next()
    {
        return m_next;
    }

    bool isTail(){
        return m_next == NULL;
    }

public:
    DATA      m_data;
    DulNode*  m_prev;
    DulNode*  m_next;
};

*/



