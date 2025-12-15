#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

// Prime number used for double hashing
#define TABLE_PRIME 19

class HashTable {
private:
    int mode; // 0: Linear Probing, 1: Double Hashing, 2: Separate Chaining
    std::vector<int> table; // For Linear Probing and Double Hashing
    std::vector<std::list<int>> chain_table; // For Separate Chaining
    int table_size;
    int num_elements;
    int num_collisions;

    // Hash functions
    int h1(int key) const { return key % table_size; }
    int h2(int key) const { return (key * key) % TABLE_PRIME; }

    void resize_table(); // Resize the hash table when load factor exceeds 70%

public:
    HashTable(int mode);
    void insert(int key);
    void print_table() const;
    int get_num_collisions() const { return num_collisions; }
};

#endif

