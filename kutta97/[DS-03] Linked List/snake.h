#ifndef SNAKE_H
#define SNAKE_H

#define EMPTY 0
#define APPLE 1
#define SNAKE 2
#include <list>

enum directions { N, E, S, W };

struct Position {
	Position() {}
	Position(int xx, int yy): x(xx), y(yy) {}
	int x, y;
} movement[4] = { Position(-1, 0), Position(0,1), Position(1, 0), Position(0, -1) };

class Snake {
private:
	std::list<Position> snake;
	int dir;

public:
	Snake();
	void setDir(char);
	Position nextMove();
	void moveHead(Position);
	Position moveTail();
	bool isDead(Position, int, int);
};

#endif