#include<iostream>
#include "ArrayHeader.h"
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num;
	float sum = 0.0;
	cin >> num;
	Array scores(num);
	
	scores.SetArr();
	int MaxScore = scores.GetMax();
	for (int i = 0; i < scores.GetSize(); i++) {
		sum += ((float)scores.Getnum(i) / MaxScore)*100;
	}
	cout.precision(10);
	cout << sum / scores.GetSize();

}