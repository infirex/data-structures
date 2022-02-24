#include "linkedList.hpp"

LinkedList::LinkedList() : root{nullptr}, last{nullptr}, size{0}
{
}

int LinkedList::getLastElement() const
{
    return last->data;
}

int LinkedList::getFirstElement() const
{
    return root->data;
}

int LinkedList::getSize() const
{
    return size;
}

LinkedList &LinkedList::insertBegin(int val)
{
    Node *newNode{new Node{val}};

    Node *temp{root};
    root = newNode;
    root->next = temp;

    size++;
    return *this;
}

LinkedList &LinkedList::insertEnd(int val)
{
    Node *node{new Node{val}};
    size++; //  increase the size

    if (root == nullptr) // no exist item in the list
    {
        root = node;
        last = root;
        return *this;
    }

    last->next = node;
    last = node;

    return *this;
}

LinkedList &LinkedList::insert(int val, int index)
{
    if (index > size)
        return *this;

    Node *newNode{new Node{val}};

    if (index == 0)
        return insertBegin(val);

    if (size == index)
        return insertEnd(val);

    Node *iter{root};
    Node *iter2{nullptr};

    for (int i = 0; i < index - 1; i++)
        iter = iter->next;

    iter2 = iter->next;

    iter->next = newNode;

    iter->next->next = iter2;

    size++; //  increase the size

    return *this;
}

LinkedList &LinkedList::removeFirst()
{
    Node *temp{root};
    root = root->next;
    delete temp;

    size--; //  decrease the size
    return *this;
}

LinkedList &LinkedList::removeLast()
{
    Node *iter{root};

    for (iter; iter->next != last; iter = iter->next)
        ;

    Node *temp{iter->next};
    last = iter;
    delete temp;
    last->next = nullptr;

    size--;
    return *this;
}

LinkedList &LinkedList::remove(int val)
{
    if (root == nullptr)
        return *this;

    if (root->data == val)
        return removeFirst();

    Node *iter{root};

    while (iter->next != nullptr && iter->next->data != val)
        iter = iter->next;

    if (iter == last) // not found
        return *this;

    Node *temp{iter->next};

    if (temp == last)
        return removeLast();

    iter->next = iter->next->next;
    delete temp;

    size--; //  decrease the size
    return *this;
}

// return the index of given val in the list
int LinkedList::find(int val) const
{
    Node *iter{root};

    int index{};

    while (iter->next != nullptr && iter->data != val)
    {
        index++;
        iter = iter->next;
    }

    return iter->data == val ? index : -1;
}

// get the value of the given index in the list
int &LinkedList::operator[](int index)
{
    Node *iter{root};

    for (int i = 0; i < index; i++)
        iter = iter->next;

    return iter->data;
}

// print the list
std::ostream &operator<<(std::ostream &out, const LinkedList &list)
{
    Node *iter{list.root};

    while (iter != nullptr)
    {
        out << iter->data << ' ';
        iter = iter->next;
    }

    return out;
}