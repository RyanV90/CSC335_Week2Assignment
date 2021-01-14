#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	Node<T>* getHead() const;  // return the head pointer.
	Node<T>* getTail() const;  // returns the tail pointer.
	void listAppend(T value);
	void listPrepend(Node<T>* newNode);
	void printList() const;

private:
	Node<T>* head;
	Node<T>* tail;


};

#endif // !DOUBLYLINKEDLIST