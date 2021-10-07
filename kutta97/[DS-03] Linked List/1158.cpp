// 요세푸스 문제
#include <iostream>
#include <list>
using namespace std;

int main() {
	int N, K;
	list<int> seq;

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		seq.push_back(i);

	cout << '<';
	while (N-- > 1) {
		for (int i = 0; i < K - 1; i++) {
			seq.push_back(seq.front());
			seq.pop_front();
		}	
		cout << seq.front() << ", ";
		seq.pop_front();
	}
	cout << seq.front() << ">\n";

	return (0);
}