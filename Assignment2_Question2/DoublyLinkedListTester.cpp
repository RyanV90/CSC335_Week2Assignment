#include "DoublyLinkedList.h"

int main() {

	DoublyLinkedList<int> list;

	//Prepend some values to the list
	list.listPrepend(1);
	list.listPrepend(3);
	list.listPrepend(5);
	list.listPrepend(7);

	//Print the list
	list.printList();

	//Append some values to the list
	list.listAppend(2);
	list.listAppend(4);
	list.listAppend(6);
	list.listAppend(8);

	//Print the list
	list.printList();

	return 0;
}