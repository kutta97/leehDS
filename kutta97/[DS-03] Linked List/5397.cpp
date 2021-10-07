// 키로거
#include <iostream>
#include <list>
using namespace std;

void keyLogger(string key_input, list<char> &left, list<char> &right) {
	for (int i = 0; key_input[i] != 0; i++) {
		if (key_input[i] == '<') {
			if (!left.empty()) {
				right.push_front(left.back());
				left.pop_back();
			}
		} else if (key_input[i] == '>') {
			if (!right.empty()) {
				left.push_back(right.front());
				right.pop_front();
			}
		} else if (key_input[i] == '-') {
			if (!left.empty())
				left.pop_back();
		} else {
			left.push_back(key_input[i]);
		}
	}
}

void printPassword(list<char> &left, list<char> &right) {
	while (!left.empty()) {
		cout << left.front();
		left.pop_front();
	}
	while (!right.empty()) {
		cout << right.front();
		right.pop_front();
	}
	cout << "\n";
}

int main() {
	int T;
	string key_input;

	cin >> T;
	while (T--) {
		list<char> left;
		list<char> right;
		cin >> key_input;
		keyLogger(key_input, left, right);
		printPassword(left, right);
	}
	
	return (0);
}