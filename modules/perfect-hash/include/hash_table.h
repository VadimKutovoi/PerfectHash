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

     virtual ullong hash(int64_t key) { return ullong{}; }
     virtual void rehash() {}

     bool add(int64_t item);
     bool remove(int64_t item);

     ullong getCell(int64_t cell_number);

     int64_t find(int64_t item);

     unsigned buildTable(std::vector<int64_t> data);

 protected:
     std::vector<bool> is_in_table;
     std::vector<int64_t> table;
     ullong table_size;
};

#endif  // MODULES_PERFECT_HASH_INCLUDE_HASH_TABLE_H_
