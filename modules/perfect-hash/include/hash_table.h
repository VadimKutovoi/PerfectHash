// Copyright 2019 Kutovoi Vadim

#include <vector>
#include <random>
#include <ctime>

#ifndef MODULES_PERFECT_HASH_INCLUDE_HASH_TABLE_H_
#define MODULES_PERFECT_HASH_INCLUDE_HASH_TABLE_H_

class hashTable {
 public:
     using ullong = uint64_t;

     hashTable();
     explicit hashTable(ullong _table_size);

     virtual ullong hash(ullong key) { return ullong{}; }
     virtual void rehash() {}

     bool add(ullong item);
     bool remove(ullong item);

     ullong getCell(ullong cell_number);

     ullong find(ullong item);

     unsigned buildTable(std::vector<ullong> data);

 protected:
     std::vector<bool> is_in_table;
     std::vector<ullong> table;
     ullong table_size;
};

#endif  // MODULES_PERFECT_HASH_INCLUDE_HASH_TABLE_H_
