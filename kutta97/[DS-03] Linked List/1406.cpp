// 에디터
#include <iostream>
#include <list>
using namespace std;

int main(void) {
	list<char> left;
	list<char> right;
	string input;
	char cmd;
	int M;
 
	cin >> input;
	for (int i = 0; input[i] != 0; i++)
		left.push_back(input[i]);

	cin >> M;
	while (M--) {
		cin >> cmd;
		if (cmd == 'L') {
			if (!left.empty()) {
				right.push_front(left.back());
				left.pop_back();
			}
		}
		else if (cmd == 'D') {
			if (!right.empty()) {
				left.push_back(right.front());
				right.pop_front();
			}
		}
		else if (cmd == 'B') {
			if (!left.empty())
				left.pop_back();
		}
		else if (cmd == 'P') {
			cin >> cmd;
			left.push_back(cmd);
		}
	}

	while (!left.empty()) {
		cout << left.front();
		left.pop_front();
	}
	while (!right.empty()) {
		cout << right.front();
		right.pop_front();
	}
	cout << "\n";

	return (0);
}