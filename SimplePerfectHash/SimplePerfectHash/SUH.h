#pragma once

#include <vector>
#include <list>
#include <random>
#include <ctime>

using uint = unsigned int;

#ifndef SIMPLE_UNIVERSAL_HASH
#define SIMPLE_UNIVERSAL_HASH

class uhash
{
private:
    uint prime;
    uint alpha;
    uint betta;
    size_t table_size;
    std::vector<int> table;
    static std::mt19937 gen;
    static std::uniform_int_distribution<uint> random;
public:
    uhash(unsigned int table_size);
    uint hash(int key, int alpha, int betta);
    void rehash();
};

#endif // !SUH
