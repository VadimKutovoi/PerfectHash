// Copyright 2019 Kutovoi Vadim

#include <vector>

#include "../include/universal_hash_table.h"

std::mt19937 unihash::gen(time(0));
std::uniform_int_distribution<hashTable::ullong> unihash::random(0, UINT32_MAX);

unihash::unihash() {
    table_size = 0;
    table_size > 16 ? prime = 1198754321 : prime = 433494437;
    rehash();
}

unihash::unihash(hashTable::ullong _table_size = 0) {
    table_size = _table_size;
    table_size > 16 ? prime = 1198754321 : prime = 433494437;
    rehash();
}

hashTable::ullong unihash::hash(int64_t key) {
    if (alpha == 0 || betta == 0) rehash();
    if (table_size == 1) return 0;
    return (alpha * key + betta) % prime % table_size;
}

void unihash::rehash() {
    alpha = random(gen) % (prime - 1);
    if (alpha == 0) ++alpha;
    betta = random(gen) % (prime - 1);

    std::vector<bool> tmp_vec(table_size, false);
    is_in_table = tmp_vec;

    std::vector<int64_t> tmp_table(table_size, 0);
    table = tmp_table;
}
