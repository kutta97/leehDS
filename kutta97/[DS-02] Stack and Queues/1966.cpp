// 프린터 큐
#include <iostream>
#include <queue>
using namespace std;

class Element
{
public:
	int index;
	int value;
	Element(int i, int v) {
		index = i;
		value = v;
	}
};

int getPrintCountAt(int index, queue<Element> q, priority_queue<int> pq) {
	int print = 0;

	while (!q.empty()) {
		if (q.front().value == pq.top()) {
			print++;
			if (q.front().index == index)
				return (print);
			q.pop(); pq.pop();
		}
		if (q.front().value < pq.top()) {
			q.push(q.front());
			q.pop();
		}
	}
	return (-1);
}

int main(void) {
	int T;
	int N, M;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		int num;
		queue<Element> q;
		priority_queue<int> pq;
		for (int i = 0; i < N; i++) {
			cin >> num;
			q.push(Element(i, num));
			pq.push(num);
		}

		cout << getPrintCountAt(M, q, pq) << '\n';
	}

	return (0);
}