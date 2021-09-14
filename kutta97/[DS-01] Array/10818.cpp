// 최소, 최대
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int* array;

	cin >> n;
	array = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	sort(array, array+n);
	cout << array[0] << ' ' << array[n-1];

	delete[] array;
	return (0);
}