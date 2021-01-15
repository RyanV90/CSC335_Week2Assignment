#include "LinkedList.h"

int main() {

	LinkedList<int> list;

	list.listAppend(5);
	list.listAppend(6);
	list.printList();

	list.listPrepend(1);
	list.listPrepend(2);
	list.printList();
	return 0;
}