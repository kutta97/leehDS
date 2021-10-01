#include<iostream>
#include"Stack.h"
using namespace std;

template<class T>
Stack<T>::Stack() {
	StackMem = new T[500];
	size = 0;
	capa = 500;
}

template<class T>
Stack<T>::~Stack() {
	delete[] StackMem;
}

template<class T>
void Stack<T>::ChangeSizeID(T*& Mem, const int oldsize, const int newSize)
{
	T* tmp = new T[newSize];
	int copysize = min(oldsize, newSize);
	copy(Mem, Mem + copysize, tmp);
	delete[] Mem;
	Mem = tmp;

}

template<class T>
void Stack<T>::Push(T data) {
	if (size >= capa) {
		ChangeSizeID(StackMem, capa, capa * 2);
	}
	size++;
	StackMem[size - 1] = data;

}

template<class T>
T Stack<T>::Pop() {
	T tmp;
	if (size > 0)
	{
		tmp = StackMem[size - 1];
		size--;							//내부자로 하나하나 날릴 필요는 없는듯
	}
	else {
		tmp = -1;
	}
	return tmp;
}

template<class T>
int Stack<T>::Size() {
	return size;
}

template<class T>
int Stack<T>::Empty() {
	if (size == 0)
		return 1;
	else
		return 0;
}

template<class T>
T Stack<T>::Top() {
	if (size <= 0)
		return -1;
	return StackMem[size - 1];
}

