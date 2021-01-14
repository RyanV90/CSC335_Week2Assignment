#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include "Node.h"

template<typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	Node<T>* getHead() const;  // return the head pointer.
	Node<T>* getTail() const;  // returns the tail pointer.
	void listAppend(Node<T>* newNode);
	void listPrepend(Node<T>* newNode);
	void printList() const;

private:
	Node<T>* head;
	Node<T>* tail;


};

#endif // !DOUBLYLINKEDLIST