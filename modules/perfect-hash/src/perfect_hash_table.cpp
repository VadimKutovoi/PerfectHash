#include <vector>

#include "include/perfect_hash_table.h"

perfhash::perfhash(uint _table_size) : unihash(_table_size) {
    std::vector<unihash> tmp_table(_table_size);
    main_table = tmp_table;
}

inline void perfhash::buildTable(std::vector<int> data) {
    uint hash_result = 0;
    std::vector<std::vector<int>> prehash_table(data.size());

    for (uint i = 0; i < data.size(); i++) {
        hash_result = hash(data[i]);
        prehash_table[hash_result].push_back(data[i]);
    }

    for (uint i = 0; i < prehash_table.size(); i++) {
        if (prehash_table[i].size() > 0) {
            unihash secondLvlTable(prehash_table[i].size() *
                                   prehash_table[i].size());
            main_table[i] = secondLvlTable;

            main_table[i].buildTable(prehash_table[i]);
        }
    }
}

int perfhash::find(int key) {
    uint first_lvl_hash_result = hash(key);

    return main_table[first_lvl_hash_result].find(key);
}
