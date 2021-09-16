// 평균은 넘겠지
#include <iostream>
using namespace std;

float getRatio(int *score, int n, float avg) {
	int greater_than_avg = 0;
	for (int i = 0; i < n; i++) {
		if (score[i] > avg) greater_than_avg++;
	}
	return (greater_than_avg / (float)n * (float)100);
}

int main() {
	int c, n, sum;
	int *score;
	float *array;

	cin >> c;
	array = new float[c];
	for (int i = 0; i < c; i++) {
		cin >> n;
		score = new int[n];
		sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> score[j];
			sum += score[j];
		}
		array[i] = getRatio(score, n, sum/n);
		delete[] score;
	}

	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < c; i++)
		cout << array[i] << "%\n";

	delete[] array;
	return 0;
}