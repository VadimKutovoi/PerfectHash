#include <vector>

#include "include/universal_hash_table.h"


std::mt19937 unihash::gen(time(0));
std::uniform_int_distribution<uint> unihash::random(0, UINT32_MAX);

unihash::unihash() {
    table_size = 1;
    table_size > 16 ? prime = 1198754321 : prime = 433494437;
    rehash();
}

unihash::unihash(uint _table_size = 0) {
    table_size = _table_size;
    table_size > 16 ? prime = 1198754321 : prime = 433494437;
    rehash();
}

uint unihash::hash(int key) {
    if (alpha == -1 || betta == -1) rehash();
    if (table_size == 1) return 0;
    return (alpha * key + betta) % prime % table_size;
}

void unihash::rehash() {
    alpha = random(gen) % (prime - 1);
    if (alpha == 0) ++alpha;
    betta = random(gen) % (prime - 1);

    std::vector<bool> tmp_vec(table_size, false);
    is_in_table = tmp_vec;

    std::vector<int> tmp_table(table_size, 0);
    table = tmp_table;
}

uint unihash::add(int item) {
    uint position = hash(item);
    if (!is_in_table[position]) {
        table[position] = item;
        is_in_table[position] = true;
        return 0;
    } else {
        return 1;
    }
}

inline int unihash::getCell(int cell_number) {
    return table.at(cell_number);
}

inline void unihash::buildTable(std::vector<int> data) {
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

inline int unihash::find(int item) {
    uint pos = hash(item);
    if (is_in_table[pos]) {
        return table[pos];
    } else {
        std::cout << "ERROR:" << item << " not in table!" << std::endl;
        return -1;
    }
}
