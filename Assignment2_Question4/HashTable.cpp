#include <iostream>
#include <vector>
#include <exception>
#include <list>
#include "LinkedList.h"
using namespace std;

//===================================== Hash related functions ================
const int TABLESIZE = 10;
//hash function defined as modulo operator
//receive an item and return bucket key (index)
template<typename T>
int hfun(T item)
{
	return item % TABLESIZE;  //
}

//insert an item in the hash table
//Collision resolution by chanining
template<typename T>
void hashInsertChaining(vector<LinkedList<T> >& h, T item)
{
	h[hfun(item)].listAppend(item);
}

template<typename T>
void hashRemoveChaining(vector <LinkedList<T>>& h, T item)
{
	int key = hfun(item);
	if (h[key].getHead()->data == item)
		h[key].removeHead();
	else if ((h[key].getTail()->data == item))
		h[key].removeTail();
	else
	{
		Node<T>* temp = h[key].getHead();
		while (temp->next != NULL) {
			if (temp->next->data == item)
			{
				h[key].removeAfter(temp);
				break;
			}
			else
				temp = temp->next;
		}

	}
}



//Display all elements of the hash table, Collision resolution by chaining
template<typename T>
void printHash(const vector<LinkedList<T>>& h)
{
	for (int i = 0; i < h.size(); i++) // goes through each bucket and prints the linked list there
	{
		cout << i << "---> ";
		h[i].printList();
	}
}

//insert an item in the hash table
//Collision resolution by Linear Probing
// bucket value of -1 means empty since start
//bucket value of -2 means empty after removal
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

//remove item from hash table
//Linear probing
// bucket value of -1 means empty since start
//bucket value of -2 means empty after removal
template<typename T>
bool hashRemoveL(vector<T>& h, T item)
{
	int bucket = hfun(item);  // calculate the key
	int count = 0;
	while (h[bucket] != -1 && count < TABLESIZE) // cell not empty since start
	{
		if (h[bucket] == item)  // found the item
		{
			h[bucket] = -2;  // mark cell as empty after removal
			return true;
		}
		bucket = (bucket + 1) % TABLESIZE; // next bucket
		count++;
	}
	return false;
}
//hash search, linear probing
// functions 
template<typename T>
int hashSearchL(vector<T>& h, T item)
{
	int bucket = hfun(item);
	int count = 0;
	while (h[bucket] != -1 && count < TABLESIZE)
	{
		if (h[bucket] == item)
			return bucket;
		++count;
		bucket = (bucket + 1) % TABLESIZE;
	}
	return -1;
}

// print function for hash table with probing 
template<typename T>
void printHashTable(vector<T>h)
{
	for (int i = 0; i < TABLESIZE; i++)
		cout << i << "---> " << h[i] << endl;

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

//hash Search Quadratic probing
template<typename T>
int hashSearchQ(vector<T> h, T item)
{
	int i = 0;
	int count = 0;
	int bucket = hfun(item);
	int bucket1 = bucket;
	while (h[bucket] != -1 && count < TABLESIZE)
	{
		if (h[bucket] == item)
			return bucket;
		i++;
		bucket = (bucket1 + i + i * i) % TABLESIZE;
		count++;
	}
	return -1;
}

//hash remove, quadratic probing
template<typename T>
bool hashRemoveQ(vector<T>& h, T key)
{
	int bucket = hashSearchQ(h, key);
	if (bucket != -1)
	{
		h[bucket] = -2;
		return true;
	}
	return false;
}




int main()
{

	return 0;
}