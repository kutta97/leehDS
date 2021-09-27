#pragma once
#ifndef ArrayHeader
#define ArrayHeader

class Array {
	int* arr;
	int size = 0;
	int min = 987654321;
	int max = -987654321;
public:
	Array(int size);		//생성자 size만큼의 공간확보
	~Array();
	void SetArr();			//size 만큼의 수 받아옴	
	void GetMin();			//최솟값 출력
	void GetMax();			//최댓값 출력
	int num(int num);		//arr의 num위치의 값
};


#endif
