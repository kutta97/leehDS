// 요세푸스 문제 0
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int N, K;
	queue<int> q;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		q.push(i);
	
	int ans[N];
	int idx = 0;
	while(!q.empty()) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		ans[idx++] = q.front();
		q.pop();
	}

	cout << '<' << ans[0];
	for (int i = 1; i < N; i++)
		cout << ", " << ans[i];
	cout << ">\n";

	return (0);
}