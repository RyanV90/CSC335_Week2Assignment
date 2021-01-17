#include <iostream>
#include <vector>
#include <exception>
#include <list>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h> 
#include "LinkedList.h"
using namespace std;

const int TABLESIZE = 31;
const int NUMBEROFITEMS = 20;
int collisionCounter = 0;

template<typename T>
int hfun(T item)
{
	collisionCounter++;
	
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
		//++collisionCounter;
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
		collisionCounter++;
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
	vector<int> listOfRandomIntegers(20);
	
	srand(time(0));
	for (int i = 0; i < NUMBEROFITEMS; i++)
	{
		listOfRandomIntegers.at(i) = generateRandomNumber(100);
	}
	//sort(listOfRandomIntegers.begin(), listOfRandomIntegers.end());

	for (int i = 0; i < NUMBEROFITEMS; i++)
	{
		hashInsertLprobe(htablep, listOfRandomIntegers.at(i));
	}
	
	for (int i = 0; i < NUMBEROFITEMS; i++)
	{
		hashInsertQ(htableq, listOfRandomIntegers.at(i));
	}
	

	
	for (int number : listOfRandomIntegers)
	{
		cout << number << " ";
	}
	cout << endl;

	printHashTable(htablep);
	cout << "Collisons: " << collisionCounter << endl;
	printHashTable(htableq);
	cout << "Collisons: " << collisionCounter << endl;

	return 0;
}