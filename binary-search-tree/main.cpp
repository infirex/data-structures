#include "binarySearch.hpp"

int main(int argc, char const *argv[])
{
    BinarySearch tree{};
    tree.insert(1).insert(2).insert(0).insert(4).printBFS();
    return 0;
}
