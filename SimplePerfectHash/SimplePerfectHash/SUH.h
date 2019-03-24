#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <iostream>

using uint = unsigned int;

#ifndef SIMPLE_UNIVERSAL_HASH
#define SIMPLE_UNIVERSAL_HASH

class unihash
{
private:
    uint prime = -1;
    uint alpha = -1;
    uint betta = -1;

    uint table_size;

    std::vector<bool> is_in_table;
    std::vector<int> table;

    static std::mt19937 gen;
    static std::uniform_int_distribution<uint> random;
public:
    unihash(uint _table_size);

    uint hash(int key);
    void rehash();

    uint add(int item);
    int find(int item);
    int getCell(int cell_number);
    void buildTable(std::vector<int> data);

    uint getAlpha() { return alpha; }
    uint getBetta() { return betta; }
    uint getSize() { return table_size; }

    std::mt19937 getGen() { return gen; }
    std::uniform_int_distribution<uint> getRandom() { return random; }

    void print();
};

unihash::unihash(uint _table_size = 0) {
    table_size = _table_size;
    table_size > 16 ? prime = 1198754321 : prime = 433494437;
    
    rehash();
}

std::mt19937 unihash::gen(time(0));
std::uniform_int_distribution<uint> unihash::random(0, UINT32_MAX);

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

uint unihash::add(int item)
{
    uint position = hash(item);
    if (is_in_table[position] == false) {
        table[position] = item;
        is_in_table[position] = true;
        return 0;
    }
    else
        return 1;
}

inline int unihash::getCell(int cell_number)
{
    return table.at(cell_number);
}

inline void unihash::buildTable(std::vector<int> data)
{
    uint i = 0, hash_result = 0;

    while (true) {
        hash_result = add(data[i]);
        i++;
        if (hash_result == 1) {
            std::cout << "Collision! Rehashing!" << std::endl;
            rehash();
            i = 0;
            hash_result = 0;
        }
        else if (i == data.size()) break;
    }
}
inline void unihash::print()
{
    std::cout << "-------" << std::endl;
    for (int i = 0; i < table_size; i++) {
        std::cout << i << " | " << getCell(i) << std::endl;
        std::cout << "-------" << std::endl;
    }
}
inline int unihash::find(int item)
{
    uint pos = hash(item);
    if (is_in_table[pos])
        return table[pos];
    else {
        std::cout << "ERROR:" << item << " not in table!" << std::endl;
        return 0;
    }
}
#endif // !SUH
