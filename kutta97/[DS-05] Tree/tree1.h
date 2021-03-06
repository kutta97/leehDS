#ifndef TREE1_H
#define TREE1_H
#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct Node {
	Node(T d, Node<T> *left=0,  Node<T> *right=0)
		: data(d), leftChild(left), rightChild(right) { }
	
	Node<T> *leftChild;
	T data;
	Node<T> *rightChild;
};

template <class T>
class Tree {
	public:
		Tree() { root = 0; }
		void Insert(T value) { Insert(root, value); }
		void Preorder() { Preorder(root); }
		void Inorder() { Inorder(root); }
		void Postorder() { Postorder(root); }

		void Levelorder();
	private:
		void Visit(Node<T> *); 
		void Insert(Node<T>* &,T); 
		void Preorder(Node<T> *); 
		void Inorder(Node<T> *); 
		void Postorder(Node<T> *);

		Node<T> *root;
};

template <class T>
void Tree<T>::Visit(Node<T> *ptr) { cout << ptr->data << " "; }

template <class T>
void Tree<T>::Insert(Node<T>* &ptr,T value) { // Insert의 helper 함수
	if (ptr==0) ptr = new Node<T>(value);
	else if (value < ptr->data) Insert(ptr->leftChild, value);
	else if (value > ptr->data) Insert(ptr->rightChild, value);
	else cout << endl << "Duplicate value " << value << " ignored\n";
}

template<class T>
void Tree<T>::Preorder(Node<T> *currentNode) {
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}

template<class T>
void Tree<T>::Inorder(Node<T> *currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}

template<class T>
void Tree<T>::Postorder(Node<T> *currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}

template<class T>
void Tree<T>::Levelorder() {
	queue<Node<T>*> q;
	Node<T>* currentNode = root;
	while (currentNode) {
		Visit(currentNode);
		if (currentNode->leftChild)
			q.push(currentNode->leftChild);
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		if (q.empty()) return;
		currentNode = q.front();
		q.pop();
	}
}

#endif