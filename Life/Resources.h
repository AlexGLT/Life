#include <SDL.h>

class Application
{
private:
	SDL_Window* window;
	SDL_Surface* screenSurface;

	//����, �� ���������� �� ������ � ������ ����
	int width, height;

public:
	//�����������
	Application(int width, int height, SDL_Window* window, SDL_Surface* screenSurface)
	{
		window = SDL_CreateWindow("Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		screenSurface = SDL_GetWindowSurface(window);

		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

		SDL_UpdateWindowSurface(window);
	}

	//������� ���������� ������
	void finish()
	{
		SDL_DestroyWindow(window);
	}
};