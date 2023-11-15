#include "render.h"

#include <SDL2/SDL.h>

void Render(SDL_Renderer *renderer, const Snake *snake, const Position *food) {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (size_t i = 0; i < snake->size; ++i) {
		SDL_Rect rect = { snake->body[i].x, snake->body[i].y, CELL_SIZE, CELL_SIZE };
		SDL_RenderFillRect(renderer, &rect);
	}

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect foodRect = { food->x, food->y, CELL_SIZE, CELL_SIZE };
	SDL_RenderFillRect(renderer, &foodRect);

	SDL_RenderPresent(renderer);
}

void HandleInput(Snake *snake) {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		switch (event.type) {

		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {

			case SDLK_UP:

				if (snake->dir != DIRECTION_DOWN) {
					snake->dir = DIRECTION_UP;
				}

				break;

			case SDLK_DOWN:

				if (snake->dir != DIRECTION_UP) {
					snake->dir = DIRECTION_DOWN;
				}

				break;

			case SDLK_LEFT:

				if (snake->dir != DIRECTION_RIGHT) {
					snake->dir = DIRECTION_LEFT;
				}

				break;

			case SDLK_RIGHT:

				if (snake->dir != DIRECTION_LEFT) {
					snake->dir = DIRECTION_RIGHT;
				}

				break;
			}
			break;
		}
	}
}
