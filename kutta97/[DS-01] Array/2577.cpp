// 숫자의 개수
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int mul;
	int array[10] = { 0, };

	cin >> a >> b >> c;
	mul = a * b * c;

	while (mul > 0) {
		array[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << array[i] << '\n';
	}

	return (0);
}