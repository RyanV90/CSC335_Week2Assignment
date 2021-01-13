#ifndef NODE
#define NODE

template<typename T>
class Node
{
public:
	Node();
	Node(T value, Node<T>* nextNode, Node<T>* prevNode);
	T data;
	Node<T>* next;
	Node<T>* prev;
};

#endif // !NODE