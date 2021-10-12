// 행운의 바퀴
#include <iostream>
#include <list>
using namespace std;

int main() {
	int N, K, S;
	char alpha;
	bool check[26] = { 0, };
	list<char> wheel;

	cin >> N >> K;
	while (N--) wheel.push_back('?');

	while (K--) {
		cin >> S >> alpha;

		while (S--) {
			wheel.push_front(wheel.back());
			wheel.pop_back();
		}
		if (check[alpha - 'A'] && wheel.front() != alpha) {
			cout << '!';
			return (0);
		}
		if (wheel.front() != '?' && wheel.front() != alpha) {
			cout << '!';
			return (0);
		}
		if (wheel.front() == '?' || wheel.front() == alpha) {
			wheel.front() = alpha;
		}
		check[alpha - 'A'] = true;
	}

	while (!wheel.empty()) {
		cout << wheel.front();
		wheel.pop_front();
	}
	return (0);
}