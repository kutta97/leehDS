#include "ArrayHeader.h"
#include<iostream>

using namespace std;

Array::Array(int size) : size(size) {
	arr = new int[size] {0,};
}
Array::~Array(){
	delete[] arr;
}

void Array::SetArr() {
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
}

void Array::GetMax() {
	cout << max << " ";
}

void Array::GetMin() {
	cout << min << " ";
}

int Array::num(int num) {
	return arr[num];
}

