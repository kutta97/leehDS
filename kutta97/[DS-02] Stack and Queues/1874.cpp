// 스택 수열
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int	main(void) {
	int n;
	int m;
	int x;
	stack<int> s;
	string ans;
	bool found;

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	m = 0;
	while (n--) {
		cin >> x;
		if (x > m) {
			while (x > m) {
				s.push(++m);
				ans += '+';
			}
			s.pop();
			ans += '-';
		} else {
			found = false;
			if (!s.empty()) {
				if (x == s.top())
					found = true;
				s.pop();
				ans += '-';
			}
			if (!found) {
				cout << "NO" << '\n';
				return (0);
			}
		}
	}

	int i = 0;
	while (ans[i]) {
		cout << ans[i] << '\n';
		i++;
	}

	return (0);
}