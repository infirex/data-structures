#include "binarySearch.hpp"

int main(int argc, char const *argv[])
{
    BinarySearch tree{};
    tree.insert(1).insert(2).insert(100).remove(2).printTree();
    return 0;
}
