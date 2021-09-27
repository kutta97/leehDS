#pragma once
#ifndef ArrayHeader
#define ArrayHeader
#include<limits.h>

class Array {

	int* arr;
	int size = 0;
	int min = INT_MAX;
	int max = INT_MIN;
	int maxNum;
	int minNum;
public:
	Array(int size);		//생성자 size만큼의 공간확보
	~Array();
	void SetArr();			//size 만큼의 수 받아옴	
	void Setnum(int num, int data);	//num위치에 data값넣기 
	//type GetNum()형식은 return Num 
	int Getnum(int num);		//arr의 num위치의 값
	int GetMin();			
	int GetMax();			
	int GetMaxNum();		
	int GetMinNum();
	int GetSize();				

};


#endif