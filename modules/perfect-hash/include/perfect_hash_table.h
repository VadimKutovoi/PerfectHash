// Copyright 2019 Kutovoi Vadim

#include <string>
#include <vector>

#include "include/universal_hash_table.h"

#ifndef MODULES_PERFECT_HASH_INCLUDE_PERFECT_HASH_TABLE_H_
#define MODULES_PERFECT_HASH_INCLUDE_PERFECT_HASH_TABLE_H_

class perfhash : public unihash {
 private:
    std::vector<unihash> main_table;
 public:
    explicit perfhash(ullong _table_size);

    void buildTable(std::vector<ullong> data);
};

#endif  // MODULES_PERFECT_HASH_INCLUDE_PERFECT_HASH_TABLE_H_
