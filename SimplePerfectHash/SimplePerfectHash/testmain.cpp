#include "universal_hash_table.h"
#include "perfect_hash_table.h"
#include "multiply_shift_hash_table.h"
#include <iostream>
#include <set>
#include <chrono>
#include <map>

#define HASH_TABLE_SIZE  10000
#define DATA_VECTOR_SIZE 300

int main() {
    uint err_count = 0;
    std::vector<int> gen_data;
    std::vector<int> test_data;
    
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> rand(1, INT_MAX);

    for (int i = 0; i < DATA_VECTOR_SIZE; ++i)
        gen_data.push_back(rand(gen));

    std::set<int> data_set(gen_data.begin(), gen_data.end());
    std::set<int>::iterator it;

    for (it = data_set.begin(); it != data_set.end(); ++it) {
        test_data.push_back(*it);
    }

   /* auto start_time_map = std::chrono::high_resolution_clock::now();
    std::map<int, int> test_map(test_data.begin(), test_data.end());
    auto end_time_map = std::chrono::high_resolution_clock::now();
    auto time_map = end_time_map - start_time_map;
    std::cout << "Map time : " << time_map / std::chrono::milliseconds(1) << std::endl;*/
    
   // MULTIPLY SHIFT HASH TESTING
    
    mshifthash msh(HASH_TABLE_SIZE);

    std::cout << "MULTIPLY SHIFT HASHING..." << std::endl;

    msh.buildTable(test_data);

    std::cout << "    Comparing results..." << std::endl;

    for (int i = 0; i < DATA_VECTOR_SIZE; ++i) {
        int item = msh.find(test_data[i]);
        if (test_data[i] != item) {
            std::cout << "    Error! Element " << test_data[i] << " not in table!" << std::endl;
            err_count++;
        }
    }

    if (err_count == 0) std::cout << "    No errors" << std::endl;
    else std::cout << "    Hashing failed with " << err_count << " errors!" << std::endl;

   // UNIVERSAL HASH TESTING

    mshifthash uh(HASH_TABLE_SIZE);

    std::cout << "UNIVERSAL HASHING..." << std::endl;

    uh.buildTable(test_data);

    std::cout << "    Comparing unihash results..." << std::endl;

    for (int i = 0; i < DATA_VECTOR_SIZE; ++i) {
        int item = uh.find(test_data[i]);
        if (test_data[i] != item) {
            std::cout << "    Error! Element " << test_data[i] << " not in table!" << std::endl;
            err_count++;
        }
    }

    if (err_count == 0) std::cout << "    No errors" << std::endl;
    else std::cout << "    Hashing failed with " << err_count << " errors!" << std::endl;



    //PERFECT HASH TESTING
    
    perfhash ph(test_data.size());

    std::cout << "PERFECT HASHING..." << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();
    ph.buildTable(test_data);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    std::cout << "    Time : " << time / std::chrono::milliseconds(1) << std::endl;
    std::cout << "    Comparing perfhash results..." << std::endl;

    err_count = 0;
    for (int i = 0; i < test_data.size(); ++i) {
        int item = ph.find(test_data[i]);
        if (test_data[i] != item) {
            std::cout << "    Error! Element " << test_data[i] << " not in table!" << std::endl;
        }
    }

    if (err_count == 0) std::cout << "    No errors" << std::endl;
    else std::cout << "Hashing failed with " << err_count << " errors!" << std::endl;
}