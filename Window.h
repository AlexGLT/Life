#include <SDL_video.h> // SDL_Window


class Window
{
    SDL_Window* handle;

public:
    Window(const char* title, int width, int height, int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED, Uint32 flags = 0)
    {
		handle = ::SDL_CreateWindow(title, x, y, width, height, flags);
    }
    ~Window()
	{
		::SDL_DestroyWindow(handle);
	}

    // Метод повертає копію вказівника на об'єкт типу const SDL_Window.
    SDL_Window* get_handle()
	{
		return handle;
	}
};

