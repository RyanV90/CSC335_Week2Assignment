#ifndef NODE
#define NODE


template<typename T>
class Node
{
public:
	Node();
	Node(T value, Node<T>* nextNode);
	T data;
	Node<T>* next;
};

#endif // !NODE