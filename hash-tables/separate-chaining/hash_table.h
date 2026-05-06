#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

typedef struct HashEntry HashEntry;

typedef struct {
    HashEntry **buckets;
    size_t capacity;
    size_t size;
} HashTable;

int hash_table_init(HashTable *table, size_t capacity);
int hash_table_put(HashTable *table, const char *key, int value);
int hash_table_get(const HashTable *table, const char *key, int *value);
int hash_table_remove(HashTable *table, const char *key);
size_t hash_table_size(const HashTable *table);
void hash_table_destroy(HashTable *table);

#endif
