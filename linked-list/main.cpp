#include "linkedList.hpp"

int main(int argc, char const *argv[])
{
    LinkedList linkedlist{};
    std::cout << linkedlist.insertEnd(1).insertEnd(2).insertEnd(3).remove(2).insertBegin(0).remove(3);
    return 0;
}
