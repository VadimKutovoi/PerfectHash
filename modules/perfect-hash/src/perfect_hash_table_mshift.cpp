// Copyright 2019 Kutovoi Vadim

#include <vector>
#include <iostream>

#include "../include/perfect_hash_table_mshift.h"

perfhash_mshift::perfhash_mshift(ullong _table_size) : mshifthash(_table_size) {
    std::vector<mshifthash> tmp_table(_table_size);
    main_table = tmp_table;
}

void perfhash_mshift::buildTable(std::vector<ullong> data) {
    ullong hash_result = 0;
    std::vector<std::vector<ullong>> prehash_table(data.size());

    for (auto i : data) {
        hash_result = hash(i);
        prehash_table[hash_result].push_back(i);
    }

    unsigned pos = 0;
    for (auto i : prehash_table) {
        if (i.size() > 0) {
            mshifthash secondLvlTable(i.size() *
                                   i.size());
            main_table[pos] = secondLvlTable;

            main_table[pos].buildTable(i);
        }
        pos++;
    }
}

mshifthash::ullong perfhash_mshift::find(ullong item)
{
    ullong first_lvl_position = hash(item);

    return main_table[first_lvl_position].find(item);
}
