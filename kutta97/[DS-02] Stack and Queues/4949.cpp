// 균형잡힌 세상
#include <iostream>
#include <stack>
using namespace std;

string checkBalancedStr(string str) {
	stack<char> s;

	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == '(') s.push('(');
		if (str[i] == '[') s.push('[');
		if (str[i] == ')') {
			if (s.empty()) return "no";
			if (s.top() != '(') return "no";
			s.pop();
		}
		if (str[i] == ']') {
			if (s.empty()) return "no";
			if (s.top() != '[') return "no";
			s.pop();
		}
	}
	return (s.empty()? "yes" : "no");
}

int main(void) {
	string str;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, str);
	while (str != ".") {
		cout << checkBalancedStr(str) << '\n';
		getline(cin, str);
	}

	return (0);
}