#include "HashTable.h"

//Generates random integer from 0 to maxValue
int generateRandomNumber(int maxValue) {

	int randomNumber = rand() % maxValue + 1;

	return randomNumber;
}

int main() {
	
	int integerListSize = 20; //Size of the list of integers being inserted into hash table

	vector<int> listOfRandomIntegers(integerListSize, 0); //List of integers being inserted into hash table
	HashTable<int> linearProbingHashTable; //Hash table to hash by linear probing
	HashTable<int> quadraticProbingHashTable; //Hash table to hash by quadratic probing

	srand(time(0));
	//Generate list of random integers from 0 to 100 of integerListSize;
	for (int i = 0; i < integerListSize; i++)
	{
		listOfRandomIntegers.at(i) = generateRandomNumber(100);
	}

	//Inserts list of integers into a hash table using linear probing.
	for (int i = 0; i < integerListSize; i++)
	{
		linearProbingHashTable.hashInsertLprobe(listOfRandomIntegers.at(i));
	}

	//Inserts list of integers into a hash table using quadratic probing.
	for (int i = 0; i < integerListSize; i++)
	{
		quadraticProbingHashTable.hashInsertQ(listOfRandomIntegers.at(i));
	}

	//Prints the list of integers being inserting into hash tables
	cout << "Number List: ";
	for (int number : listOfRandomIntegers)
	{
		cout << number << " ";
	}
	cout << endl;

	//Print the table size, number of values, total number of collisions, and final hash table of linear probing hash
	cout << "\nHash table inserting by linear probing" << "\nTable Size: " << linearProbingHashTable.getTableSize() << 
		"\nNumber of values being inserted: " << integerListSize << "\nTotal number of collisions: " << linearProbingHashTable.getCollisionCounter() << endl;
	linearProbingHashTable.printHashTable();
	
	//Prints the list of integers being inserting into hash tables
	cout << "\nNumber List: ";
	for (int number : listOfRandomIntegers)
	{
		cout << number << " ";
	}
	cout << endl;
	
	//Print the table size, number of values, total number of collisions, and final hash table of quadratic probing hash
	cout << "\nHash table inserting by linear probing" << "\nTable Size: " << quadraticProbingHashTable.getTableSize() <<
		"\nNumber of values being inserted: " << integerListSize << "\nTotal number of collisions: " << quadraticProbingHashTable.getCollisionCounter() << endl;
	quadraticProbingHashTable.printHashTable();

	return 0;
}