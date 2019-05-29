// Copyright 2019 Kutovoi Vadim

#include <string>
#include <vector>

#include "include/multiply_shift_hash_table.h"

#ifndef MODULES_PERFECT_HASH_INCLUDE_PERFECT_HASH_TABLE_MSHIFT_H_
#define MODULES_PERFECT_HASH_INCLUDE_PERFECT_HASH_TABLE_MSHIFT_H_

class perfhash_mshift : public mshifthash {
 private:
    std::vector<mshifthash> main_table;
 public:
    explicit perfhash_mshift(ullong _table_size);

    void buildTable(std::vector<ullong> data);
    ullong find(ullong item);
};

#endif  // MODULES_PERFECT_HASH_INCLUDE_PERFECT_HASH_TABLE_MSHIFT_H_
