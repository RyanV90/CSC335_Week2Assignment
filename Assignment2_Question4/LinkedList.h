#include "Node.h"

// Definition of the singly linked list
template<typename T>
class LinkedList
{
public:
	LinkedList();
	Node<T>* getHead() const;  // return the head pointer
	Node<T>* getTail() const;  // returns the tail pointer
	void listAppend(T value);  // inserts an element at the end of the list
	void listPrepend(T value); //inserts a n element at the head of the list
	void insertAfter(Node<T>* curNode, T value); // Insert value after the curNode
	void removeAfter(Node<T>* curNode); // removes the Node after the CurNode
	void removeHead();  // Removes the first element
	void removeTail();  // removes the last element
	//int getLength();  // retunrs the number of elements in the linked list
	void printList() const;  // print the elements of the linked list
	//Node<T>* search(T element) const;
	void SwapFirstTwo(); // swaps the first two elemenst of the list
	//void listInsertionSort();
private:
	Node<T>* head;
	Node<T>* tail;
	//Node<T>* listFindInsertionPosition(T value);
};

//implementation of the linked list functions
template<typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
}

template<typename T>
void LinkedList<T>::insertAfter(Node<T>* curNode, T value)
{
	if (head == NULL)  // empty list, insert at head
	{
		Node<T>* newNode = new Node<T>(value, NULL); // Dynamically create a node object
		head = newNode;
		tail = newNode;
	}
	else if (curNode == tail)  //insert after the tail
	{
		Node<T>* newNode = new Node<T>(value, curNode->next);
		tail->next = newNode;
		tail = newNode;
	}
	else // insert in the middle
	{
		Node<T>* newNode = new Node<T>(value, curNode->next);
		curNode->next = newNode;
	}
}

template<typename T>
void LinkedList<T>::SwapFirstTwo()
{
	if (head != NULL && head->next != NULL)
	{
		T temp = head->next->data;  // copy the second element in temp
		head->next->data = head->data; //copy the first element in the second node
		head->data = temp; // copy temp value in the first node
	}
}

template<typename T>
void LinkedList<T>::removeHead()
{
	if (head != NULL)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;  // Nodes are dynamically allocated, must delete them when removed.
	}
}

template<typename T>
void LinkedList<T>::removeTail()
{
	Node<T>* temp = head;
	while (temp->next != tail) // move forward in the list until reaching the node 
		temp = temp->next;     // just before the tail node.
	temp->next = NULL;
	delete tail;
	tail = temp;
}

template<typename T>
void LinkedList<T>::removeAfter(Node<T>* curNode)
{
	if (curNode->next == NULL)
		std::cout << "Cannot remove Node\n";
	else
	{
		Node<T>* temp = curNode->next;
		curNode->next = temp->next;
		delete temp;
	}
}

template<typename T>
Node<T>* LinkedList<T>::getHead() const
{
	return head;   // returns a Node pointer that points to the head of the list
}

template<typename T>
Node<T>* LinkedList<T>::getTail() const
{
	return tail;  // retruns a Node pointer that points to the tail of the list
}

template<typename T>
void LinkedList<T>::listAppend(T value)
{
	Node<T>* newNode = new Node<T>(value, NULL);
	if (tail == NULL)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

template<typename T>
void LinkedList<T>::listPrepend(T value)
{
	Node<T>* temp = new Node<T>(value, NULL);
	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

template<typename T>
void LinkedList<T>::printList() const
{
	Node<T>* temp = head;  // or temp = head
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}