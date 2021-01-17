#ifndef NODE
#define NODE

//Creates a node object to be used by a linked list
template<typename T>
class Node
{
public:
	Node();
	Node(T nodeData, Node<T>* nextNode, Node<T>* prevNode);
	T getNodeData() const;
	void setNodeData(T nodeData);
	Node<T>* getNextNode() const;
	void setNextNode(Node<T>* nextNode);
	Node<T>* getPrevNode() const;
	void setPrevNode(Node<T>* prevNode);

private:
	T nodeData;
	Node<T>* nextNode;
	Node<T>* prevNode;
};

#endif // !NODE

//Creates an empty node
template<typename T>
inline Node<T>::Node()
{
	this->nextNode = nullptr;
	this->prevNode = nullptr;
	this->nodeData = 0;
}

//Creates a occupied node
template<typename T>
inline Node<T>::Node(T nodeData, Node<T>* nextNode, Node<T>* prevNode)
{
	this->nextNode = nextNode;
	this->prevNode = prevNode;
	this->nodeData = nodeData;
}

//Returns node T data
template<typename T>
inline T Node<T>::getNodeData() const
{
	return this->nodeData;
}

//Sets node T data
template<typename T>
inline void Node<T>::setNodeData(T nodeData)
{
	this->nodeData = nodeData;
}

//Returns a pointer to the next node in the linked list
template<typename T>
inline Node<T>* Node<T>::getNextNode() const
{
	return this->nextNode;
}

//Sets next node in the linked list
template<typename T>
inline void Node<T>::setNextNode(Node<T>* nextNode)
{
	this->nextNode = nextNode;
}

//Returns a pointer to the previous node
template<typename T>
inline Node<T>* Node<T>::getPrevNode() const
{
	return this->prevNode;
}

//Sets the pointer of the previous node
template<typename T>
inline void Node<T>::setPrevNode(Node<T>* prevNode)
{
	this->prevNode = prevNode;
}