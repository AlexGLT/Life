#include <SDL.h>

class Application
{
private:
	SDL_Window* window;
	SDL_Surface* screenSurface;

	//змінні, які відповідають за ширину і висоту вікна
	int width, height;

public:
	//конструктор
	Application(int width, int height, SDL_Window* window, SDL_Surface* screenSurface)
	{
		window = SDL_CreateWindow("Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		screenSurface = SDL_GetWindowSurface(window);

		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

		SDL_UpdateWindowSurface(window);
	}
	//функція завершення роботи
	void finish()
	{
		SDL_DestroyWindow(window);
	}
};
