#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <iostream>

//Creates a linked list object which uses nodes to store data
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

//Creates an empty linked list
template<typename T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

//Returns a pointer to the head node
template<typename T>
Node<T>* LinkedList<T>::getHead() const
{
	return this->head;
}

//Sets the pointer to a new head node
template<typename T>
void LinkedList<T>::setHead(Node<T>* head)
{
	this->head = head;
}

//Returns a pointer to the tail node
template<typename T>
Node<T>* LinkedList<T>::getTail() const
{
	return this->tail;
}

//Sets the pointer to a new tail node
template<typename T>
void LinkedList<T>::setTail(Node<T>* tail)
{
	this->tail = tail;
}

//Places a new node with data to the end of the linked list
template<typename T>
void LinkedList<T>::listAppend(T nodeData)
{
	Node<T>* newNode = new Node<T>(nodeData, nullptr);

	//If the list is empty, set head and tail to new node
	if (this->tail == nullptr)
	{
		this->head = this->tail = newNode;
	}
	//If the list contains nodes, add new node to end of list
	else
	{
		this->tail->setNextNode(newNode);
		this->tail = newNode;
	}
}

//Places a new node with data to the beginning of the linked list
template<typename T>
void LinkedList<T>::listPrepend(T nodeData)
{
	Node<T>* tempNode = new Node<T>(nodeData, nullptr);
	
	//If the list is empty, set head and tail to new node
	if (this->head == nullptr)
	{
		this->head = tempNode;
		this->tail = tempNode;
	}
	//If the list contains nodes, add new node to beginning of list
	else
	{
		tempNode->setNextNode(this->head);
		this->head = tempNode;
	}
}

//Inserts a new node after the parameter node
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

//Removes the node after the parameter node
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

//Remove the current head node
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

//Remove the current tail node
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

//Prints the data of each node in the linked list
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

//Returns the length of the linked list
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

//Searchs for a node with requested data and returns the pointer of that node.
template<typename T>
Node<T>* LinkedList<T>::listSearch(T key)
{
	Node<T>* curNode = this->head;

	//While not at end of list
	while (curNode != nullptr)
	{
		//If a node contains the data, return pointer to node
		if (curNode->getNodeData() == key)
		{
			return curNode;
		}
		curNode = curNode->getNextNode();
	}
	
	return nullptr;
}