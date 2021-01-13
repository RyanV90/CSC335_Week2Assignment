#include "Node.h"

template<typename T>
Node<T>::Node()
{
	next = nullptr;
	data = 0;
}

template<typename T>
Node<T>::Node(T value, Node<T>* nextNode)
{
	data = value;
	next = nextNode;
}
