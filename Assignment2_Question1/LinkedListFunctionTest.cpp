#include "LinkedList.h"

int main() {

	LinkedList<int> list;

	list.listAppend(5);
	list.listAppend(6);
	
	std::cout << "Length of list: " << list.getLength() << std::endl;
	list.printList();

	list.listPrepend(1);
	list.listPrepend(2);
	
	std::cout << "Length of list: " << list.getLength() << std::endl;
	list.printList();

	//list.insertAfter(list.getHead()->getNextNode()->getNextNode(), 9);
	list.removeAfter(list.getHead());

	std::cout << "Length of list: " << list.getLength() << std::endl;
	list.printList();



	return 0;
}