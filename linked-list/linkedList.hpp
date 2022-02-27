#pragma once
#include <iostream>
#include "node.hpp"

class LinkedList
{
private:
    int size;
    Node *root;
    Node *last;


public:
    LinkedList();

    LinkedList& insertBegin(int);
    LinkedList& insertEnd(int);
    LinkedList& insert(int,int);
    LinkedList& remove(int);
    LinkedList& removeFirst();
    LinkedList& removeLast();

    int find(int) const;
    int getSize() const;
    int getLastElement() const;
    int getFirstElement() const;


    int& operator[](int);
    friend std::ostream& operator<<(std::ostream&,const LinkedList&);
};
