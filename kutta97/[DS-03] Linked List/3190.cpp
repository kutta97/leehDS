// 뱀
#include <iostream>
#include "snake.h"
using namespace std;

Snake::Snake() {
	snake.push_front(Position(0, 0));
	dir = E;
}

void Snake::setDir(char C) {
	if (C == 'D') { dir = (dir + 1) % 4; }
	if (C == 'L') { dir = (dir == 0) ?  3 : (dir - 1); }
}

Position Snake::nextMove() {
	int newX = snake.front().x + movement[dir].x;
	int newY = snake.front().y + movement[dir].y;
	return Position(newX, newY);
}

void Snake::moveHead(Position newMove) {
	snake.push_front(Position(newMove.x, newMove.y));
}

Position Snake::moveTail() {
	Position tail = snake.back();
	snake.pop_back();
	return tail;
}

bool Snake::isDead(Position nextMove, int value, int N) {
	if (nextMove.x < 0 || nextMove.x >= N) return true;
	if (nextMove.y < 0 || nextMove.y >= N) return true;
	if (value == SNAKE) return true;
	return false;
}

int main() {
	int N, K; // 보드의 크기 N, 사과의 개수 K
	int L, X; // 방향 변환 횟수 L, 방향변환 시간 X
	char C; // 방향 변환 정보
	int map[100][100] = { { 0, }, };
	Snake snake;
	int time = 1;

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = APPLE;
	}
	map[0][0] = SNAKE;

	cin >> L;
	cin >> X >> C;
	while (true) {
		Position nextMove = snake.nextMove();
		int nextMoveVal = map[nextMove.x][nextMove.y];

		if (snake.isDead(nextMove, nextMoveVal, N)) {
			cout << time << '\n';
			return (0);
		}

		snake.moveHead(nextMove);
		map[nextMove.x][nextMove.y] = SNAKE;
		if (nextMoveVal != APPLE) {
			Position tail = snake.moveTail();
			map[tail.x][tail.y] = EMPTY;
		}

		if (time == X) {
			snake.setDir(C); L--;
			if (L == 0) X = 10000;
			else cin >> X >> C;
		}
		time++;
	}
	return 0;
}