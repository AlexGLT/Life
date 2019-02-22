#include <SDL.h>
#include <cstdio>
#include "Resources.h"

int main(int argc, char* args[])
{
	Application Life;

	Life.start(800, 600);

	SDL_Delay(2000);

	SDL_Quit();

	return 0;
}