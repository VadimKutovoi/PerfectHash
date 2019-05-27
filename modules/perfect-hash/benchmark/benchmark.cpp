#include <vector>
#include <random>
#include <iostream>
#include <chrono>
#include <unordered_map> 

#include "../include/universal_hash_table.h"
#include "../include/multiply_shift_hash_table.h"

#ifndef MODULES_PERFECT_HASH_APP_PHBENCHMARK_CPP_
#define MODULES_PERFECT_HASH_APP_PHBENCHMARK_CPP_

#define DATA_VECTOR_SIZE 100000
#define TABLE_SIZE_RATIO 1.5
#define HASHING_DATA_TYPE unihash::ullong

int main(int argc, char **argv) {
    std::vector<HASHING_DATA_TYPE> data(DATA_VECTOR_SIZE);

    static std::mt19937 gen;
    static std::uniform_int_distribution<HASHING_DATA_TYPE> random(1, 1198754321 / 10);

    for (auto i = 0; i < DATA_VECTOR_SIZE; i++) {
        //HASHING_DATA_TYPE rgen = random(gen);
        data[i] = i;
    }


    // UNORDERED MAP

    std::unordered_map<HASHING_DATA_TYPE, HASHING_DATA_TYPE> umap;

    std::chrono::high_resolution_clock::time_point t1 =
        std::chrono::high_resolution_clock::now();
    
    for (auto i : data) {
        umap.insert(std::pair<HASHING_DATA_TYPE, HASHING_DATA_TYPE>(i, i));
    }

    std::chrono::high_resolution_clock::time_point t2 =
        std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span =
        std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Unordered map : " << time_span.count() << " seconds." << std::endl;


    // UNIVERSAL HASHING

    unsigned int table_size = TABLE_SIZE_RATIO * DATA_VECTOR_SIZE;

    t1 = std::chrono::high_resolution_clock::now();

    unihash table1(table_size);

    table1.buildTable(data);

    t2 = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Universal : " << time_span.count() << " seconds." << std::endl;


    // MULTIPLY SHIFT HASHING

    mshifthash table2(table_size);

    t1 = std::chrono::high_resolution_clock::now();

    table2.buildTable(data);

    t2 = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Multiply shift : " << time_span.count() << " seconds." << std::endl;
}

#endif
