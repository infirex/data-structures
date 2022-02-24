#pragma once

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node();
    Node(int);
};