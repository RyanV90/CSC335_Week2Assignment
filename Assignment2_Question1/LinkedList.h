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

template<typename T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
Node<T>* LinkedList<T>::getHead() const
{
	return this->head;
}

template<typename T>
void LinkedList<T>::setHead(Node<T>* head)
{
	this->head = head;
}

template<typename T>
Node<T>* LinkedList<T>::getTail() const
{
	return this->tail;
}

template<typename T>
void LinkedList<T>::setTail(Node<T>* tail)
{
	this->tail = tail;
}

template<typename T>
void LinkedList<T>::listAppend(T nodeData)
{
	/*Node<T>* newNode = new Node<T>(nodeData, nullptr);

	if (this->tail == nullptr)
	{
		this->head = this->tail = newNode;
	}
	else
	{
		this->tail->next = newNode;
		this->tail = newNode;
	}*/

	//delete newNode;
}

template<typename T>
void LinkedList<T>::listPrepend(T nodeData)
{
}

template<typename T>
void LinkedList<T>::insertAfter(Node<T>* curNode, T nodeData)
{
}

template<typename T>
void LinkedList<T>::removeAfter(Node<T>* curNode)
{
}

template<typename T>
void LinkedList<T>::removeHead()
{
	//if (this->head != nullptr)
	//{
	//	Node<T>* tempNode = this->head;
	//	this->head = this->head->nextNode;
	//	delete tempNode;  //Nodes are dynamically allocated, must delete them when removed.
	//}
}

template<typename T>
void LinkedList<T>::removeTail()
{
	/*Node<T>* tempNode = this->head;

	while (tempNode->nextNode != this->tail)
	{
		tempNode = tempNode->nextNode;
	}

	tempNode->nextNode = nullptr;
	delete this->tail;
	this->tail = tempNode;*/
	//delete tempNode;
}

template<typename T>
void LinkedList<T>::printList() const
{
	//Node<T>* tempNode = this->head;  // or temp = head
	//while (tempNode != nullptr)
	//{
	//	std::cout << tempNode->nodeData << " ";
	//	tempNode = tempNode->nextNode;
	//}
	//std::cout << "\n";

	//delete tempNode;
}

template<typename T>
int LinkedList<T>::getLength() const
{
	return 0;
}

template<typename T>
Node<T>* LinkedList<T>::listSearch(T key)
{
	return nullptr;
}