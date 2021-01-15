#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <iostream>
//#include <list>
//#include <vector>

template<typename T>
class LinkedList {

public:
	LinkedList();
	Node<T>* getHead() const;
	void setHead(Node<T>* head);
	Node<T>* getTail() const;
	void setTail(Node<T>* tail);
	void listAppend(T nodeData);
	void listPrepend(T nodeData);
	void insertAfter(Node<T>* curNode, T nodeData);
	void removeAfter(Node<T>* curNode); 
	void removeHead();  
	void removeTail();   
	void printList() const; 
	int getLength() const;
	Node<T>* listSearch(T key);
private:
	Node<T>* head;
	Node<T>* tail;
};

#endif // !LINKEDLIST