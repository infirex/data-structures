#include "binarySearch.hpp"

BinarySearch::BinarySearch() : root{nullptr} {}

Node *BinarySearch::getRoot() const
{
    return root;
}

BinarySearch &BinarySearch::insert(int val)
{
    _insert(val, root);
    return *this;
}

void BinarySearch::_insert(int val, Node *&tree)
{
    if (tree == nullptr)
    {
        tree = new Node{val};
        return;
    }

    if (val > tree->data)
        _insert(val, tree->right);
    else
        _insert(val, tree->left);
}
BinarySearch& BinarySearch::remove(int value)
{
    _remove(root,value);
    return *this;
}
void BinarySearch::_remove(Node *tree, int val)
{
    if (tree == nullptr)
        return;

    if (tree->data == val)
    {
        if (tree->left == nullptr && tree->right == nullptr)
        {
            delete tree;
            return;
        }

        if (tree->right != nullptr)
        {
            tree->data = _min(tree->right);
            _remove(tree->right, _min(tree->right));
        }
        else
        {
            tree->data = _max(tree->left);
            _remove(tree->right, _max(tree->left));
        }
    }

    if (val > tree->data)
        _remove(tree->right, val);
    else
        _remove(tree->left, val);
}

bool BinarySearch::search(int value) const
{
    return _search(root, value);
}

bool BinarySearch::_search(Node *tree, int value) const
{
    if (tree == nullptr)
        return false;

    if (tree->data == value)
        return true;

    return _search(tree->left, value) || _search(tree->right, value);
}

int BinarySearch::_max(Node *tree) const
{
    while (tree->right != nullptr)
        tree = tree->right;

    return tree->data;
}

int BinarySearch::max() const
{
    return _max(root);
}

int BinarySearch::_min(Node *tree) const
{
    while (tree->left != nullptr)
        tree = tree->left;

    return tree->data;
}

int BinarySearch::min() const
{
    return _min(root);
}

void BinarySearch::_printBFS(Node *tree,std::queue<Node*>& queue) const
{
    if(queue.empty())
        return;

    tree = queue.front();
    std::cout << queue.front()->data << ' ';
    queue.pop();

    if(tree->left != nullptr)
        queue.push(tree->left);
    if(tree->right != nullptr)
        queue.push(tree->right);
    
    _printBFS(tree,queue);
}

void BinarySearch::printBFS() const
{
    std::queue<Node*> queue;
    queue.push(root);
    _printBFS(root,queue);
}

void BinarySearch::_printTree(Node *tree) const
{
    if (tree == nullptr)
        return;

    _printTree(tree->left);
    std::cout << tree->data << ' ';
    _printTree(tree->right);
}

void BinarySearch::printTree() const
{
    _printTree(root);
}
