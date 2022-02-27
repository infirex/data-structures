#include "node.hpp"

Node::Node() : prev{nullptr}, next{nullptr} {}

Node::Node(int val)
{
    data = val;
    next = nullptr;
    prev = nullptr;
}
