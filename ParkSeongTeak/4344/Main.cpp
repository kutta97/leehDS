#include<iostream>
#include<string>
#include "ArrayHeader.h"

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;      
	double average = 0;
	int cnt = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		
		cnt = 0;
		average = 0;
		cin >> n;
		Array arr(n);
		arr.SetArr();

		for (int i = 0; i < n; i++) {
			average += arr.Getnum(i);
		}
		average = average / n;
		for (int i = 0; i < n; i++) {
			if (arr.Getnum(i) > average)
				cnt++;
		}
		cout << fixed;
		cout.precision(3);

		cout << (double)(cnt*100) / n <<"%" << "\n";
	}
}