#pragma once
#include "HashTable.h"
class QuadraticProbingHashTable :
    public HashTable
{
public:
    QuadraticProbingHashTable();
    void hashInsert(int item);
    int hashSearch(int key);
};

