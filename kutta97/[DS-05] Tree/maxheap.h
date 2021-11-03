#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
using namespace std;

template <class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize);

template <class T>
class MaxHeap {
	public:
		MaxHeap(int);
		void Push(const T& e);
		void Pop();
		bool IsEmpty() { return heapSize == 0; }
		T Top() {
			if (IsEmpty()) throw "You can't call Top() for an empty Heap.";
			return heap[1];
		}
	private:
		int heapSize;
		int capacity;
		T *heap;
	template <class T2>
	friend ostream& operator<<(ostream&, MaxHeap<T2>&);
};

template <class T>
void ChangeSize1D(T *&a, const int oldSize, const int newSize) {
	if (newSize < 0) throw "newSize must be greater than 0";
	T *temp = new T[newSize];
	copy(a, a + oldSize, temp);
	delete[] a;
	a = temp;
}

template <class T>
ostream& operator<<(ostream& os, MaxHeap<T>& H) {
	os << "<Heap Contents> ";
	for (int i = 1; i <= H.heapSize; i++)
		os << i << ":" << H.heap[i] << " ";
		os << endl;
}

template <class T>
MaxHeap<T>::MaxHeap (int theCapacity = 10) : heapSize(0) {
	if (theCapacity < 1) throw "Heap Capacity must be +ve";
	capacity = theCapacity;
	heap = new T[capacity + 1]; // heap[0]는 사용안함
}

template <class T>
void MaxHeap<T>::Push(const T& e) { 
	// Insert e into the max heap.
	if (heapSize == capacity) {
		ChangeSize1D(heap, capacity+1, 2*capacity+1);
		capacity *= 2;
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode/2]<e) 
	{	// bubble up
		heap[currentNode] = heap[currentNode/2]; // move parent down
		currentNode /= 2;
	}
	heap[currentNode] = e;
}

template <class T>
void MaxHeap<T>::Pop() { 
	// Delete max element
	if (IsEmpty()) throw "heap is empty. Cannot delete.";
	heap[1].~T(); // delete max element
	T lastE = heap[heapSize--]; // remove last element from heap

	// trickle down
	int currentNode = 1; // root
	int child = 2;
	while (child <= heapSize) // while the left child exists
	{	// set child to larger child of currentNode
		if (child < heapSize && heap[child] < heap[child+1]) child++;
		if (lastE >= heap[child]) break; // put lastE in currentNode

		heap[currentNode] = heap[child]; // move child up
		currentNode = child; child *= 2; // move down a level
	}
	heap[currentNode] = lastE;
 }

 #endif