#ifndef NODE
#define NODE

template<typename T>
class Node
{
public:
	Node();
	Node(T nodeData, Node<T>* nextNode, Node<T>* prevNode);
	T getNodeData() const;
	void setNodeData(T nodeData);
	Node<T>* getNextNode() const;
	void setNextNode(Node<T>* prevNode);
	Node<T>* getPrevNode() const;
	void setPrevNode(Node<T>* prevNode);

private:
	T nodeData;
	Node<T>* nextNode;
	Node<T>* prevNode;
};

#endif // !NODE

template<typename T>
inline Node<T>::Node()
{
	this->nextNode = nullptr;
	this->prevNode = nullptr;
	this->nodeData = 0;
}

template<typename T>
inline Node<T>::Node(T nodeData, Node<T>* nextNode, Node<T>* prevNode)
{
	this->nextNode = nextNode;
	this->prevNode = prevNode;
	this->nodeData = nodeData;
}

template<typename T>
inline T Node<T>::getNodeData() const
{
	return this->nodeData;
}

template<typename T>
inline void Node<T>::setNodeData(T nodeData)
{
	this->nodeData = nodeData;
}

template<typename T>
inline Node<T>* Node<T>::getNextNode() const
{
	return this->nextNode;
}

template<typename T>
inline void Node<T>::setNextNode(Node<T>* prevNode)
{
	this->nextNode = nextNode;
}

template<typename T>
inline Node<T>* Node<T>::getPrevNode() const
{
	return this->prevNode;
}

template<typename T>
inline void Node<T>::setPrevNode(Node<T>* prevNode)
{
	this->prevNode = prevNode;
}