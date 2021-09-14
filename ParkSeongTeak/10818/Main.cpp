#include<iostream>
#include "ArrayHeader.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	Array arr(num);
	arr.SetArr();
	arr.GetMin();
	arr.GetMax();

}