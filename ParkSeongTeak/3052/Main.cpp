#include<iostream>
#include "ArrayHeader.h"
using namespace std;

//A*B*C <1000 000 000 -> 21억미만 int
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Array org(10);
	Array rest(42);
	int cnt = 0;

	org.SetArr();
	for (int i = 0; i < org.GetSize(); i++) {
		rest.Setnum(org.Getnum(i) % 42, rest.Getnum(org.Getnum(i) % 42) + 1);
	}
	for (int i = 0; i < rest.GetSize(); i++) {
		if (rest.Getnum(i) != 0) {
			cnt++;
		}
	}
	cout << cnt;



}