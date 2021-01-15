#ifndef NODE
#define NODE

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