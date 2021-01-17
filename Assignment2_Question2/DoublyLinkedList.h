#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST
#include "Node.h"
#include <iostream>

//Creates a doubly linked list object which uses nodes to store data
template<typename T>
class DoublyLinkedList
{
public: 
	DoublyLinkedList();
	Node<T>* getHead() const;
	void setHead(Node<T>* head);
	Node<T>* getTail() const;
	void setTail(Node<T>* tail);
	void listAppend(T nodeData);
	void listPrepend(T nodeData);
	void printList() const;

private:
	Node<T>* head;
	Node<T>* tail;
};

#endif // !DOUBLYLINKEDLIST

//Creates an empty linked list
template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

//Returns the head of the linked list
template<typename T>
inline Node<T>* DoublyLinkedList<T>::getHead() const
{
	return this->head;
}

//Sets a new head of the linked list
template<typename T>
inline void DoublyLinkedList<T>::setHead(Node<T>* head)
{
	this->head = head;
}

//Returns the tail of the linked list
template<typename T>
inline Node<T>* DoublyLinkedList<T>::getTail() const
{
	return this->tail;
}

//Sets a new tail of the linked list
template<typename T>
inline void DoublyLinkedList<T>::setTail(Node<T>* tail)
{
	this->tail = tail;
}

//Places a new node with data to the end of the linked list
template<typename T>
inline void DoublyLinkedList<T>::listAppend(T nodeData)
{
	Node<T>* newNode = new Node<T>(nodeData, nullptr, nullptr);

	//If the list is empty, set head and tail to new node
	if (this->head == nullptr)
	{
		this->head = this->tail = newNode;
	}
	//If the list contains nodes, add new node to end of list
	else
	{
		this->tail->setNextNode(newNode);
		newNode->setPrevNode(this->tail);
		this->tail = newNode;
	}
}

//Places a new node with data to the beginning of the linked list
template<typename T>
inline void DoublyLinkedList<T>::listPrepend(T nodeData)
{
	Node<T>* newNode = new Node<T>(nodeData, nullptr, nullptr);
	
	//If the list is empty, set head and tail to new node
	if (this->head == nullptr)
	{
		this->head = newNode;
		this->tail = newNode;
	}
	//If the list contains nodes, add new node to beginning of list
	else
	{
		newNode->setNextNode(this->head);
		this->head->setPrevNode(newNode);
		this->head = newNode;
	}
}

//Prints the data of each node in the linked list
template<typename T>
inline void DoublyLinkedList<T>::printList() const
{
	Node<T>* tempNode = this->head;
	
	//While not at end of list
	while (tempNode != nullptr)
	{
		std::cout << tempNode->getNodeData() << " ";
		tempNode = tempNode->getNextNode();
	}
	std::cout << "\n";
}