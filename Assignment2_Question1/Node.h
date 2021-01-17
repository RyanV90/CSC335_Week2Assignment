#ifndef NODE
#define NODE

//Creates a node object to be used by a linked list
template<typename T>
class Node {

public:
	Node();
	Node(T nodeData, Node<T>* nextNode);
	T getNodeData() const;
	void setNodeData(T nodeData);
	Node<T>* getNextNode() const;
	void setNextNode(Node<T>* nextNode);
	
private:
	T nodeData;
	Node<T>* nextNode;
};

#endif // !NODE

//Creates an empty node
template<typename T>
Node<T>::Node()
{
	this->nextNode = nullptr;
	this->nodeData = 0;
}

//Creates a occupied node
template<typename T>
Node<T>::Node(T nodeData, Node<T>* nextNode)
{
	this->nodeData = nodeData;
	this->nextNode = nextNode;
}

//Returns node T data
template<typename T>
T Node<T>::getNodeData() const
{
	return this->nodeData;
}

//Sets node T data
template<typename T>
void Node<T>::setNodeData(T nodeData)
{
	this->nodeData = nodeData;
}

//Returns a pointer to the next node in the linked list
template<typename T>
Node<T>* Node<T>::getNextNode() const
{
	return this->nextNode;
}

//Sets next node in the linked list
template<typename T>
void Node<T>::setNextNode(Node<T>* nextNode)
{
	this->nextNode = nextNode;
}