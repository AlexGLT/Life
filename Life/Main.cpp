#include <SDL.h>
#include <cstdio>
#include "Resources.h"

int main(int argc, char* args[])
{
	Application Life(800, 600, NULL, NULL);

	SDL_Delay(2000);

	SDL_Quit();

	return 0;
}