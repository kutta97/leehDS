#include<iostream>
#include"Linked_List.h"
using namespace std;



template<class T>
LinkedList<T>::LinkedList() {
	start.back = &end;
	end.front = &start;
	start.front = &end;
	end.back = &start;
	sizeint = 0;
}

template<class T>
LinkedList<T>::~LinkedList<T>() {
	while (sizeint != 0) {

		//cout << back();
		pop_back();
	}
}

template<class T>
void LinkedList<T>::push_back(T data) {
	Node<T> * tmpnode = new Node<T>;
	tmpnode->data = data;
	tmpnode->back = &end;
	tmpnode->front = end.front;
	tmpnode->front->back = tmpnode;
	end.front = tmpnode;
	sizeint++;

}

template<class T>
void LinkedList<T>::push_front(T data) {
	Node<T>* tmpnode = new Node<T>;
	tmpnode.data = data;
	tmpnode.back = start.back;
	tmpnode.front = &start;
	tmpnode.back->front = &tmpnode;
	start.back = &tmpnode;
	sizeint++;

}


template<class T>
void LinkedList<T>::pop_front() {
	if (sizeint!=0) {
		Node<T>* tmpnode = start.back;

		start.back = start.back->back;
		start.back->front = &start;

		delete tmpnode;
		sizeint--;
	}
	

}

template<class T>
void LinkedList<T>::pop_back() {
	if (sizeint != 0) {

		Node<T>* tmpnode = end.front;

		end.front = end.front->front;
		end.front->back = &start;

		delete tmpnode;
		sizeint--;
	}
}

template<class T>
T LinkedList<T>::front() {
	return start.back->data;
}
template<class T>
T LinkedList<T>::back() {
	return end.front->data;
}
template<class T>
bool LinkedList<T>::empty() {
	if (sizeint == 0) return true;
	else return false;
}

template<class T>
int LinkedList<T>::size() {
	return sizeint;
}
