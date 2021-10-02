// 큐2
#include <iostream>
using namespace std;

class Queue
{
private:
	int queue[2000000];

public:
	int size;
	int start;
	int end;
	Queue() { size = 0; start = 0; end = -1;}
	bool empty() {
		if (size == 0) return (1);
		else return (0);
	};
	void push(int x) {
		queue[++end] = x;
		size++;
	};
	int pop() {
		if(empty()) return (-1);
		else {
			size--;
			return (queue[start++]);
		}
	};
	int front() {
		if(empty()) return (-1);
		else return (queue[start]);
	};
	int back() {
		if (empty()) return (-1);
		else return (queue[end]);
	};

};

int main(void) {
	int	N;
	int num;
	string cmd;
	Queue q;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			q.push(num);
		}
		if (cmd == "pop")
			cout << q.pop() << '\n';
		if (cmd == "size")
			cout << q.size << '\n';
		if (cmd == "empty")
			cout << q.empty() << '\n';
		if (cmd == "front")
			cout << q.front() << '\n';
		if (cmd == "back")
			cout << q.back() << '\n';
	}

	return (0);
}