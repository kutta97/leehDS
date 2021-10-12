// 회전하는 큐
#include <iostream>
#include <list>
using namespace std;

int countMinMove(list<int> &q, int find) {
	int count = 0;
	int tofind_idx = 0;

	list<int>::iterator iter;
	for (iter = q.begin(); *iter != find; iter++)
		tofind_idx++;

	if (tofind_idx <= q.size() / 2) {
		while (q.front() != find) {
			q.push_back(q.front());
			q.pop_front();
			count++;
		}
	} else {
		while (q.front() != find) {
			q.push_front(q.back());
			q.pop_back();
			count++;
		}
	}
	q.pop_front();
	return count;
}

int main(void) {
	int N, M;
	int find, count = 0;
	list<int> queue;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		queue.push_back(i);

	for (int i = 0; i < M; i++) {
		cin >> find;
		count += countMinMove(queue, find);
	}
	cout << count;
	
	return (0);
}