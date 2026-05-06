#include <stdio.h>
#include <string.h>

#include "graphs/matrix-graph/matrix_graph.h"
#include "hash-tables/separate-chaining/hash_table.h"
#include "heaps/binary-heap/binary_heap.h"
#include "linked-lists/singly-linked-list/singly_linked_list.h"
#include "queues/linked-queue/linked_queue.h"
#include "recursion/recursion.h"
#include "searching/binary_search.h"
#include "sorting/sorting.h"
#include "stacks/linked-stack/linked_stack.h"
#include "trees/binary-search-tree/bst.h"
#include "union-find/union_find.h"

#define ASSERT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            printf("FAIL: %s:%d: %s\n", __FILE__, __LINE__, #condition); \
            return 0; \
        } \
    } while (0)

static int arrays_equal(const int first[], const int second[], size_t length)
{
    for (size_t index = 0; index < length; index++) {
        if (first[index] != second[index]) {
            return 0;
        }
    }

    return 1;
}

static int test_sorting(void)
{
    int expected[] = {1, 2, 3, 4, 5};
    int bubble[] = {5, 4, 3, 2, 1};
    int selection[] = {3, 1, 4, 5, 2};
    int merge[] = {2, 5, 1, 4, 3};
    int quick[] = {4, 2, 5, 1, 3};
    size_t length = sizeof(expected) / sizeof(expected[0]);

    bubble_sort(bubble, length);
    selection_sort(selection, length);
    ASSERT_TRUE(merge_sort(merge, length));
    quick_sort(quick, length);

    ASSERT_TRUE(arrays_equal(bubble, expected, length));
    ASSERT_TRUE(arrays_equal(selection, expected, length));
    ASSERT_TRUE(arrays_equal(merge, expected, length));
    ASSERT_TRUE(arrays_equal(quick, expected, length));

    return 1;
}

static int test_searching_and_recursion(void)
{
    int values[] = {1, 3, 5, 7, 9};

    ASSERT_TRUE(binary_search(values, 5, 7) == 3);
    ASSERT_TRUE(binary_search(values, 5, 4) == -1);
    ASSERT_TRUE(factorial(5) == 120);
    ASSERT_TRUE(fibonacci(10) == 55);

    return 1;
}

static int test_linear_structures(void)
{
    SinglyLinkedList list;
    LinkedStack stack;
    LinkedQueue queue;
    int value;

    list_init(&list);
    ASSERT_TRUE(list_push_back(&list, 10));
    ASSERT_TRUE(list_push_front(&list, 5));
    ASSERT_TRUE(list_contains(&list, 10));
    ASSERT_TRUE(list_remove(&list, 5));
    ASSERT_TRUE(list_size(&list) == 1);
    list_clear(&list);

    stack_init(&stack);
    ASSERT_TRUE(stack_push(&stack, 1));
    ASSERT_TRUE(stack_push(&stack, 2));
    ASSERT_TRUE(stack_pop(&stack, &value) && value == 2);
    ASSERT_TRUE(stack_peek(&stack, &value) && value == 1);
    stack_clear(&stack);

    queue_init(&queue);
    ASSERT_TRUE(queue_enqueue(&queue, 1));
    ASSERT_TRUE(queue_enqueue(&queue, 2));
    ASSERT_TRUE(queue_dequeue(&queue, &value) && value == 1);
    ASSERT_TRUE(queue_peek(&queue, &value) && value == 2);
    queue_clear(&queue);

    return 1;
}

static int test_tree_heap_hash_and_union_find(void)
{
    BinarySearchTree tree;
    BinaryMaxHeap heap;
    HashTable table;
    UnionFind set;
    int traversal[5];
    int value;

    bst_init(&tree);
    ASSERT_TRUE(bst_insert(&tree, 3));
    ASSERT_TRUE(bst_insert(&tree, 1));
    ASSERT_TRUE(bst_insert(&tree, 4));
    ASSERT_TRUE(bst_insert(&tree, 2));
    ASSERT_TRUE(bst_contains(&tree, 4));
    bst_in_order(&tree, traversal, 5);
    ASSERT_TRUE(traversal[0] == 1 && traversal[1] == 2 && traversal[2] == 3 && traversal[3] == 4);
    bst_clear(&tree);

    heap_init(&heap);
    ASSERT_TRUE(heap_push(&heap, 3));
    ASSERT_TRUE(heap_push(&heap, 10));
    ASSERT_TRUE(heap_push(&heap, 5));
    ASSERT_TRUE(heap_pop(&heap, &value) && value == 10);
    heap_destroy(&heap);

    ASSERT_TRUE(hash_table_init(&table, 17));
    ASSERT_TRUE(hash_table_put(&table, "alice", 42));
    ASSERT_TRUE(hash_table_put(&table, "bob", 7));
    ASSERT_TRUE(hash_table_get(&table, "alice", &value) && value == 42);
    ASSERT_TRUE(hash_table_remove(&table, "bob"));
    hash_table_destroy(&table);

    ASSERT_TRUE(union_find_init(&set, 5));
    ASSERT_TRUE(union_find_union(&set, 0, 1));
    ASSERT_TRUE(union_find_union(&set, 1, 2));
    ASSERT_TRUE(union_find_connected(&set, 0, 2));
    ASSERT_TRUE(!union_find_connected(&set, 0, 4));
    union_find_destroy(&set);

    return 1;
}

static int test_graph(void)
{
    MatrixGraph graph;
    size_t bfs[5];
    size_t dfs[5];

    ASSERT_TRUE(graph_init(&graph, 5, 0));
    ASSERT_TRUE(graph_add_edge(&graph, 0, 1));
    ASSERT_TRUE(graph_add_edge(&graph, 0, 2));
    ASSERT_TRUE(graph_add_edge(&graph, 1, 3));
    ASSERT_TRUE(graph_add_edge(&graph, 2, 4));

    ASSERT_TRUE(graph_bfs(&graph, 0, bfs, 5) == 5);
    ASSERT_TRUE(graph_dfs(&graph, 0, dfs, 5) == 5);
    ASSERT_TRUE(bfs[0] == 0);
    ASSERT_TRUE(dfs[0] == 0);
    ASSERT_TRUE(graph_has_edge(&graph, 1, 0));

    graph_destroy(&graph);
    return 1;
}

int main(void)
{
    ASSERT_TRUE(test_sorting());
    ASSERT_TRUE(test_searching_and_recursion());
    ASSERT_TRUE(test_linear_structures());
    ASSERT_TRUE(test_tree_heap_hash_and_union_find());
    ASSERT_TRUE(test_graph());

    printf("All tests passed.\n");
    return 0;
}
