#include "doublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList() : size{0}, root{nullptr}, last{nullptr}, data{0}
{
}

int DoublyLinkedList::getSize() const { return size; }

int DoublyLinkedList::getFirstElement() const { return root->data; }

int DoublyLinkedList::getLastElement() const { return last->data; }

DoublyLinkedList &DoublyLinkedList::insertEnd(int val)
{
    if (root == nullptr)
        return insertBegin(val);

    Node *newNode{new Node{val}};

    Node *temp{last};
    last = newNode;
    last->prev = temp;
    temp->next = last;

    size++;
    return *this;
}

DoublyLinkedList &DoublyLinkedList::insertBegin(int val)
{
    Node *newNode{new Node{val}};
    size++;

    if (root == nullptr)
    {
        root = newNode;
        last = root;
        return *this;
    }

    Node *temp{root};
    root = newNode;
    root->next = temp;
    temp->prev = root;

    return *this;
}

DoublyLinkedList &DoublyLinkedList::insert(int val, int index)
{
    if (index == 0)
    {
        return insertBegin(val);
    }
    if (size == index)
    {
        return insertEnd(val);
    }

    Node *newNode{new Node{val}};

    Node *iter{root};

    for (int i = 0; i < index - 1; i++)
        iter = iter->next;

    newNode->next = iter->next;
    newNode->prev = iter;
    iter->next->prev = newNode;
    iter->next = newNode;

    size++;
    return *this;
}

DoublyLinkedList &DoublyLinkedList::removeFirst()
{
    if (root == nullptr)
        return *this;

    Node *temp{root};
    root = root->next;
    root->prev = nullptr;
    delete temp;

    size--;
    return *this;
}

DoublyLinkedList &DoublyLinkedList::removeLast()
{
    if (root == nullptr)
        return *this;

    Node *temp{last};
    last = last->prev;
    last->next = nullptr;
    delete temp;

    size--;
    return *this;
}

int &DoublyLinkedList::operator[](int index)
{
    Node *iter{root};

    for (int i = 0; i < index; i++)
        iter = iter->next;

    return iter->data;
}

std::ostream &operator<<(std::ostream &out, const DoublyLinkedList &list)
{
    Node *iter{list.root};

    while (iter != nullptr)
    {
        out << iter->data << ' ';
        iter = iter->next;
    }

    return out;
}