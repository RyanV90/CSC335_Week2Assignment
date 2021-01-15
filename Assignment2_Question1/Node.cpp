#include "Node.h"

template<typename T>
Node<T>::Node()
{
	this->nextNode = nullptr;
	this->nodeData = 0;
}

template<typename T>
Node<T>::Node(T nodeData, Node<T>* nextNode)
{
	this->nodeData = nodeData;
	this->nextNode = nextNode;
}

template<typename T>
T Node<T>::getNodeData() const
{
	return this->nodeData;
}

template<typename T>
void Node<T>::setNodeData(T nodeData)
{
	this->nodeData = nodeData;
}

template<typename T>
Node<T>* Node<T>::getNextNode() const
{
	return this->nextNode;
}

template<typename T>
void Node<T>::setNextNode(Node<T>* nextNode)
{
	this->nextNode = nextNode;
}