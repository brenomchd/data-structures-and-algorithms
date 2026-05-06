#include "matrix_graph.h"

#include <stdlib.h>

/*
 * Adjacency Matrix Graph
 *
 * Add/check edge: O(1)
 * BFS/DFS traversal: O(V^2)
 * Space Complexity: O(V^2)
 */
static size_t edge_index(const MatrixGraph *graph, size_t source, size_t target)
{
    return source * graph->vertices + target;
}

int graph_init(MatrixGraph *graph, size_t vertices, int directed)
{
    if (graph == NULL || vertices == 0) {
        return 0;
    }

    graph->matrix = calloc(vertices * vertices, sizeof(*graph->matrix));
    if (graph->matrix == NULL) {
        graph->vertices = 0;
        graph->directed = 0;
        return 0;
    }

    graph->vertices = vertices;
    graph->directed = directed;
    return 1;
}

int graph_add_edge(MatrixGraph *graph, size_t source, size_t target)
{
    if (graph == NULL || graph->matrix == NULL || source >= graph->vertices || target >= graph->vertices) {
        return 0;
    }

    graph->matrix[edge_index(graph, source, target)] = 1;

    if (!graph->directed) {
        graph->matrix[edge_index(graph, target, source)] = 1;
    }

    return 1;
}

int graph_has_edge(const MatrixGraph *graph, size_t source, size_t target)
{
    if (graph == NULL || graph->matrix == NULL || source >= graph->vertices || target >= graph->vertices) {
        return 0;
    }

    return graph->matrix[edge_index(graph, source, target)] != 0;
}

size_t graph_bfs(const MatrixGraph *graph, size_t start, size_t output[], size_t capacity)
{
    if (graph == NULL || graph->matrix == NULL || output == NULL || start >= graph->vertices) {
        return 0;
    }

    int *visited = calloc(graph->vertices, sizeof(*visited));
    size_t *queue = malloc(graph->vertices * sizeof(*queue));
    if (visited == NULL || queue == NULL) {
        free(visited);
        free(queue);
        return 0;
    }

    size_t front = 0;
    size_t back = 0;
    size_t count = 0;

    visited[start] = 1;
    queue[back++] = start;

    while (front < back && count < capacity) {
        size_t vertex = queue[front++];
        output[count++] = vertex;

        for (size_t next = 0; next < graph->vertices; next++) {
            if (graph_has_edge(graph, vertex, next) && !visited[next]) {
                visited[next] = 1;
                queue[back++] = next;
            }
        }
    }

    free(visited);
    free(queue);
    return count;
}

static void dfs_visit(const MatrixGraph *graph, size_t vertex, int visited[], size_t output[], size_t capacity, size_t *count)
{
    if (*count >= capacity) {
        return;
    }

    visited[vertex] = 1;
    output[(*count)++] = vertex;

    for (size_t next = 0; next < graph->vertices; next++) {
        if (graph_has_edge(graph, vertex, next) && !visited[next]) {
            dfs_visit(graph, next, visited, output, capacity, count);
        }
    }
}

size_t graph_dfs(const MatrixGraph *graph, size_t start, size_t output[], size_t capacity)
{
    if (graph == NULL || graph->matrix == NULL || output == NULL || start >= graph->vertices) {
        return 0;
    }

    int *visited = calloc(graph->vertices, sizeof(*visited));
    if (visited == NULL) {
        return 0;
    }

    size_t count = 0;
    dfs_visit(graph, start, visited, output, capacity, &count);
    free(visited);
    return count;
}

void graph_destroy(MatrixGraph *graph)
{
    if (graph == NULL) {
        return;
    }

    free(graph->matrix);
    graph->matrix = NULL;
    graph->vertices = 0;
    graph->directed = 0;
}
