#include <string>
#include <vector>

#include "include/universal_hash_table.h"

#ifndef MODULES_PERFECT_HASH_INCLUDE_PERFECT_HASH_TABLE_H_
#define MODULES_PERFECT_HASH_INCLUDE_PERFECT_HASH_TABLE_H_

class perfhash : public unihash {
 private:
    std::vector<unihash> main_table;
 public:
    perfhash(uint _table_size);

    void buildTable(std::vector<int> data);
    int find(int key);
};

#endif  // MODULES_PERFECT_HASH_INCLUDE_PERFECT_HASH_TABLE_H_
