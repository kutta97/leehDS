// 뱀
#include <iostream>
#include <list>
using namespace std;

# define EMPTY 0
# define APPLE 1
# define SNAKE 2

enum directions { N, E, S, W };

struct Position {
	Position() {}
	Position(int xx, int yy): x(xx), y(yy) {}
	int x, y;
} movement[4] = { Position(-1, 0), Position(0,1), Position(1, 0), Position(0, -1) };

class Snake {
private:
	list<Position> snake;
	int dir;

public:
	Snake() {
		snake.push_front(Position(0, 0));
		dir = E;
	}
	void setDir(char C) {
		if (C == 'D') { dir = (dir + 1) % 4; }
		if (C == 'L') { dir = (dir == 0) ?  3 : (dir - 1); }
	}
	Position nextMove() {
		int newX = snake.front().x + movement[dir].x;
		int newY = snake.front().y + movement[dir].y;
		return Position(newX, newY);
	}
	void moveHead(Position newMove) {
		snake.push_front(Position(newMove.x, newMove.y));
	}
	Position moveTail() {
		Position tail = snake.back();
		snake.pop_back();
		return tail;
	}
	bool isDead(int x, int y, int N, int value) {
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= N) return false;
	if (value == SNAKE) return false;
	return true;
	}
};

int main() {
	int N, K; // 보드의 크기 N, 사과의 개수 K
	int L, X; // 방향 변환 횟수 L, 방향변환 시간 X
	char C; // 방향 변환 정보
	int map[100][100] = { 0, };
	Snake snake;
	int time = 1;

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
	}
	map[0][0] = 2;

	cin >> L;
	cin >> X >> C;
	while (true) {
		Position nextMove = snake.nextMove();
		int nextMoveVal = map[nextMove.x][nextMove.y];
		if (snake.isDead(nextMove.x, nextMove.y, N, nextMoveVal))
		{
			if (nextMoveVal != APPLE) {
				Position tail = snake.moveTail();
				map[tail.x][tail.y] = EMPTY;
			}
			snake.moveHead(nextMove);
			map[nextMove.x][nextMove.y] = SNAKE;
		} else {
			cout << time << '\n';
			return (0);
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