#include "DoublyLinkedList.h"

int main() {

	DoublyLinkedList<int> list;

	list.listPrepend(1);
	list.listPrepend(3);
	list.listPrepend(5);
	list.listPrepend(7);

	list.printList();

	list.listAppend(2);
	list.listAppend(4);
	list.listAppend(6);
	list.listAppend(8);

	list.printList();

	return 0;
}