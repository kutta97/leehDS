// 스택
#include <iostream>
#include <algorithm>
using namespace std;

class Stack
{
private:
	int	stack[10000];

public:
	int	size;
	Stack() { size = 0; }
	bool empty() {
		if (size == 0) return (1);
		else return (0);
	}
	void push(int num) {
		stack[size++] = num;
	}
	int pop() {
		if (empty()) return (-1);
		else return (stack[--size]);
	}
	int top() {
		if (empty()) return (-1);
		else return (stack[size - 1]);
	}
};

int	main(void) {
	int	N;
	int num;
	string cmd;
	Stack s;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--)
	{
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			s.push(num);
		}
		if (cmd == "pop")
			cout << s.pop() << "\n";
		if (cmd == "size")
			cout << s.size << "\n";
		if (cmd == "empty")
			cout << (s.empty() ? 1 : 0) << "\n";
		if (cmd == "top")
			cout << s.top() << "\n";
	}

	return (0);
}