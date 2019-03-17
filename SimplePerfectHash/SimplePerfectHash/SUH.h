#pragma once

#include <vector>
#include <list>
#include <random>
#include <ctime>

using uint = unsigned int;

#ifndef SIMPLE_UNIVERSAL_HASH
#define SIMPLE_UNIVERSAL_HASH

class unihash
{
private:
    uint prime = -1;
    uint alpha = -1;
    uint betta;
    uint table_size;
    static std::mt19937 gen;
    static std::uniform_int_distribution<uint> random;
public:
    unihash(uint _table_size);
    uint hash(int key);
    void rehash();
    uint add();
};

unihash::unihash(uint _table_size) {
    table_size = _table_size;
    table_size > 16 ? prime = 1198754321 : prime = 433494437;
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
    betta = random(gen) % (betta - 1);
}

#endif // !SUH
