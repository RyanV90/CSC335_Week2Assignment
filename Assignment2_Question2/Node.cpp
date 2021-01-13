#include "Node.h"

template<typename T>
Node<T>::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

template<typename T>
Node<T>::Node(T value, Node<T>* nextNode, Node<T>* prevNode)
{
	data = value;
	next = nextNode;
	prev = prevNode;
}
