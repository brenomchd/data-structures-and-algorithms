# Data Structures and Algorithms in C

Repository with classic data structures and algorithms implemented in C, organized as a small academic library for study, practice, and portfolio presentation.

## About

This repository documents my practice with data structures, algorithms, modular C programming, memory management, and clean API design using `.c` and `.h` files.

The project is organized by computer science topic. Each module exposes a public header file, keeps implementation details in a source file, and is validated by a lightweight test program.

The code is organized into these main areas:

- `sorting/`: comparison-based sorting algorithms.
- `searching/`: search algorithms for ordered data.
- `linked-lists/`: linked list implementations.
- `stacks/`: stack implementations.
- `queues/`: queue implementations.
- `trees/`: tree data structures.
- `graphs/`: graph representations and traversals.
- `hash-tables/`: hash table implementations.
- `heaps/`: heap data structures.
- `recursion/`: recursive and iterative algorithm examples.
- `union-find/`: disjoint set union data structure.
- `tests/`: test program that validates the implemented modules.

## Repository Structure

```text
.
├── graphs/
│   └── matrix-graph/
│       ├── matrix_graph.c
│       └── matrix_graph.h
├── hash-tables/
│   └── separate-chaining/
│       ├── hash_table.c
│       └── hash_table.h
├── heaps/
│   └── binary-heap/
│       ├── binary_heap.c
│       └── binary_heap.h
├── linked-lists/
│   └── singly-linked-list/
│       ├── singly_linked_list.c
│       └── singly_linked_list.h
├── queues/
│   └── linked-queue/
│       ├── linked_queue.c
│       └── linked_queue.h
├── recursion/
│   ├── recursion.c
│   └── recursion.h
├── searching/
│   ├── binary_search.c
│   └── binary_search.h
├── sorting/
│   ├── sorting.c
│   └── sorting.h
├── stacks/
│   └── linked-stack/
│       ├── linked_stack.c
│       └── linked_stack.h
├── tests/
│   └── test_algorithms.c
├── trees/
│   └── binary-search-tree/
│       ├── bst.c
│       └── bst.h
└── union-find/
    ├── union_find.c
    └── union_find.h
```

## Contents

### Sorting

The `sorting/` directory contains comparison-based sorting algorithms.

Implemented algorithms:

- Bubble sort
- Selection sort
- Merge sort
- Quick sort

Complexities:

| Algorithm | Best Case | Average Case | Worst Case | Space |
| --- | ---: | ---: | ---: | ---: |
| Bubble sort | O(n) | O(n^2) | O(n^2) | O(1) |
| Selection sort | O(n^2) | O(n^2) | O(n^2) | O(1) |
| Merge sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick sort | O(n log n) | O(n log n) | O(n^2) | O(log n) |

### Searching

The `searching/` directory contains algorithms for locating values in collections.

Implemented algorithm:

- Binary search

Binary search requires the input array to be sorted.

### Linear Data Structures

The repository includes linked implementations of common linear data structures:

- `linked-lists/singly-linked-list/`: singly linked list
- `stacks/linked-stack/`: stack using linked nodes
- `queues/linked-queue/`: queue using linked nodes

These modules include initialization, insertion/removal operations, size tracking, and cleanup functions for dynamic memory.

### Trees

The `trees/` directory contains a binary search tree implementation.

Features:

- Insert values
- Search values
- In-order traversal
- Track tree size
- Clear allocated nodes

### Graphs

The `graphs/` directory contains an adjacency matrix graph implementation.

Features:

- Directed or undirected graph initialization
- Add edges
- Check whether an edge exists
- Breadth-first search
- Depth-first search

### Hash Tables

The `hash-tables/` directory contains a hash table implemented with separate chaining.

Features:

- Insert or update key-value pairs
- Search values by key
- Remove keys
- Destroy allocated entries

### Heaps

The `heaps/` directory contains a binary max heap implementation.

Features:

- Push values
- Peek maximum value
- Pop maximum value
- Dynamic resizing

### Recursion

The `recursion/` directory contains small examples used to practice recursive thinking and algorithmic complexity.

Implemented functions:

- Factorial
- Fibonacci

### Union-Find

The `union-find/` directory contains a disjoint set union implementation.

Features:

- Path compression
- Union by rank
- Connectivity checks

## Requirements

- C compiler, such as `gcc` or `clang`
- Terminal or command-line environment

## Compile and Run Tests

To compile and run the test program:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -O2 -I. \
  tests/test_algorithms.c \
  sorting/sorting.c \
  searching/binary_search.c \
  recursion/recursion.c \
  linked-lists/singly-linked-list/singly_linked_list.c \
  stacks/linked-stack/linked_stack.c \
  queues/linked-queue/linked_queue.c \
  trees/binary-search-tree/bst.c \
  graphs/matrix-graph/matrix_graph.c \
  hash-tables/separate-chaining/hash_table.c \
  heaps/binary-heap/binary_heap.c \
  union-find/union_find.c \
  -o test_algorithms

./test_algorithms
```

Expected output:

```text
All tests passed.
```

## Compile Individual Modules

Each module is designed to be reused through its header file.

Example:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -I. \
  your_program.c \
  sorting/sorting.c \
  -o your_program
```

## Notes

This repository is focused on clarity, modularity, and learning. The implementations favor readable code, explicit memory management, and small APIs over excessive abstraction.

## Future Improvements

- Add more unit tests and edge cases.
- Add benchmark programs for algorithm comparison.
- Add adjacency list graph representation.
- Add balanced trees such as AVL or red-black trees.
- Add documentation examples for each module.

## Author

Breno Machado Barros
