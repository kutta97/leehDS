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
	~Array();
	void SetArr();			//size ��ŭ�� �� �޾ƿ�	
	void Setnum(int num, int data);	//num��ġ�� data���ֱ� 
	//type GetNum()������ return Num 
	int Getnum(int num);		//arr�� num��ġ�� ��
	int GetMin();			
	int GetMax();			
	int GetMaxNum();		
	int GetMinNum();
	int GetSize();				

};


#endif