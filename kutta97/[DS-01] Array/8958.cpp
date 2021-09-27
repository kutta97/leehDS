// OX퀴즈
#include <iostream>
using namespace std;

int getScore(char *quiz) {
	int score = 0;
	int sum = 0;
	while (*quiz != 0) {
		if (*quiz == 'O') sum += ++score;
		if (*quiz == 'X') score = 0;
		quiz++;
	}
	return sum;
}

int main() {
	int n;
	char **quiz;

	cin >> n;
	quiz = new char*[n];
	for (int i = 0; i < n; i++) {
		quiz[i] = new char[80];
		cin >> quiz[i];
	}

	for (int i = 0; i < n; i++) {
		cout << getScore(quiz[i]) << '\n';
		delete[] quiz[i];
	}
	delete[] quiz;

	return 0;
}