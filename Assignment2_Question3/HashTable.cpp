#include <iostream>
#include <vector>
#include <exception>
#include <list>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h> 
#include "LinkedList.h"
using namespace std;

const int TABLESIZE = 31;

template<typename T>
int hfun(T item)
{
	return item % TABLESIZE;  
}

template<typename T>
bool hashInsertLprobe(vector<T>& h, T item)
{
	int bucket = hfun(item);    //find the hash value of the key
	int count = 0;
	while (count < TABLESIZE)  // No need to probe more than number of buckets(cells) in the table
	{
		if (h[bucket] == -1 || h[bucket] == -2)  //if an empty cell
		{
			h[bucket] = item;
			return true;
		}
		++count;  // number of probes
		bucket = (bucket + 1) % TABLESIZE;  //next linear bucket
	}
	return false;
}

//hash insert, quadratic probing with c1 = 1 and c2 = 1
template<typename T>
bool hashInsertQ(vector<T>& h, T item)
{
	int i = 0;
	int count = 0;
	int bucket = hfun(item);
	int bucket1 = bucket;  // need a copy of the bucket (key)
	while (count < TABLESIZE)
	{
		if (h[bucket] == -1 || h[bucket] == -2)
		{
			h[bucket] = item;
			
			return true;
		}
		i++;
		bucket = (bucket1 + i + i * i) % TABLESIZE;
		count++;
	}
	return false;
}

// print function for hash table with probing 
template<typename T>
void printHashTable(vector<T>h)
{
	for (int i = 0; i < TABLESIZE; i++)
		cout << i << "---> " << h[i] << endl;
}

// Generates random integer from 0 to maxValue
int generateRandomNumber(int maxValue) {

	int randomNumber = rand() % maxValue + 1;

	return randomNumber;
}

int main()
{
	vector<int> htablep(TABLESIZE, -1);
	vector<int> htableq(TABLESIZE, -1); // initialize all table values = -1, empty since start
	LinkedList<int> listOfIntegers;
	
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		int integerToInsert = generateRandomNumber(100);
		listOfIntegers.listAppend(integerToInsert);
		hashInsertQ(htableq, integerToInsert);
		hashInsertLprobe(htablep, integerToInsert);
	}
	listOfIntegers.printList();
	printHashTable(htablep);

	printHashTable(htableq);

	return 0;
}