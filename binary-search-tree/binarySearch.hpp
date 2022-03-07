#pragma once
#include "Node.hpp"
#include <iostream>

class BinarySearch
{
private:
    Node *root;

    void _insert(int value,Node *&tree);
    void _printTree(Node* tree) const;
    bool _search(Node *tree,int value) const;
    void _remove(Node *tree,int value);
    int _max(Node *tree) const;
    int _min(Node *tree) const;

public:
    BinarySearch();

    BinarySearch& insert(int value);
    BinarySearch& remove(int value);
    bool search(int value) const;
    void printTree() const;
    int max() const;
    int min() const;

    Node* getRoot() const;
};