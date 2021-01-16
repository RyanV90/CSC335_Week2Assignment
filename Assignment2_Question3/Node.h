// Definition of a node in a linked list
template<typename T>
class Node
{
public:         // all memebrs are made public
	Node();
	Node(T value, Node<T>* nextNode);
	T data;
	Node<T>* next;
};

//implementation of Node functions
template<typename T>
Node<T>::Node()
{
	next = NULL;
}

template<typename T>
Node<T>::Node(T value, Node<T>* nextNode)
{
	data = value;
	next = nextNode;
}