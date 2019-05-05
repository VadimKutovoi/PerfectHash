#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <iostream>

using uint = unsigned int;
using ullong = uint64_t;

#ifndef MODULES_PERFECT_HASH_INCLUDE_MULTIPLY_SHIFT_HASH_TABLE_H_
#define MODULES_PERFECT_HASH_INCLUDE_MULTIPLY_SHIFT_HASH_TABLE_H_

class mshifthash {
 private:
    ullong alpha = -1;
    ullong betta = -1;
    ullong table_size;
    ullong one = 1;

    size_t w;
    size_t M;

    std::vector<bool> is_in_table;
    std::vector<int> table;

    static std::mt19937 gen;
    static std::uniform_int_distribution<ullong> random;

 public:
    explicit mshifthash(uint _table_size);

    size_t hash(int key);
    void rehash();

    uint add(int item);
    int find(int item);
    int getCell(int cell_number);
    void buildTable(std::vector<int> data);

    uint getAlpha() { return alpha; }
    uint getBetta() { return betta; }
    uint getSize() { return table_size; }

    std::mt19937 getGen() { return gen; }
    std::uniform_int_distribution<ullong> getRandom() { return random; }
};

#endif  // MODULES_PERFECT_HASH_INCLUDE_MULTIPLY_SHIFT_HASH_TABLE_H_
