#include <vector>
#include <random>
#include <iostream>
#include <chrono>
#include <unordered_map> 
#include <map>

#include "../include/perfect_hash_table.h"
#include "../include/perfect_hash_table_mshift.h"

#ifndef MODULES_PERFECT_HASH_APP_PHBENCHMARK_CPP_
#define MODULES_PERFECT_HASH_APP_PHBENCHMARK_CPP_

#define DATA_VECTOR_SIZE 1000000
#define TABLE_SIZE_RATIO 100
#define HASHING_DATA_TYPE unihash::ullong
#define EXTRA_VERBOSITY

int main(int argc, char **argv) {
    std::map<HASHING_DATA_TYPE, HASHING_DATA_TYPE> data_set;

    static std::mt19937 gen;
    static std::uniform_int_distribution<HASHING_DATA_TYPE> random(INT32_MAX, INT64_MAX);

    for (auto i = 0; i < DATA_VECTOR_SIZE; i++) {
        HASHING_DATA_TYPE rgen = random(gen);
#ifdef EXTRA_VERBOSITY
        if (i < 10) std::cout << rgen << std::endl;
#endif
        data_set.insert(std::pair<HASHING_DATA_TYPE, HASHING_DATA_TYPE>(rgen, rgen));
    }

    std::cout << data_set.size() << std::endl;

    std::vector<HASHING_DATA_TYPE> data;

    for (auto i : data_set) {
        data.push_back(i.first);
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

    // PERFECT HASHING

    perfhash table1(data.size());

    t1 = std::chrono::high_resolution_clock::now();

    table1.buildTable(data);

    t2 = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Perfect hashing unihash: " << time_span.count() << " seconds." << std::endl;

    // PERFECT HASHING MSHIFT

    perfhash_mshift table2(data.size());

    t1 = std::chrono::high_resolution_clock::now();

    table2.buildTable(data);

    t2 = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Perfect hashing mshift : " << time_span.count() << " seconds." << std::endl;

#ifdef EXTRA_VERBOSITY
    std::cout << "Comparing results..." << std::endl;
#endif

    for (auto i : data) {
        uint64_t el = 0;
        el = table1.find(i);
        if (el != i) std::cout << "ERROR in perfhash : " << i << "!=" << el << std::endl;
        el = table2.find(i);
        if (el != i) std::cout << "ERROR in perfhash_mshift : " << i << "!=" << el << std::endl;
    }

#ifdef EXTRA_VERBOSITY
    std::cout << "Done" << std::endl;
#endif
}

#endif
