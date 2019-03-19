#include "SUH.h"
#include <iostream>

#define HASH_TABLE_SIZE 15
#define DATA_VECTOR_SIZE 10

int main() {
    std::vector<int> test_data;
    unihash uh(HASH_TABLE_SIZE);

    for (int i = 0; i < DATA_VECTOR_SIZE; ++i)
        test_data.push_back(i + 1);

    for (int i = 0; i < DATA_VECTOR_SIZE; ++i)
        std::cout << test_data[i] << std::endl;

    uh.rehash();
    uh.build_table(test_data);

    std::cout << "Hashing results" << std::endl;
    for (int i = 0; i < HASH_TABLE_SIZE; ++i)
        std::cout << uh.get_cell(i) << std::endl;

    std::cout << "Comparing results..." << std::endl;

    for (int i = 0; i < DATA_VECTOR_SIZE; ++i) {
        int item = uh.find(test_data[i]);
        std::cout << item << std::endl;
    }
}