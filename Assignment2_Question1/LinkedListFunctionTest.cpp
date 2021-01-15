#include "LinkedList.h"

int main() {

	LinkedList<int> list;

	list.listAppend(5);
	list.listAppend(6);
	list.printList();
	list.printList();
	return 0;
}