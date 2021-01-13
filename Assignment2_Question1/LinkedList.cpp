#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template<typename T>
Node<T>* LinkedList<T>::getHead() const
{
	return this->head;
}

template<typename T>
Node<T>* LinkedList<T>::getTail() const
{
	return this->tail;
}

template<typename T>
void LinkedList<T>::listAppend(T value)
{
	if (this->head == nullptr)
	{
		this->head = value;
		this->tail = value;
	}
	else
	{
		this->tail->next = value;
		this->tail = value;
	}
}

template<typename T>
void LinkedList<T>::listPrepend(T value)
{
	if (this->head == nullptr)
	{
		this->head = value;
		this->tail = value;
	}
	else
	{
		
	}	
}

template<typename T>
void LinkedList<T>::insertAfter(Node<T>* curNode, T value)
{

}

template<typename T>
void LinkedList<T>::removeAfter(Node<T>* curNode)
{
}

template<typename T>
void LinkedList<T>::removeHead()
{
}

template<typename T>
void LinkedList<T>::removeTail()
{
}

template<typename T>
void LinkedList<T>::printList() const
{
}

template<typename T>
int LinkedList<T>::getLength() const
{
	return 0;
}

template<typename T>
void* LinkedList<T>::search(T element)
{
	return nullptr;
}
