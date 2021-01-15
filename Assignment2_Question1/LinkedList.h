#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <iostream>

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
	Node<T>* newNode = new Node<T>(nodeData, nullptr);

	if (this->tail == nullptr)
	{
		this->head = this->tail = newNode;
	}
	else
	{
		this->tail->setNextNode(newNode);
		this->tail = newNode;
	}
}

template<typename T>
void LinkedList<T>::listPrepend(T nodeData)
{
	Node<T>* tempNode = new Node<T>(nodeData, nullptr);
	if (this->head == nullptr)
	{
		this->head = tempNode;
		this->tail = tempNode;
	}
	else
	{
		tempNode->setNextNode(this->head);
		this->head = tempNode;
	}
}

template<typename T>
void LinkedList<T>::insertAfter(Node<T>* curNode, T nodeData)
{
	if (this->head == nullptr)  // empty list, insert at head
	{
		Node<T>* newNode = new Node<T>(nodeData, nullptr); // Dynamically create a node object
		this->head = newNode;
		this->tail = newNode;
	}
	else if (curNode == this->tail)  //insert after the tail
	{
		Node<T>* newNode = new Node<T>(nodeData, curNode->getNextNode());
		this->tail->setNextNode(newNode);
		this->tail = newNode;
	}
	else // insert in the middle
	{
		Node<T>* newNode = new Node<T>(nodeData, curNode->getNextNode());
		curNode->setNextNode(newNode);
	}
}

template<typename T>
void LinkedList<T>::removeAfter(Node<T>* curNode)
{
	if (curNode->getNextNode() == nullptr)  //if the after Node is NULL, there is nothing to remove
	{
		std::cout << "Cannot remove Node\n";
	}
	else
	{
		Node<T>* tempNode = curNode->getNextNode();
		curNode->setNextNode(tempNode->getNextNode());
		delete tempNode;
	}
}

template<typename T>
void LinkedList<T>::removeHead()
{
	if (this->head != nullptr)
	{
		Node<T>* tempNode = this->head;
		this->head = this->head->getNextNode();
		delete tempNode;  //Nodes are dynamically allocated, must delete them when removed.
	}
}

template<typename T>
void LinkedList<T>::removeTail()
{
	Node<T>* tempNode = this->head;

	while (tempNode->getNextNode() != this->tail)
	{
		tempNode = tempNode->getNextNode();
	}

	tempNode->setNextNode(nullptr);
	
	delete this->tail;
	this->tail = tempNode;
}

template<typename T>
void LinkedList<T>::printList() const
{
	Node<T>* tempNode = this->head;
	while (tempNode != nullptr)
	{
		std::cout << tempNode->getNodeData() << " ";
		tempNode = tempNode->getNextNode();
	}
	std::cout << "\n";
}

template<typename T>
int LinkedList<T>::getLength() const
{
	Node<T>* curNode = this->head;
	int lengthOfListCounter = 0;

	while (curNode != nullptr)
	{
		curNode = curNode->getNextNode();
		lengthOfListCounter++;
	}

	return lengthOfListCounter;
}

template<typename T>
Node<T>* LinkedList<T>::listSearch(T key)
{
	Node<T>* curNode = this->head;

	while (curNode != nullptr)
	{
		if (curNode->getNodeData() == key)
		{
			return curNode;
		}
		curNode = curNode->getNextNode();
	}
	
	return nullptr;
}