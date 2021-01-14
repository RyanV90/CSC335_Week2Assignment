#include "DoublyLinkedList.h"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::getHead() const
{
	return this->head;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::getTail() const
{
	return this->tail;
}

template<typename T>
void DoublyLinkedList<T>::listAppend(Node<T>* newNode)
{
	if (this->head == nullptr)
	{
		list->head = newNode;
		list->tail = newNode;
	}
	else
	{
		this->tail->next = newNode;
		newNode->prev = this->tail;
		this->tail = newNode;
	}
}

template<typename T>
void DoublyLinkedList<T>::listPrepend(Node<T>* newNode)
{
	if (this->head == nullptr)
	{
		list->head = newNode;
		list->tail = newNode;
	}
	else
	{
		newNode->next = list->head;
		this->head->prev = newNode;
		this->head = newNode;
	}
}

template<typename T>
void DoublyLinkedList<T>::printList() const
{
	Node<T> curNode = this->head;

	while(curNode != nullptr)
	{
		cout << curNode;
		curNode = curNode->next;
	}
}
