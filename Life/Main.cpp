#include <SDL.h>
#include <cstdio>

int main(int argc, char* args[])
{
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	window = SDL_CreateWindow("Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

	screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(window);

	SDL_Delay(2000);

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}