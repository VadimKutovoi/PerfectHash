#include "SUH.h"
#include <iostream>

#define HASH_TABLE_SIZE 10
#define DATA_VECTOR_SIZE 5

int main() {
    std::vector<uint> test_table(HASH_TABLE_SIZE);
    std::vector<int> test_data;
    unihash uh(HASH_TABLE_SIZE);

    for (int i = 0; i <= DATA_VECTOR_SIZE; ++i)
        test_data.push_back(i);

    for (int i = 0; i <= DATA_VECTOR_SIZE; ++i)
        std::cout << test_data[i] << std::endl;

    uh.rehash();
    for (int i = 0; i <= DATA_VECTOR_SIZE; ++i)
        test_table.insert(test_table.begin() + uh.hash(test_data[i]), test_data[i]);

    std::cout << "Hashing results" << std::endl;
    for (int i = 0; i <= HASH_TABLE_SIZE; ++i)
        std::cout << test_table[i] << std::endl;
}