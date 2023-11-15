#ifndef _SNAKE_H_

#define _SNAKE_H_

#include <stddef.h>

typedef struct {
	int x, y;
} Position;

typedef enum {

	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,

} Direction;

typedef struct {

	Position *body;
	size_t size, capacity;
	Direction dir;

} Snake;

void Snake_init(Snake *snake);

Position Get_new_food(void);

void Snake_update(Snake *snake, Position *food);

char Is_GAME_OVER(const Snake *snake);

char CheckCollision(Position a, Position b);

#endif // !_SNAKE_H_
