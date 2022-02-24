#pragma once
#include <iostream>
#include "node.hpp"

class DoublyLinkedList
{
private:
    int data;
    int size;
    Node *root;
    Node *last;

public:
    DoublyLinkedList();
    DoublyLinkedList& insertBegin(int);
    DoublyLinkedList& insertEnd(int);
    DoublyLinkedList& insert(int, int);
    DoublyLinkedList& remove(int);
    DoublyLinkedList& removeFirst();
    DoublyLinkedList& removeLast();
    
    int find(int) const;
    int getSize() const;
    int getLastElement() const;
    int getFirstElement() const;

    int& operator[](int);
    friend std::ostream& operator<<(std::ostream&,const DoublyLinkedList&);
};