#include "SUH.h"

#ifndef SIMPLE_PERFECT_HASH
#define SIMPLE_PERFECT_HASH

class perfhash : public unihash
{
private:
    std::vector<unihash> main_table;
public:
    perfhash(uint _table_size);

    uint buildTable(std::vector<int> data);
};

perfhash::perfhash(uint _table_size) : unihash(_table_size) {
    std::vector<unihash> tmp_table(_table_size);
    main_table = tmp_table;
}

inline uint perfhash::buildTable(std::vector<int> data)
{
    uint hash_result = 0;
    std::vector<std::vector<int>> prehash_table(data.size());

    for (int i = 0; i < data.size(); i++) {
        hash_result = hash(data[i]);
        prehash_table[hash_result].push_back(data[i]);
    }

    for (int i = 0; i < prehash_table.size(); i++) {
        unihash secondLvlTable(prehash_table[i].size() * prehash_table[i].size());
        main_table[i] = secondLvlTable;
        
        for (int j = 0; j < prehash_table[i].size(); j++) {
            main_table[i].add(prehash_table[i][j]);
        }
    }
    return uint();
}

#endif