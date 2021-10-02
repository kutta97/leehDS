// 카드2
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int N;
	queue<int> q;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() > 1) {
		q.pop();
		if (q.size() > 1) {
			q.push(q.front());
			q.pop();
		}
	}

	cout << q.front() << '\n';

	return (0);
}