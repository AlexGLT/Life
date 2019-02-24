#include <SDL_render.h>

class Window; // forward-declaration - Window is not a complete type.

class Renderer
{
    SDL_Renderer* handle;

public:
    // explicit means that 'Renderer renderer = window' will not work. 'Renderer renderer(window)' is the only correct way now.
    explicit Renderer(const Window& window);
    ~Renderer() {::SDL_DestroyRenderer(handle);}

    Renderer(const Renderer&) = delete;

    void present() const noexcept {::SDL_RenderPresent(handle);}
    void clear() const noexcept {::SDL_RenderClear(handle);}

    void fill_rect(int  x, int  y, int  w, int  h) const noexcept;
    void draw_rect(int  x, int  y, int  w, int  h) const noexcept;
    void draw_line(int x1, int y1, int x2, int y2) const noexcept {::SDL_RenderDrawLine(handle, x1, y1, x2, y2);}
    void set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255) const noexcept {::SDL_SetRenderDrawColor(handle, r, g, b, a);}
};
