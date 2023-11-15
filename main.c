#include "config.h"
#include "render.h"
#include "snake.h"

#include <SDL2/SDL.h>

int main(void) {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Window *window =
	    SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	                     SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Snake snake;
	Snake_init(&snake);

	Position food = Get_new_food();

	while (1) {

		HandleInput(&snake);

		Snake_update(&snake, &food);

		Render(renderer, &snake, &food);

		if (Is_GAME_OVER(&snake)) {
			break;
		}

		SDL_Delay(100);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
