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
	now = &start;
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
	if (size() == 0) {
		Next();
	}

	sizeint++;

}


template<class T>
void LinkedList<T>::push_Now(T data) {
	Node<T>* tmpnode = new Node<T>;
	tmpnode->data = data;
	tmpnode->back = now -> back;
	tmpnode->front = now;
	now -> back = tmpnode;
	tmpnode -> back ->front = tmpnode;
	if (size() == 0) {
		Next();
	}

	sizeint++;

}
template<class T>
void LinkedList<T>::push_front(T data) {
	Node<T>* tmpnode = new Node<T>;
	tmpnode->data = data;
	tmpnode->back = start.back;
	tmpnode->front = &start;
	tmpnode->back->front = tmpnode;
	start.back = tmpnode;
	if (size() == 0) {
		Next();
	}

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

template<class T>
void LinkedList<T>::Next() {
	if (now -> back != &end) {
		now = now->back;
	}
	else {
		now = start.back;
	}
	
}


template<class T>
void LinkedList<T>::Prev() {
	if (now -> front != &start) {
		now = now->front;
	}
	else {
		now = end.front;
	}

}


template<class T>
T LinkedList<T>::Now() {
	return now->data;

}


template<class T>
void LinkedList<T>::pop_Now() {
	if (sizeint != 0) {

		Node<T>* tmpnode = now;
		Next();
		
		tmpnode->front->back = tmpnode->back;
		tmpnode->back->front = tmpnode->front;

		delete tmpnode;
		sizeint--;
	}
}
