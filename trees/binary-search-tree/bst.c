#include "bst.h"

#include <stdlib.h>

struct BstNode {
    int value;
    struct BstNode *left;
    struct BstNode *right;
};

/*
 * Binary Search Tree
 *
 * Search/insert average: O(log n)
 * Search/insert worst: O(n), when the tree becomes unbalanced.
 * Space Complexity: O(n)
 */
void bst_init(BinarySearchTree *tree)
{
    if (tree == NULL) {
        return;
    }

    tree->root = NULL;
    tree->size = 0;
}

static BstNode *node_create(int value)
{
    BstNode *node = malloc(sizeof(*node));
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int bst_insert(BinarySearchTree *tree, int value)
{
    if (tree == NULL) {
        return 0;
    }

    BstNode **current = &tree->root;

    while (*current != NULL) {
        if (value == (*current)->value) {
            return 1;
        }

        current = value < (*current)->value ? &(*current)->left : &(*current)->right;
    }

    *current = node_create(value);
    if (*current == NULL) {
        return 0;
    }

    tree->size++;
    return 1;
}

int bst_contains(const BinarySearchTree *tree, int value)
{
    if (tree == NULL) {
        return 0;
    }

    const BstNode *current = tree->root;

    while (current != NULL) {
        if (value == current->value) {
            return 1;
        }

        current = value < current->value ? current->left : current->right;
    }

    return 0;
}

size_t bst_size(const BinarySearchTree *tree)
{
    return tree == NULL ? 0 : tree->size;
}

static void node_in_order(const BstNode *node, int output[], size_t capacity, size_t *index)
{
    if (node == NULL || *index >= capacity) {
        return;
    }

    node_in_order(node->left, output, capacity, index);

    if (*index < capacity) {
        output[*index] = node->value;
        (*index)++;
    }

    node_in_order(node->right, output, capacity, index);
}

void bst_in_order(const BinarySearchTree *tree, int output[], size_t capacity)
{
    size_t index = 0;

    if (tree == NULL || output == NULL) {
        return;
    }

    node_in_order(tree->root, output, capacity, &index);
}

static void node_destroy(BstNode *node)
{
    if (node == NULL) {
        return;
    }

    node_destroy(node->left);
    node_destroy(node->right);
    free(node);
}

void bst_clear(BinarySearchTree *tree)
{
    if (tree == NULL) {
        return;
    }

    node_destroy(tree->root);
    tree->root = NULL;
    tree->size = 0;
}
