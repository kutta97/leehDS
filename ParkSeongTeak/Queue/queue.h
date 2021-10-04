#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;

template<class T>
class Node {
	T data;
	Node* front;
	Node* back;
public :
	friend queue;
};

template<class T>
class queue {
	Node start;
	Node end;
	Node* Now;
	int size;
public :

	queue();
	~queue();
	void push(T);
	T front();
	T back();
	int size();
	void pop();
	bool empty();
	
};

#include"queue.hpp"
#endif // !1
