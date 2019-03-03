#include <SDL_render.h>

class Window; // forward-declaration - Window is not a complete type.

class Renderer
{
    SDL_Renderer* handle;

public:
    Renderer(Window& window);
    
	~Renderer()
	{
		::SDL_DestroyRenderer(handle);
	}

    void present()
	{
		::SDL_RenderPresent(handle);
	}
    void clear()
	{
		::SDL_RenderClear(handle);
	}

    void fill_rect(int  x, int  y, int  w, int  h);
    void draw_rect(int  x, int  y, int  w, int  h);
    void draw_line(int x1, int y1, int x2, int y2)
	{
		::SDL_RenderDrawLine(handle, x1, y1, x2, y2);
	}
    void set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255)
	{
		::SDL_SetRenderDrawColor(handle, r, g, b, a);
	}
};
