#include "node.hpp"

Node::Node() : next{nullptr} {}

Node::Node(int x)
{
    data = x;
    next = nullptr;
}