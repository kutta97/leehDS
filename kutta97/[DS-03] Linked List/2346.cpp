// 풍선 터뜨리기
#include <iostream>
#include <list>
using namespace std;

struct Balloon
{
	int index;
	int data;
	Balloon(int i, int d): index(i), data(d) {}
};


int main() {
	int N;
	int move;
	list<Balloon> b;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> move;
		b.push_back(Balloon(i, move));
	}

	while (!b.empty()) {
		cout << b.front().index << ' ';	
		move = b.front().data;
		b.pop_front();
	
		if (move > 0) {
			for (int i = 0; i < move - 1; i++) {
				b.push_back(b.front());
				b.pop_front();
			}
		}
		if (move < 0) {
			for (int i = 0; i < (-move); i++) {
				b.push_front(b.back());
				b.pop_back();
			}
		}
	}
	
	return (0);
}