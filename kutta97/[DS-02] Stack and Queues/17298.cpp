// 오큰수
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
	int N;
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	stack<int> s;
	vector<int> seq(N);
	vector<int> ans(N);

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int i = 0; i < N; i++) {
		while (!s.empty() && seq[s.top()] < seq[i]) {
			ans[s.top()] = seq[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return (0);
}