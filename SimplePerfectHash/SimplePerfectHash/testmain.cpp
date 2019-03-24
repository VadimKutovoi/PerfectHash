#include "SUH.h"
#include "SPH.h"
#include <iostream>
#include <chrono>

#define HASH_TABLE_SIZE  1000000
#define DATA_VECTOR_SIZE 10000000

int main() {
    uint err_count = 0;

    // UNIVERSAL HASH TESTING

    std::vector<int> test_data;
    unihash uh(HASH_TABLE_SIZE);

    for (int i = 0; i < DATA_VECTOR_SIZE; ++i)
        test_data.push_back(i);
    

    //std::cout << "Unihashing..." << std::endl;

    //uh.buildTable(test_data);

    //std::cout << "Comparing unihash results..." << std::endl;

    //

    //for (int i = 0; i < DATA_VECTOR_SIZE; ++i) {
    //    int item = uh.find(test_data[i]);
    //    if (test_data[i] != item) {
    //        std::cout << "Error! Element " << test_data[i] << " not in table!" << std::endl;
    //        err_count++;
    //    }
    //}

    //if (err_count == 0) std::cout << "No errors" << std::endl;
    //else std::cout << "Hashing failed with " << err_count << " errors!" << std::endl;

    //PERFECT HASH TESTING
    
    perfhash ph(test_data.size());

    std::cout << "Perfhashing..." << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();
    ph.buildTable(test_data);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    std::cout << "Time : " << time / std::chrono::milliseconds(1) << std::endl;
    std::cout << "Comparing perfhash results..." << std::endl;

    err_count = 0;
    for (int i = 0; i < DATA_VECTOR_SIZE; ++i) {
        int item = ph.find(test_data[i]);
        if (test_data[i] != item) {
            std::cout << "Error! Element " << test_data[i] << " not in table!" << std::endl;
        }
    }

    if (err_count == 0) std::cout << "No errors" << std::endl;
    else std::cout << "Hashing failed with " << err_count << " errors!" << std::endl;
}