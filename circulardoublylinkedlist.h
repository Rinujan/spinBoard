#pragma once
#include <iostream>
template <class spinBoard>
class circulardoublylinkedlist{
public:
    class Node{
    public:
        Node(spinBoard v, Node *nx=nullptr,Node * px=nullptr) : value(v), next(nx),prev(px){}
        spinBoard value;
        Node * next;
        Node * prev;
    };
    //all method for cdll
    circulardoublylinkedlist();
    ~circulardoublylinkedlist();
    spinBoard replace(unsigned int n, spinBoard item);
    void shiftlefts();
    void shiftrights();
    unsigned int size() const;
    bool isEmpty() const;
    void addTail(spinBoard item);
    void addHead(spinBoard item);
    spinBoard removeHead();
    spinBoard removeTail();
    spinBoard retrieveHead() const;
    spinBoard retrieveTail() const;
    spinBoard remove(unsigned int n);
    spinBoard retrieve(unsigned int n) const;
    void add(unsigned int n, spinBoard item);
    inline Node* getHead() const { return _head; }
    //these are some extra node pointers i created to help me writing the this code. It is only accessory nodes do not play a key role.
    Node *left;
    Node *right;
    Node *exhptr;
private:
    //node members. very important
    Node *_head;
    Node *_tail;
    Node *newnode;
    unsigned int _size;
public:
    //iterator class for easy traversing. this is used for the << operator for printing the actual board
    class Iterator {
    private:
        Node* m_ptr;
    public:
        Iterator(Node* ptr) { m_ptr = ptr; }
        void operator++ () { m_ptr = m_ptr->next; }
        bool operator != (const Iterator& b) { return m_ptr != b.m_ptr; }
        spinBoard operator *() { return m_ptr->value; }
        spinBoard getValue() { return m_ptr->value; }
        void setValue(spinBoard val) { m_ptr->value = val; }
    };
    
    Iterator begin()const { return Iterator(_head); }
    Iterator end() { return Iterator(nullptr); }
};
//default constructor
template <class spinBoard>
circulardoublylinkedlist<spinBoard>::circulardoublylinkedlist()
:_head(nullptr)
,_tail(nullptr)
,_size(0)
{}
//deconstructor
template <class spinBoard>
circulardoublylinkedlist<spinBoard>::~circulardoublylinkedlist(){
    if (_head == nullptr)
        return;
    
    Node *a = _head;
   Node *b = _head->next;
    
    while(b != a)
    {
        b = b->next;
        
        delete b->prev;
    }
    
    delete a;
}
//return size
template <class spinBoard>
unsigned int circulardoublylinkedlist<spinBoard>::size() const{
    return _size;
}
//check if list is empty
template <class spinBoard>
bool circulardoublylinkedlist<spinBoard>::isEmpty() const{
    return (_size==0);
}
//add a head node to the cdll
template <class spinBoard>
void circulardoublylinkedlist<spinBoard>::addHead(spinBoard item){
    newnode=new Node(item);
    _size ++;
    if( _head==nullptr){
        _head=newnode;
        _tail=newnode;
        newnode->next=newnode;
        newnode->prev=newnode;
        exhptr=_head;
    }
    else {
        newnode->prev=_tail;
        newnode->next=_head;
        _tail->next=newnode;
        _head->prev=newnode;
        _head=newnode;
        exhptr=_head;
    }

}
//add a tail node to the cdll
template <class spinBoard>
void circulardoublylinkedlist<spinBoard>::addTail(spinBoard item){
    newnode= new Node(item);
    if( _size==0){
        _head=newnode;
        _tail=newnode;
        newnode->next=newnode;
        newnode->prev=newnode;
        exhptr=_head;

    }
    else {
        newnode->prev=_tail;
        newnode->next=_head;
        _tail->next=newnode;
        _head->prev=newnode;
        _tail=newnode;
        exhptr=_head;

    }
    _size++;
}
//remove at a certain postion of the cdll
template < class spinBoard>
spinBoard circulardoublylinkedlist<spinBoard>::remove(unsigned int n){
    if (n == 1) return removeHead();
    if (n == size()) return removeTail();
    
    Node * here = _head;
    for (unsigned int k = 0; k < n - 1; k++)
        here = here->next;
    Node * kill = here;
    spinBoard returnVal5 = kill->value;
    here=here->next;
    here->prev=kill->prev;
    here->prev->next=here;
    delete kill;

    _size--;
    return returnVal5;
}
//remove head of cdll
template < class spinBoard>
spinBoard circulardoublylinkedlist<spinBoard>::removeHead(){
    Node * oldNode = _head;
    spinBoard returnVal = _head->value;
    _head = _head->next;
    if (_head == nullptr) {
        _tail = nullptr;
    }
    else{
        _head->prev=_tail;
        _tail->next=_head;
    }
    _size--;
    exhptr=_head;
    delete oldNode;
    return returnVal;
}
//remove tail of cdll
template < class spinBoard>
spinBoard circulardoublylinkedlist<spinBoard>::removeTail(){
    Node * oldNode = _tail;
    spinBoard returnVal = _tail->value;
    if (_head == _tail) {
        return removeHead();
        _head->next=nullptr;
        _head->prev=nullptr;
    }
    else{
    _tail=_tail->prev;
    _tail->next = _head;
        _head->prev=_tail;
    }
    exhptr=_head;
    delete oldNode;
    _size--;
    return returnVal;
    

}
//retrieve head of cdll(used to print board with retrieve function)
template < class spinBoard>
spinBoard circulardoublylinkedlist<spinBoard>::retrieveHead() const{
    return _head->value;

}
//retrieve tail of cdll(used to print board with retrieve function)
template < class spinBoard>
spinBoard circulardoublylinkedlist<spinBoard>::retrieveTail() const{
    return _tail->value;
}
//retrieve node at a position used for printing board
template < class spinBoard>
spinBoard circulardoublylinkedlist<spinBoard>::retrieve(unsigned int n) const{
    if (n == 1) return retrieveHead();
    if (n == size()) return retrieveTail();
    Node * here = _head;
    for (unsigned int k = 1; k < n; k++)here = here->next;
    return here->value;
}
//shift the spinBoard function right. used in spinBoard.cpp
template <class spinBoard>
void circulardoublylinkedlist<spinBoard>::shiftlefts(){
    _head=_head->prev;//shift right
    //adjust spinner to keep within indices
    left = left->prev;
    right = right->prev;
  
}
template <class spinBoard>
void circulardoublylinkedlist<spinBoard>::shiftrights(){
    _head=_head->next;//shift left
    //adjust spinner to keep within indices
    left = left->next;
    right = right->next;
    
}
//replace position at n with an item. this is an important function for the spin method
template <class spinBoard>
spinBoard circulardoublylinkedlist<spinBoard>::replace(unsigned int n, spinBoard item)
{
    spinBoard returnValue;
    Node * here = _head;
    for (unsigned int k = 1; k < n; k++)
        here = here->next;
    returnValue = here->value;
    here->value = item;
    return returnValue;
    exhptr=_head;

    
}
//last but not least is the add method. this is to add at position n with an item.
template <class spinBoard>
void circulardoublylinkedlist<spinBoard> ::add(unsigned int n, spinBoard item)
{
    if (n == 1)
        addHead(item);
else if (n == (size() + 1))
    addTail(item);
else
{
    Node * here = _head;
    Node * after= _head;
    for (unsigned int k = 1; k < n - 1; k++)
        here = here->next;
    here->next = new Node(item, here->next, here->prev);
    after=here->next;
    after=here->next;
    after->prev=here->next;
    here->next=after->prev;
    _size++;
    exhptr=_head;
    
    _size++;
}
    }




