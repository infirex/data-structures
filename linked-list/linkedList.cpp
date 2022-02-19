#include "linkedList.hpp"

LinkedList::LinkedList() : root{nullptr}
{
}

Node *LinkedList::last()
{
    Node *iter{root};

    while (iter->next != nullptr)
        iter = iter->next;

    return iter;
}

LinkedList &LinkedList::insert(int val)
{
    Node *node{new Node{val}};

    if (root == nullptr) // no exist item in the list
    {
        root = node;
        return *this;
    }

    last()->next = node;
    return *this;
}

LinkedList &LinkedList::insert(int val, int index)
{
    Node *newNode{new Node{val}};

    if (index == 0)
    {
        Node *temp{root};
        root = newNode;
        root->next = temp;
        return *this;
    }

    Node *iter{root};
    Node *iter2{nullptr};

    for (int i = 0; i < index-1; i++)
        iter = iter->next;

    iter2 = iter->next;

    iter->next = newNode;
    iter->next->next = iter2;

    return *this;
}


LinkedList &LinkedList::remove(int val)
{
    if (root == nullptr)
        return *this;

    if (root->data == val)
    {
        Node *temp{root};
        root = root->next;
        delete temp;
        return *this;
    }

    Node *iter{root};

    while (iter->next != nullptr && iter->next->data != val)
        iter = iter->next;

    if (iter == last()) // not found
        return *this;

    Node *temp{iter->next};
    iter->next = iter->next->next;
    delete temp;

    return *this;
}


int &LinkedList::operator[](int index)
{
    Node *iter{root};

    for (int i = 0; i < index; i++)
        iter = iter->next;

    return iter->data;
}

void LinkedList::printList()
{
    Node *iter{root};

    while (iter != nullptr)
    {
        std::cout << iter->data << ' ';
        iter = iter->next;
    }
}

// LinkedList::LinkedList() : root{nullptr}
// {
// }

// LinkedList::LinkedList(int val)
// {
//     this->data = val;
//     this->next = nullptr;
// }

// void LinkedList::insert(int val)
// {
//     LinkedList *node{new LinkedList{val}};
//     if (root == nullptr)
//     {
//         root = node;
//         return;
//     }

//     LinkedList *temp{root};

//     while (temp->next != nullptr)
//         temp = temp->next;

//     temp->next = node;
// }

// void LinkedList::printList()
// {
//     LinkedList *temp{this->root};

//     while (temp != nullptr)
//     {
//         std::cout << temp->data << ' ';
//         temp = temp->next;
//     }
// }