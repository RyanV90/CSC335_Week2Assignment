#include "HashTable.h"
#include <algorithm>

// Generates random integer from 0 to maxValue
int generateRandomNumber(int maxValue) {

	int randomNumber = rand() % maxValue + 1;

	return randomNumber;
}

int main() {
	int listSize = 20;

	//vector<int> vect(31, -1);
	vector<int> listOfRandomIntegers(listSize, 0);
	HashTable<int> table1;
	HashTable<int> table2;

	srand(time(0));
	for (int i = 0; i < listSize; i++)
	{
		listOfRandomIntegers.at(i) = generateRandomNumber(100);
	}
	sort(listOfRandomIntegers.begin(), listOfRandomIntegers.end());

	for (int i = 0; i < listSize; i++)
	{
		table1.hashInsertLprobe(listOfRandomIntegers.at(i));
	}

	for (int i = 0; i < listSize; i++)
	{
		table2.hashInsertQ(listOfRandomIntegers.at(i));
	}

	for (int number : listOfRandomIntegers)
	{
		cout << number << ", ";
	}
	cout << endl;

	table1.printHashTable();
	cout << "Collisons: " << table1.getCollisionCounter() << endl;
	table2.printHashTable();
	cout << "Collisons: " << table2.getCollisionCounter() << endl;

	return 0;
}