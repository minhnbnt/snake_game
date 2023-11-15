#include "snake.h"

#include "config.h"

#include <stdlib.h>

char CheckCollision(Position a, Position b) {
	return a.x == b.x && a.y == b.y;
}

void Snake_init(Snake *snake) {

	Position start_position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };

	snake->size = 1, snake->capacity = 5;
	snake->body = malloc(sizeof(Position) * snake->capacity);
	snake->body[0] = start_position;
}

void Snake_update(Snake *snake, Position *food) {

	for (size_t i = snake->size - 1; i > 0; --i) {
		snake->body[i] = snake->body[i - 1];
	}

	switch (snake->dir) {

	case DIRECTION_UP:
		snake->body[0].y -= CELL_SIZE;
		break;

	case DIRECTION_DOWN:
		snake->body[0].y += CELL_SIZE;
		break;

	case DIRECTION_LEFT:
		snake->body[0].x -= CELL_SIZE;
		break;

	case DIRECTION_RIGHT:
		snake->body[0].x += CELL_SIZE;
		break;
	}

	const char is_eaten_food = CheckCollision(snake->body[0], *food);

	if (!is_eaten_food) return;

	*food = Get_new_food();

	++snake->size;
	if (snake->size == snake->capacity + 1) {
		snake->capacity *= 1.6;
		snake->body = realloc(snake->body, sizeof(Position) * snake->capacity);
	}
}

Position Get_new_food(void) {

	const Position new_food = { rand() % (SCREEN_WIDTH / CELL_SIZE) * CELL_SIZE,
		                        rand() % (SCREEN_HEIGHT / CELL_SIZE) * CELL_SIZE };

	return new_food;
}

char Is_GAME_OVER(const Snake *snake) {

	for (size_t i = snake->size - 1; i > 0; --i) {
		if (CheckCollision(snake->body[i], snake->body[0])) {
			return 1;
		}
	}

	const char out_of_screen = snake->body[0].x < 0 || snake->body[0].x >= SCREEN_WIDTH ||
	                           snake->body[0].y < 0 || snake->body[0].y >= SCREEN_HEIGHT;

	return out_of_screen;
}
