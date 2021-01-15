#include "LinkedList.h"

int main() {

	LinkedList<int> list;

	list.listAppend(5);
	list.listAppend(6);
	list.printList();

	list.listPrepend(1);
	list.listPrepend(2);
	list.printList();

	//list.insertAfter(list.getHead()->getNextNode()->getNextNode(), 9);
	list.removeAfter(list.getHead());

	list.printList();

	return 0;
}