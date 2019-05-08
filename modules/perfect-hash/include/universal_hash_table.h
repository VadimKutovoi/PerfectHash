// Copyright 2019 Kutovoi Vadim

#include <vector>
#include <list>
#include <random>
#include <ctime>

#include "../include/hash_table.h"


#ifndef MODULES_PERFECT_HASH_INCLUDE_UNIVERSAL_HASH_TABLE_H_
#define MODULES_PERFECT_HASH_INCLUDE_UNIVERSAL_HASH_TABLE_H_

class unihash : public hashTable {
 public:
    unihash();
    explicit unihash(hashTable::ullong _table_size);

    ullong getAlpha() { return alpha; }
    ullong getBetta() { return betta; }

    hashTable::ullong hash(int64_t key);
    void rehash();

    std::mt19937 getGen() { return gen; }
    std::uniform_int_distribution<ullong> getRandom() { return random; }

private:
    ullong prime = 0;
    ullong alpha = 0;
    ullong betta = 0;

    static std::mt19937 gen;
    static std::uniform_int_distribution<ullong> random;
};

#endif  // MODULES_PERFECT_HASH_INCLUDE_UNIVERSAL_HASH_TABLE_H_
