// 최댓값
#include <iostream>
using namespace std;

int main() {
	int array[9];
	int max = 0;
	int index;

	for (int i = 0; i < 9; i++) {
		cin >> array[i];
		if (max < array[i]) {
			max = array[i];
			index = i;
		}
	}
	cout << max << '\n' << index + 1;

	return (0);
}