#include "llrbtree.h"
#include <iostream>

LLRBTNode::LLRBTNode(int value) 
    : data(value), left(nullptr), right(nullptr), color(true) {} // true = red, false = black

// Rotate left helper
LLRBTNode* LLRBTree::rotateLeft(LLRBTNode* node) {
    LLRBTNode* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    temp->color = node->color;
    node->color = true;
    return temp;
}

// Rotate right helper
LLRBTNode* LLRBTree::rotateRight(LLRBTNode* node) {
    LLRBTNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    temp->color = node->color;
    node->color = true;
    return temp;
}

// Flip colors helper
void LLRBTree::flipColors(LLRBTNode* node) {
    node->color = !node->color;
    if (node->left) node->left->color = !node->left->color;
    if (node->right) node->right->color = !node->right->color;
}

// Balance the tree
LLRBTNode* LLRBTree::balance(LLRBTNode* node) {
    if (node->right && node->right->color) node = rotateLeft(node);
    if (node->left && node->left->color && node->left->left && node->left->left->color)
        node = rotateRight(node);
    if (node->left && node->left->color && node->right && node->right->color)
        flipColors(node);
    return node;
}

// Insert helper
LLRBTNode* LLRBTree::insert(LLRBTNode* node, int value) {
    if (!node) return new LLRBTNode(value);
    if (value < node->data) node->left = insert(node->left, value);
    else node->right = insert(node->right, value);
    return balance(node);
}

// Public insert method
void LLRBTree::insert(int value) {
    root = insert(root, value);
    root->color = false; // Root must always be black
}

// Tree height
int LLRBTree::height(LLRBTNode* node) const {
    if (!node) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

int LLRBTree::height() const {
    return height(root);
}

// Pre-order traversal
void LLRBTree::preorder(LLRBTNode* node) const {
    if (!node) return;
    std::cout << node->data << ":" << node->color << " ";
    preorder(node->left);
    preorder(node->right);
}

void LLRBTree::preorder() const {
    preorder(root);
    std::cout << std::endl;
}

// In-order traversal
void LLRBTree::inorder(LLRBTNode* node) const {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << ":" << node->color << " ";
    inorder(node->right);
}

void LLRBTree::inorder() const {
    inorder(root);
    std::cout << std::endl;
}

// Post-order traversal
void LLRBTree::postorder(LLRBTNode* node) const {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << ":" << node->color << " ";
}

void LLRBTree::postorder() const {
    postorder(root);
    std::cout << std::endl;
}

