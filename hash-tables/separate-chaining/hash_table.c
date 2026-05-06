#include "hash_table.h"

#include <stdlib.h>
#include <string.h>

struct HashEntry {
    char *key;
    int value;
    struct HashEntry *next;
};

/*
 * Hash Table with Separate Chaining
 *
 * Get/put/remove average: O(1)
 * Get/put/remove worst: O(n), when many keys collide.
 * Space Complexity: O(n + m), where m is bucket capacity.
 */
static unsigned long hash_string(const char *key)
{
    unsigned long hash = 5381;

    while (*key != '\0') {
        hash = ((hash << 5) + hash) + (unsigned char)*key;
        key++;
    }

    return hash;
}

static char *copy_string(const char *text)
{
    size_t length = strlen(text) + 1;
    char *copy = malloc(length);

    if (copy != NULL) {
        memcpy(copy, text, length);
    }

    return copy;
}

int hash_table_init(HashTable *table, size_t capacity)
{
    if (table == NULL || capacity == 0) {
        return 0;
    }

    table->buckets = calloc(capacity, sizeof(*table->buckets));
    if (table->buckets == NULL) {
        table->capacity = 0;
        table->size = 0;
        return 0;
    }

    table->capacity = capacity;
    table->size = 0;
    return 1;
}

int hash_table_put(HashTable *table, const char *key, int value)
{
    if (table == NULL || table->buckets == NULL || key == NULL) {
        return 0;
    }

    size_t bucket = hash_string(key) % table->capacity;

    for (HashEntry *entry = table->buckets[bucket]; entry != NULL; entry = entry->next) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return 1;
        }
    }

    HashEntry *entry = malloc(sizeof(*entry));
    if (entry == NULL) {
        return 0;
    }

    entry->key = copy_string(key);
    if (entry->key == NULL) {
        free(entry);
        return 0;
    }

    entry->value = value;
    entry->next = table->buckets[bucket];
    table->buckets[bucket] = entry;
    table->size++;
    return 1;
}

int hash_table_get(const HashTable *table, const char *key, int *value)
{
    if (table == NULL || table->buckets == NULL || key == NULL || value == NULL) {
        return 0;
    }

    size_t bucket = hash_string(key) % table->capacity;

    for (const HashEntry *entry = table->buckets[bucket]; entry != NULL; entry = entry->next) {
        if (strcmp(entry->key, key) == 0) {
            *value = entry->value;
            return 1;
        }
    }

    return 0;
}

int hash_table_remove(HashTable *table, const char *key)
{
    if (table == NULL || table->buckets == NULL || key == NULL) {
        return 0;
    }

    size_t bucket = hash_string(key) % table->capacity;
    HashEntry **current = &table->buckets[bucket];

    while (*current != NULL) {
        if (strcmp((*current)->key, key) == 0) {
            HashEntry *removed = *current;
            *current = removed->next;
            free(removed->key);
            free(removed);
            table->size--;
            return 1;
        }

        current = &(*current)->next;
    }

    return 0;
}

size_t hash_table_size(const HashTable *table)
{
    return table == NULL ? 0 : table->size;
}

void hash_table_destroy(HashTable *table)
{
    if (table == NULL || table->buckets == NULL) {
        return;
    }

    for (size_t bucket = 0; bucket < table->capacity; bucket++) {
        HashEntry *entry = table->buckets[bucket];

        while (entry != NULL) {
            HashEntry *removed = entry;
            entry = entry->next;
            free(removed->key);
            free(removed);
        }
    }

    free(table->buckets);
    table->buckets = NULL;
    table->capacity = 0;
    table->size = 0;
}
