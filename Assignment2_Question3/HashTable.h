#include <iostream>
#include <vector>
#include <exception>
#include <list>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>

using namespace std;

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

template<typename T>
inline HashTable<T>::HashTable()
{
	collisionCounter = 0;
	tableSize = 31;
	data = vector<int>(31, -1);
}

template<typename T>
inline int HashTable<T>::hashFunction(T item)
{
	return item % tableSize;
}

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

//template<typename T>
//inline bool HashTable<T>::hashInsertQ(T item)
//{
//	int i = 0;
//	int count = 0;
//	int totalCollisionCounter = 0;
//	int bucket = hashFunction(item);
//	int bucket1 = bucket;  // need a copy of the bucket (key)
//	while (count < tableSize)
//	{
//		if (data[bucket] == -1 || data[bucket] == -2)
//		{
//			data[bucket] = item;
//			return true;
//		}
//		i++;
//		bucket = (bucket1 + i + i * i) % tableSize;
//		count++;
//		totalCollisionCounter += count;
//		setCollisionCounter(totalCollisionCounter);
//	}
//	return false;
//}

template<typename T>
inline bool HashTable<T>::hashInsertQ(T item)
{
	int i = 0;
	int bucketsProbed = 0;

	int bucket = hashFunction(item);
	while (bucketsProbed < tableSize)
	{
		if (data[bucket] == -1 || data[bucket] == -2)
		{
			data[bucket] = item;
			return true;
		}

		i += 1;
		bucket = (hashFunction(item) + 1 * i + 1 * (int)pow(i, 2)) % tableSize;

		bucketsProbed += 1;

		setCollisionCounter(bucketsProbed);
	}
	return false;
}

template<typename T>
inline void HashTable<T>::printHashTable()
{
	for (int i = 0; i < tableSize; i++)
		cout << i << "---> " << data[i] << endl;
}

template<typename T>
inline int HashTable<T>::getCollisionCounter() const
{
	return collisionCounter;
}

template<typename T>
inline void HashTable<T>::setCollisionCounter(int value)
{
	this->collisionCounter = value;
}

template<typename T>
inline int HashTable<T>::getTableSize() const
{
	return tableSize;
}