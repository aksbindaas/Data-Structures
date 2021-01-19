#include <iostream>

using namespace std;

template <typename T>
class Node{
	T data;
	Node *link;
public:	
	Node (T value) : link(nullptr) {
		data = value; 
	}

	Node* next() {
		return link;
	}

	T getData() {
		return data;
	}

	void linkNode (Node *newNode) {
		link = newNode;
	}	
};

template <typename T>
class LinkedList {

private:
Node<T>*rootNode;
public:
	LinkedList () : rootNode(nullptr) {
		cout<<"LinkedList ctor\n";
	}

	void push_back(T data)
	{
		Node<T>*new_node = new Node<T>(data);
		if (rootNode == nullptr) {
			rootNode =  new_node;
		} else {
			Node<T>*iter = rootNode;
			while (iter->next() != nullptr) {
				iter = iter->next();
			}
			iter->linkNode(new_node);
		}
	}
	
	void print() {
		Node<T>*iter =  rootNode;
		while (iter != nullptr) {
			cout<< iter->getData()<<" -> ";
			iter = iter->next();
		}
		cout<<"nullptr"<<endl;
	}

	~LinkedList () {
		cout<<"~LinkedList dtor\n";
		while (rootNode->next() != nullptr) {
			Node<T> * temp = rootNode;
			rootNode = rootNode->next();
			delete temp;
		}
	}
};