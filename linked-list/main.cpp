#include "linkedList.hpp"

int main(int argc, char const *argv[])
{
    LinkedList linkedlist{};
    linkedlist.insert(1).insert(2).insert(3).insert(4,3).printList();
    return 0;
}
