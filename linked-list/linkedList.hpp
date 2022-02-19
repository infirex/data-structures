#pragma once
#include <iostream>
#include "node.hpp"

class LinkedList
{
private:
    int data;
    Node *root;

    Node *last();

public:
    LinkedList();

    LinkedList& insert(int);
    LinkedList& insert(int,int);
    LinkedList& remove(int);
    
    int& operator[](int);

    void printList();
};
