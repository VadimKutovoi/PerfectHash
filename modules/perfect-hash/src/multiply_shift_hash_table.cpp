#include <vector>
#include <climits>

#include "include/multiply_shift_hash_table.h"


std::mt19937 mshifthash::gen(time(0));
std::uniform_int_distribution<ullong> mshifthash::random(0, ULLONG_MAX);

mshifthash::mshifthash(uint _table_size = 0) :
    table_size(_table_size), w(64), one(1), M(std::log2(table_size)) {
        rehash();
}

size_t mshifthash::hash(int key) {
    if (M == 0) return 0;
    return (alpha * key + betta) >> (w - M);
}

void mshifthash::rehash() {
    alpha = random(gen) % (one << (w - 1));
    if ((alpha % 2) == 0) ++alpha;
    betta = random(gen) % (one << (w - M - 1));

    std::vector<bool> tmp_vec(table_size, false);
    is_in_table = tmp_vec;

    std::vector<int> tmp_table(table_size, 0);
    table = tmp_table;
}

uint mshifthash::add(int item) {
    uint position = hash(item);
    if (!is_in_table[position]) {
        table[position] = item;
        is_in_table[position] = true;
        return 0;
    } else {
        return 1;
    }
}

inline int mshifthash::getCell(int cell_number) {
    return table.at(cell_number);
}

inline void mshifthash::buildTable(std::vector<int> data) {
    uint i = 0, hash_result = 0;

    while (true) {
        hash_result = add(data[i]);
        i++;
        if (hash_result == 1) {
            rehash();
            i = 0;
            hash_result = 0;
        } else if (i == data.size()) {
            break;
        }
    }
}

inline int mshifthash::find(int item) {
    uint pos = hash(item);
    if (is_in_table[pos]) {
        return table[pos];
    } else {
        std::cout << "ERROR:" << item << " not in table!" << std::endl;
        return -1;
    }
}