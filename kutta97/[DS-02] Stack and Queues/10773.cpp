// 제로
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	int K;
	int input, sum = 0;
	stack<int> s;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> input;
		if (input == 0) s.pop();
		else s.push(input);
	}
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;

	return (0);
}