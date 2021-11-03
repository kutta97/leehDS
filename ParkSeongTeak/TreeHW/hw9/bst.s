#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
using namespace std;
template <class K, class E>
struct Node {
	Node(K ky, E el, int lsize = 1, Node<K, E>* left = 0, Node<K, E>* right = 0)
		: key(ky), element(el), leftSize(lsize), leftChild(left), rightChild(right) { }

	K key;
	E element;
	int leftSize;
	Node<K, E>* leftChild;
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
	bool Get(const K&, E&);
	void Print();
	bool RankGet(int r, K& k, E& e);
	void Delete(K& oldkey) { 
		Delete(root, oldkey);
	}
	void ThreeWayJoin(BST<K, E>& small, K midkey, E midel,BST<K, E>& big);
	void TwoWayJoin(BST<K, E>& small, BST<K, E>& big);

private: // helper 함수들
	void Visit(Node<K, E>*);
	void Insert(Node<K, E>*&, K, E);
	void Preorder(Node<K, E>*);
	void Inorder(Node<K, E>*);
	void Postorder(Node<K, E>*);
	void Delete(Node<K, E>*&, K&);
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
template <class K, class E>
bool BST<K, E>::Get(const K& k, E& e) {
	Node<K, E>* ptr = root;
	while (ptr)
		if (k < ptr->key) ptr = ptr->leftChild;
		else if (k > ptr->key)	ptr = ptr->rightChild;
		else { e = ptr->element; return true; }
	return false;
}

template <class K, class E>
void BST<K, E>::Print() { // inorder와 postorder로
	//traversal함
		cout << endl << "Inorder traversal : "; Inorder();
	cout << endl << "Postorder traversal : "; Postorder();
	cout << endl;
}
template <class K, class E>
bool BST<K, E>::RankGet(int r, K& k, E& e)
{ 
	Node<K, E>* ptr = root;
	while (ptr) {
		if (r < ptr -> leftSize) ptr = ptr -> leftChild;
		else if (r > ptr -> leftSize) {
			r -= ptr -> leftSize;
			ptr = ptr -> rightChild;
		}
		else {
			k = ptr -> key; 
			e = ptr -> element; 
			return true; 
		}
	}
	return false;
}
template <class K, class E>
void BST<K, E>::Delete(Node<K, E>*& ptr, K& oldkey)
{
	// ptr를 루트로 하는 트리에서 oldkey를 키로 하는 노드 삭제
	Node<K, E>* tmpptr; Node<K, E>* tmpdaddyptr;
	if (ptr == 0) return; // 그런 노드가 없으므로, 그냥 return
	if (oldkey < ptr->key)  // 좌측아들이 루트인 트리에서 삭제.
		Delete(ptr->leftChild, oldkey);
	else if (oldkey > ptr->key) // 우측아들이 루트인 트리에서
		Delete(ptr->rightChild, oldkey);
	else { // ptr노드가 바로 지울 노드인 경우임
		if (!ptr->leftChild && !ptr->rightChild) //아들이 없다면
		{
			delete ptr; ptr = 0; return;
		}
		else if (!ptr->leftChild) // 그 아들을 ptr가 가리키게
		// 하고, 현재 ptr가 가리키는 노드를 지움
		{
			tmpptr = ptr; ptr = ptr->leftChild;
			delete tmpptr; return;
		}
		else if (!ptr->rightChild) { 
			tmpptr = ptr; ptr = ptr->leftChild; 
			delete tmpptr; return;
		}
		else { // 두아들 있음:루트가 r루트인 우측 subtree 에서
		// ‘제일작은 노드’찾자
			Node<K, E>* rc = ptr->rightChild;
			if (!rc -> leftChild) {
				// rc가 왼쪽아들이 없으면 rc가 그 노드! 이제 rc 노드의
				// key/element/rightChild 정보를 ptr노드로 이동하고
				// rc노드를 지운다(즉 delete rc);
				ptr->key = rc->key; ptr->element = rc->element;
				ptr->rightChild = rc->rightChild;
				delete rc; 
				return;
			}
			else { // rc의 왼쪽 아들이 있으면, 그 아들의 왼쪽아들
				// 식으로 왼쪽 아들을 끝까지 쫒아가, 가장 작은 키 갖는
				//노드를 찾아, 그 노드의 key/element를 ptr노드로
				// 옮기고, 그 노드의 rightChild는 그 노드의 아빠의
				// leftChild에 저장한 다음 그 노드를 지움
				rc->leftSize--;
				Node<K, E>* lc = rc->leftChild;
				while (!lc->leftChild) {
					lc->leftSize--;
					tmpdaddyptr = lc;
					lc = lc->leftChild;
				}
				ptr->key = lc->key; ptr->element = lc->element;
				tmpdaddyptr->leftChild = lc->rightChild;
				delete lc; 
				return;
			}
		}
	}
}
template <class K, class E>
void BST<K, E>::ThreeWayJoin(BST<K, E>& small,
	K midkey, E midel, BST<K, E>& big) {
	root = new Node<K, E>(midkey, midel, small.root, big.root);
	small.root = big.root = 0;
}

template <class K, class E>
void BST<K, E>::TwoWayJoin(BST<K, E>& small, BST<K, E>& big) {
	if (!small.root) { root = big.root; big.root = 0; return; }
	if (!big.root) { root = small.root; small.root = 0; return; }
	BST small2 = small;
	// 이제 small2를 수정하고 midkey와 midel을 알아내어
	// ThreeWayJoin을 호출하도록 한다
	small.root = 0; big.root = 0;
}

#endif
