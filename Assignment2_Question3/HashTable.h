#include <iostream>
#include <vector>
#include <exception>
#include <list>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Creates a hash table object which can insert values by linear and quadratic probing
template<typename T>
class HashTable {

public:
	HashTable();
	int hashFunction(T item);
	bool hashInsertLprobe(T item);
	bool hashInsertQ(T item);
	void printHashTable();
	int getCollisionCounter() const;
	void setCollisionCounter(int value);
	int getTableSize() const;

private:
	int collisionCounter;
	int tableSize;
	vector<T> data;
};

//Initializes a hash table of size 31 and a vector to store 31 items
template<typename T>
inline HashTable<T>::HashTable()
{
	collisionCounter = 0;
	tableSize = 31;
	data = vector<int>(31, -1);
}

//Base hash function
template<typename T>
inline int HashTable<T>::hashFunction(T item)
{
	return item % tableSize;
}

//Inserts a value to the hash table by linear probing
template<typename T>
inline bool HashTable<T>::hashInsertLprobe(T item)
{
	int bucket = hashFunction(item);    //find the hash value of the key
	int count = 0;
	int totalCollisionCounter = 0;
	while (count < tableSize)  // No need to probe more than number of buckets(cells) in the table
	{
		if (data[bucket] == -1 || data[bucket] == -2)  //if an empty cell
		{
			data[bucket] = item;
			return true;
		}
		++count;  // number of probes
		totalCollisionCounter += count;
		setCollisionCounter(count);
		bucket = (bucket + 1) % tableSize;  //next linear bucket
	}
	return false;
}

//Inserts a value to the hash table by quadratic probing 
template<typename T>
inline bool HashTable<T>::hashInsertQ(T item)
{
	int i = 0;
	int bucketsProbed = 0;

	int bucket = hashFunction(item);
	
	//If collision is met, i will increment until it reaches the size of the table
	while (i < tableSize)
	{
		//If the bucket is empty, then the item is inserted (no collision)
		if (data[bucket] == -1 || data[bucket] == -2)
		{
			data[bucket] = item;
			return true;
		}

		i += 1;
		bucket = (hashFunction(item) + 1 * i + 1 * (int)pow(i, 2)) % tableSize; //Calculation for collision
		bucketsProbed += 1; //counts the total number of collisions

		setCollisionCounter(bucketsProbed); 
	}
	return false;
}

//Prints the hash table
template<typename T>
inline void HashTable<T>::printHashTable()
{
	for (int i = 0; i < tableSize; i++)
		cout << i << "---> " << data[i] << endl;
}

//Returns the total number of collisions after insertion
template<typename T>
inline int HashTable<T>::getCollisionCounter() const
{
	return collisionCounter;
}

//Sets the total number of collisions during insertion
template<typename T>
inline void HashTable<T>::setCollisionCounter(int value)
{
	this->collisionCounter = value;
}

//Returns the size of the hash table
template<typename T>
inline int HashTable<T>::getTableSize() const
{
	return tableSize;
}