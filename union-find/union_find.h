#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stddef.h>

typedef struct {
    size_t *parent;
    size_t *rank;
    size_t size;
} UnionFind;

int union_find_init(UnionFind *set, size_t size);
int union_find_find(UnionFind *set, size_t item, size_t *root);
int union_find_union(UnionFind *set, size_t first, size_t second);
int union_find_connected(UnionFind *set, size_t first, size_t second);
void union_find_destroy(UnionFind *set);

#endif
