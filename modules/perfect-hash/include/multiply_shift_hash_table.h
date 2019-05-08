// Copyright 2019 Kutovoi Vadim

#include <vector>
#include <random>
#include <ctime>

#include "../include/hash_table.h"

#ifndef MODULES_PERFECT_HASH_INCLUDE_MULTIPLY_SHIFT_HASH_TABLE_H_
#define MODULES_PERFECT_HASH_INCLUDE_MULTIPLY_SHIFT_HASH_TABLE_H_

class mshifthash : public hashTable {
 private:
    ullong alpha = -1;
    ullong betta = -1;
    ullong table_size;
    ullong one = 1;

    size_t w;
    size_t M;

    static std::mt19937 gen;
    static std::uniform_int_distribution<ullong> random;

 public:
    explicit mshifthash(int64_t _table_size);

    ullong hash(int64_t key);
    void rehash();

    ullong getAlpha() { return alpha; }
    ullong getBetta() { return betta; }
    ullong getSize() { return table_size; }

    std::mt19937 getGen() { return gen; }
    std::uniform_int_distribution<ullong> getRandom() { return random; }
};

#endif  // MODULES_PERFECT_HASH_INCLUDE_MULTIPLY_SHIFT_HASH_TABLE_H_
