#include "ArrayHeader.h"
#include<iostream>
using namespace std;

Array::Array(int size) : size(size) {
	arr = new int [size]{ 0, };
}
Array::~Array() {
	delete[] arr;
}

void Array::SetArr() {
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		if (arr[i] < min) {
			min = arr[i];
			minNum = i;
		}
		if (arr[i] > max) {
			max = arr[i];
			maxNum = i;

		}
	}
}
void Array::Setnum(int num, int data) {
	arr[num] = data;
}
int Array::Getnum(int num) {
	return arr[num];
}
int Array::GetMax() {
	return max;
}
int Array::GetMin() {
	return min;
}
int Array::GetMaxNum() {
	return maxNum;
}
int Array::GetMinNum() {
	return minNum;
}
int Array::GetSize()
{
	return size;
}
