#include "LinkedList.h"

int main() {

	LinkedList<int> list;

	//Append two values to list
	list.listAppend(5);
	list.listAppend(6);
	
	//Print length of list and print list
	std::cout << "Length of list: " << list.getLength() << std::endl;
	list.printList();

	//Prepend two values to list
	list.listPrepend(1);
	list.listPrepend(2);
	
	//Print length of list and print list
	std::cout << "Length of list: " << list.getLength() << std::endl;
	list.printList();

	//Removes the node after the head
	list.removeAfter(list.getHead());

	//Print length of list and print list
	std::cout << "Length of list: " << list.getLength() << std::endl;
	list.printList();

	//If the node data is found, insert a new node after it.
	if (list.listSearch(5))
	{
		list.insertAfter(list.listSearch(5), 7);
		std::cout << "Length of list: " << list.getLength() << std::endl;
		list.printList();
	}
	//If the node is not found, do not try to insert.
	else
	{
		std::cout << "The requested node was not found in the list." << std::endl;
	}

	return 0;
}