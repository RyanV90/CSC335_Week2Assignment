#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST
#include "Node.h"
#include <iostream>

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

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
inline Node<T>* DoublyLinkedList<T>::getHead() const
{
	return this->head;
}

template<typename T>
inline void DoublyLinkedList<T>::setHead(Node<T>* head)
{
	this->head = head;
}

template<typename T>
inline Node<T>* DoublyLinkedList<T>::getTail() const
{
	return this->tail;
}

template<typename T>
inline void DoublyLinkedList<T>::setTail(Node<T>* tail)
{
	this->tail = tail;
}

template<typename T>
inline void DoublyLinkedList<T>::listAppend(T nodeData)
{
	Node<T>* newNode = new Node<T>(nodeData, nullptr, nullptr);

	if (this->head == nullptr)
	{
		this->head = this->tail = newNode;
	}
	else
	{
		this->tail->setNextNode(newNode);
		newNode->setPrevNode(this->tail);
		this->tail = newNode;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::listPrepend(T nodeData)
{
	Node<T>* newNode = new Node<T>(nodeData, nullptr, nullptr);
	
	if (this->head == nullptr)
	{
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		newNode->setNextNode(this->head);
		this->head->setPrevNode(newNode);
		this->head = newNode;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::printList() const
{
	Node<T>* tempNode = this->head;
	
	while (tempNode != nullptr)
	{
		std::cout << tempNode->getNodeData() << " ";
		tempNode = tempNode->getNextNode();
	}
	std::cout << "\n";
}
