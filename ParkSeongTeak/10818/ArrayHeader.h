#pragma once
#ifndef ArrayHeader
#define ArrayHeader

class Array {
	int* arr;
	int size = 0;
	int min = 987654321;
	int max = -987654321;
public:
	Array(int size);		//������ size��ŭ�� ����Ȯ��
	void SetArr();			//size ��ŭ�� �� �޾ƿ�	
	void GetMin();			//�ּڰ� ���
	void GetMax();			//�ִ� ���
	int num(int num);		//arr�� num��ġ�� ��
};


#endif