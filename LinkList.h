#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class LinkList
{
friend class Stack;

private:
    T           mData;
    LinkList<T> *mNext;

public:
    LinkList();
    LinkList(T data);
    ~LinkList();
   
    T          getData();
    LinkList<T> *getNext();

    void setData(T data);
   
    void display();
    void insert(T data);
    bool isExist(T data);
    void remove(T data);

    bool operator<(T rhs);
    friend bool operator<(T lhs, LinkList<T> rhs);

    bool operator>(T rhs);
    friend bool operator>(T lhs, LinkList<T> rhs);

    bool operator==(T rhs);
    friend bool operator==(T lhs, LinkList<T> rhs);

    bool operator!=(T rhs);
    friend bool operator!=(T lhs, LinkList<T> rhs);

    friend ostream& operator<<(ostream &outputStream, LinkList<T> obj);
};
#endif