#include "union_find.h"

#include <stdlib.h>

/*
 * Union-Find / Disjoint Set Union
 *
 * Uses path compression and union by rank.
 * Find/union amortized time: inverse Ackermann, effectively O(1).
 * Space Complexity: O(n)
 */
int union_find_init(UnionFind *set, size_t size)
{
    if (set == NULL || size == 0) {
        return 0;
    }

    set->parent = malloc(size * sizeof(*set->parent));
    set->rank = calloc(size, sizeof(*set->rank));
    set->size = size;

    if (set->parent == NULL || set->rank == NULL) {
        free(set->parent);
        free(set->rank);
        set->parent = NULL;
        set->rank = NULL;
        set->size = 0;
        return 0;
    }

    for (size_t index = 0; index < size; index++) {
        set->parent[index] = index;
    }

    return 1;
}

int union_find_find(UnionFind *set, size_t item, size_t *root)
{
    if (set == NULL || root == NULL || item >= set->size) {
        return 0;
    }

    if (set->parent[item] != item) {
        size_t compressed_root;
        if (!union_find_find(set, set->parent[item], &compressed_root)) {
            return 0;
        }
        set->parent[item] = compressed_root;
    }

    *root = set->parent[item];
    return 1;
}

int union_find_union(UnionFind *set, size_t first, size_t second)
{
    size_t first_root;
    size_t second_root;

    if (!union_find_find(set, first, &first_root) || !union_find_find(set, second, &second_root)) {
        return 0;
    }

    if (first_root == second_root) {
        return 1;
    }

    if (set->rank[first_root] < set->rank[second_root]) {
        set->parent[first_root] = second_root;
    } else if (set->rank[first_root] > set->rank[second_root]) {
        set->parent[second_root] = first_root;
    } else {
        set->parent[second_root] = first_root;
        set->rank[first_root]++;
    }

    return 1;
}

int union_find_connected(UnionFind *set, size_t first, size_t second)
{
    size_t first_root;
    size_t second_root;

    if (!union_find_find(set, first, &first_root) || !union_find_find(set, second, &second_root)) {
        return 0;
    }

    return first_root == second_root;
}

void union_find_destroy(UnionFind *set)
{
    if (set == NULL) {
        return;
    }

    free(set->parent);
    free(set->rank);
    set->parent = NULL;
    set->rank = NULL;
    set->size = 0;
}
