#include "hash_table.h"

HashTable::HashTable(int mode)
    : mode(mode), table_size(16), num_elements(0), num_collisions(0) {
    if (mode == 2) {
        // Initialize for Separate Chaining
        chain_table.resize(table_size);
    } else {
        // Initialize for Linear Probing or Double Hashing
        table.resize(table_size, 0);
    }
}

void HashTable::resize_table() {
    int old_size = table_size;
    table_size *= 2;
    num_elements = 0; // Reset to recount elements
    num_collisions = 0;

    if (mode == 2) {
        // Resize for Separate Chaining
        std::vector<std::list<int>> old_table = chain_table;
        chain_table.clear();
        chain_table.resize(table_size);

        // Rehash all elements
        for (const auto& bucket : old_table) {
            for (int key : bucket) {
                insert(key);
            }
        }
    } else {
        // Resize for Linear Probing or Double Hashing
        std::vector<int> old_table = table;
        table.clear();
        table.resize(table_size, 0);

        // Rehash all elements
        for (int key : old_table) {
            if (key != 0) {
                insert(key);
            }
        }
    }
}

void HashTable::insert(int key) {
    if (num_elements >= 0.7 * table_size) {
        resize_table();
    }

    if (mode == 2) {
        // Separate Chaining
        int index = h1(key);
        chain_table[index].push_back(key);
    } else {
        // Linear Probing or Double Hashing
        int index = h1(key);
        int i = 0;

        while (table[index] != 0) {
            num_collisions++;
            i++;
            if (mode == 0) {
                // Linear Probing
                index = (index + 1) % table_size;
            } else if (mode == 1) {
                // Double Hashing
                index = (h1(key) + i * h2(key)) % table_size;
            }
        }
        table[index] = key;
    }

    num_elements++;
}

void HashTable::print_table() const {
    if (mode == 2) {
        // Print for Separate Chaining
        for (size_t i = 0; i < chain_table.size(); i++) {
            std::cout << i << ": ";
            for (int key : chain_table[i]) {
                std::cout << key << " ";
            }
            std::cout << std::endl;
        }
    } else {
        // Print for Linear Probing or Double Hashing
        for (size_t i = 0; i < table.size(); i++) {
            std::cout << i << ": " << table[i] << std::endl;
        }
    }
}

