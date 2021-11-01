#include <iostream>
using namespace std;
template <class T>
void ChangeSize1D(T*& a, const int oldSize,
	const int newSize);
template <class T>
class MaxHeap {
public:
	MaxHeap(int theCapacity = 10); // constructor
	void Push(const T& e);
	void Pop();
	bool IsEmpty() { return heapSize == 0; }
	T Top() { return heap[1]; }
private:
	int heapSize; // #elements in heap
	int capacity; // size of the array heap
	T* heap; // element array
	template <class T2>
	friend ostream& operator<<(ostream&, MaxHeap<T2>&);
};
template <class T>
void ChangeSize1D(T*& a, const int oldSize,
	const int newSize)
{ 
	if (newSize < 0) throw "newSize must be greater than 0";
	T* temp = new T[newSize];
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

	return os;
}


template <class T>
MaxHeap<T>::MaxHeap(int theCapacity ) : heapSize(0) {
	if (theCapacity < 1) throw "Must be + ve";
	capacity = theCapacity;
	heap = new T[capacity + 1]; // heap[0]는 사용안함
}


template <class T>
void MaxHeap<T>::Push(const T& e) {
	if (heapSize == capacity) {// 크기를 두 배로 
		ChangeSize1D(heap, capacity+1, 2*capacity+1);
		capacity *= 2;
	}
	
	int currentNode = ++heapSize;

	while (currentNode != 1 && heap[currentNode / 2] < e)// 부모노드로이동; n부모노드 2n , 2n+1 자식노드
	{//루트로 올라감
		heap[currentNode] = heap[currentNode / 2];
		currentNode /= 2;
	}
	
	heap[currentNode] = e;
	return;
}

template <class T>
void MaxHeap<T>::Pop() {
	if (IsEmpty()) {
		cout << "Heap is empty. Cannot delete";
		return;
	}
	heap[1].~T();	//최대 원소 삭제
	T lastE = heap[heapSize--];

	//trickle down

	int currentNode = 1;
	int child = 2;
	while (child <= heapSize) {
		//child 를 currentNode 의 큰 자식으로 설정
		if (child < heapSize && heap[child] < heap[child + 1])child++;

		//currentNode 에 lastE를 삽입 할 수 있는가?
		if (lastE >= heap[child]) break;// break
		//no
		heap[currentNode] = heap[child];	//자식으로 이동
		currentNode = child; child *= 2;	//한 레벨 내려감 
	}
	heap[currentNode] = lastE;
}
