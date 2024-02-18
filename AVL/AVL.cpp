#include<algorithm>
#include<cmath>
#include<iostream>
#include "AVL.h"

int AVL::height(Node* t) const
{
    return t == nullptr ? -1 : t->height;
}

AVL::AVL()
{
    root = nullptr;
}

void AVL::insert(const int& x)
{
    insert(x, root);
}

void AVL::print()
{
    if (root != nullptr)
        print(root);
}

void AVL::insert(const int& x, Node*& t)
{
    if (t == nullptr)
        t = new Node(x, nullptr, nullptr);
    else if (x < t->data)insert(x, t->left);
    else if (x > t->data)insert(x, t->right);
    balance(t);
    t->height = std::max(height(t->left), height(t->right)) + 1;
}

void AVL::balance(Node*& t)
{
    if (t == nullptr)return void(0);
    if (height(t->left) - height(t->right) > Allowd)
        if (height(t->left->left) >= height(t->left->right))
            rotateWithLeftChild(t);
        else
            doubleWithLeftChild(t);
    else if (height(t->right) - height(t->left) > Allowd)
        if (height(t->right->right) >= height(t->right->left))
            rotateWithRightChild(t);
        else
            doubleWithRightChild(t);

}

void AVL::rotateWithLeftChild(Node*& t)
{
    Node* k1 = t->left;
    t->left = k1->right;
    k1->right = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    k1->height = std::max(height(k1->left), height(k1->right)) + 1;
    t = k1;
}
void AVL::rotateWithRightChild(Node*& t)
{
    Node* k1 = t->right;
    t->right = k1->left;
    k1->left = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    k1->height = std::max(height(k1->left), height(k1->right)) + 1;
    t = k1;
}

void AVL::doubleWithLeftChild(Node*& t)
{
    rotateWithRightChild(t->left);
    rotateWithLeftChild(t);
}

void AVL::doubleWithRightChild(Node*& t)
{
    rotateWithLeftChild(t->right);
    rotateWithRightChild(t);
}

void AVL::print(Node* t)
{
    if (t == nullptr)
    {
        return void (0);
    }
    print(t->left);
   
    print(t->right);
    std::cout << t->data << " ";
}

