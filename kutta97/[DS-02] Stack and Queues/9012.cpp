// 괄호
#include <iostream>
#include <stack>
using namespace std;

string checkVPS(string PS) {
	stack<char> s;

	for (int i = 0; PS[i] != 0; i++) {
		if (PS[i] == '(') s.push('(');
		if (PS[i] == ')') {
			if (s.empty()) return "NO";
			else s.pop();
		}
	}
	return (s.empty()? "YES" : "NO");
}

int main() {
	int T;
	string PS;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> PS;
		cout << checkVPS(PS) << '\n';
	}
	return (0);
}