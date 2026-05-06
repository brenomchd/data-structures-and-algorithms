#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include <stddef.h>

typedef struct {
    int *matrix;
    size_t vertices;
    int directed;
} MatrixGraph;

int graph_init(MatrixGraph *graph, size_t vertices, int directed);
int graph_add_edge(MatrixGraph *graph, size_t source, size_t target);
int graph_has_edge(const MatrixGraph *graph, size_t source, size_t target);
size_t graph_bfs(const MatrixGraph *graph, size_t start, size_t output[], size_t capacity);
size_t graph_dfs(const MatrixGraph *graph, size_t start, size_t output[], size_t capacity);
void graph_destroy(MatrixGraph *graph);

#endif
