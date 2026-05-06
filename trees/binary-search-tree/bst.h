#ifndef BST_H
#define BST_H

#include <stddef.h>

typedef struct BstNode BstNode;

typedef struct {
    BstNode *root;
    size_t size;
} BinarySearchTree;

void bst_init(BinarySearchTree *tree);
int bst_insert(BinarySearchTree *tree, int value);
int bst_contains(const BinarySearchTree *tree, int value);
size_t bst_size(const BinarySearchTree *tree);
void bst_in_order(const BinarySearchTree *tree, int output[], size_t capacity);
void bst_clear(BinarySearchTree *tree);

#endif
