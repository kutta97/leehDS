//\linux2: / ce / a3 / cea3025 / dir7 % cat tree.h
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <queue>
using namespace std;
template <class K, class E>
struct Node {
	Node(K ky, E el, Node<K, E>* left = 0, Node<K, E>* right = 0)
		: key(ky), element(el), leftChild(left), rightChild(right) { }
	Node<K, E>* leftChild;
	
	K key;
	E element;
	Node<K, E>* rightChild;
};

template <class K, class E>
class BST {
public:
	BST() { root = 0; } // empty BST
	void Insert(K& newkey, E el) { Insert(root, newkey, el); }
	void Preorder() { Preorder(root); }
	void Inorder() { Inorder(root); }
	void Postorder() { Postorder(root); }
	void Levelorder();
private: // helper 함수들
	void Visit(Node<K, E>*);
	void Insert(Node<K, E>*&, K, E);
	void Preorder(Node<K, E>*);
	void Inorder(Node<K, E>*);
	void Postorder(Node<K, E>*);
	Node<K, E>* root;
};
template <class K, class E>
void BST<K, E>::Visit(Node<K, E>* ptr)
{
	cout << ptr->key << ":" << ptr->element << " ";
}
template <class K, class E>
void BST<K, E>::Insert(Node<K, E>*& ptr, K newkey, E el)
{ //Insert의 helper함수
	if (ptr == 0) ptr = new Node<K, E>(newkey, el);
	else if (newkey < ptr->key) Insert(ptr->leftChild, newkey, el);
	else if (newkey > ptr->key) Insert(ptr->rightChild, newkey, el);
	else ptr->element = el; // Update element
}
template <class K, class E>
void BST<K, E>::Preorder(Node<K, E>* currentNode)
{ //Preorder의 helper함수
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}

template <class K, class E>
void BST<K, E>::Inorder(Node<K, E>* currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}

}

template <class K, class E>
void BST<K, E>::Postorder(Node<K, E>* currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);

	}

}

template <class K, class E>
void BST<K, E>::Levelorder() {
	queue<Node<K, E>*> q;
	q.push(root);
	while (!q.empty()) {
		Node<K, E>* currentNode = q.front();
		q.pop();
		if (currentNode) {
			Visit(currentNode);
			q.push(currentNode->leftChild);
			q.push(currentNode->rightChild);
		}
	}
}


//.....Inorder, Postorder의 helper함수를 구현하시오.
//.....Levelorder(교재p266 참조하되 STL 큐를 이용)를 구현하시오.
#endif
