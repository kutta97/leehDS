#pragma once
#ifndef STACK_H 
#define STACK_H
#include<iostream>
using namespace std;

template<class T>
class Stack {
	T* StackMem;
	int size;
	int capa;

	void ChangeSizeID(T*& Mem, const int oldsize, const int newSize);
public:
	Stack();
	~Stack();
	void Push(T data);
	T Pop();
	int Size();
	int Empty();
	T Top();


};

#include "Stack.h"
#endif // !
