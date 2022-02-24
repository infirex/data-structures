#include "doublyLinkedList.hpp"

int main(int argc, char const *argv[])
{
    DoublyLinkedList list{};

    std::cout << list.insertEnd(1).insertEnd(2).insertBegin(0);
    return 0;
}
