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
	Array(int size);		//������ size��ŭ�� ����Ȯ��
	int num(int num);		//arr�� num��ġ�� ��
	void SetArr();			//size ��ŭ�� �� �޾ƿ�	
	
	//type GetNum()������ return Num 
	int GetMin();			
	int GetMax();			
	int GetMaxNum();		
	int GetMinNum();

};


#endif