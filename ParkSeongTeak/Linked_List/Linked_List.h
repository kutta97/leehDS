#pragma once
#ifndef LINKED_H
#define LINKED_H
#include<iostream>
using namespace std;



template<class T>
class LinkedList {
	template<class T1>
	class Node {
	public :
		T1 data;
		Node<T1>* front;
		Node<T1>* back;
	};


private:
	Node<T> start;
	Node<T> end;
	Node<T>* now;
	int sizeint;

public :

	LinkedList<T>();
	~LinkedList<T>();

	void push_back(T);
	void push_front(T);
	void push_Now(T);

	void pop_front();
	void pop_back();
	void pop_Now();

	bool empty();
	int size();

	T front();
	T back();
	T Now();
	void Next();
	
	

};


#include"Linked_List.hpp"

#endif // !1
