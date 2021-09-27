#include "ArrayHeader.h"

#include<iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Array arr(9);
	arr.SetArr();
	cout << arr.GetMax() << "\n" << arr.GetMaxNum()+1;
}