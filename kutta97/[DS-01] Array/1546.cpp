// 평균
#include <iostream>
using namespace std;

int main() {
	int n;
	float sum = 0, max = 0;
	float* score;

	cin >> n;
	score = new float[n];
	for (int i = 0; i < n; i++) {
		cin >> score[i];
		if (score[i] > max) max = score[i];
	}
	for (int i = 0; i < n; i++) {
		sum += score[i] / max * 100;
	}
	cout << sum / n;
	delete[] score;
	return 0;
}