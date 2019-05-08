// Copyright 2019 Kutovoi Vadim

#include <vector>
#include <random>
#include <ctime>

#include "include/hash_table.h"

hashTable::hashTable()
{
    table_size = 0;
}

hashTable::hashTable(ullong _table_size)
{
    table_size = _table_size;
    std::vector<int64_t> tmp(table_size);
    table = tmp;
}

bool hashTable::add(int64_t item)
{
    hashTable::ullong position = hash(item);
    if (!is_in_table[position]) {
        table[position] = item;
        is_in_table[position] = true;
        return true;
    } else {
        return false;
    }
}

bool hashTable::remove(int64_t item)
{
    hashTable::ullong pos = hash(item);
    if (is_in_table[pos] && table[pos] == item) {
        is_in_table[pos] = false;
        return true;
    } else {
        return false;
    }
}

hashTable::ullong hashTable::getCell(int64_t cell_number)
{
    return table.at(cell_number);
}

int64_t hashTable::find(int64_t item)
{
    hashTable::ullong pos = hash(item);
    if (is_in_table[pos]) {
        return table[pos];
    } else {
        return -1;  // ERROR: not in table!
    }
}

unsigned hashTable::buildTable(std::vector<int64_t> data)
{
    unsigned i = 0, retries = 0;

    while (true) {
        bool hash_result = add(data[i]);
        i++;
        if (!hash_result) {
            rehash();
            i = 0;
            hash_result = false;
            retries++;
            continue;
        } else if (i == data.size()) {
            break;
        }
    }
    return retries;
}
