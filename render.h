#ifndef _RENDER_H_

#define _RENDER_H_

#include "config.h"
#include "snake.h"

#include <SDL2/SDL.h>

void Render(SDL_Renderer *renderer, const Snake *snake, const Position *food);

void HandleInput(Snake *snake);

#endif // _RENDER_H_
