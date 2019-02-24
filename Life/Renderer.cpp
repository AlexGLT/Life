#include "Renderer.h"

#include "Window.h"

#include <stdexcept>

Renderer::Renderer(const Window& window) :
    handle{::SDL_CreateRenderer(const_cast<SDL_Window*>(window.get_handle()), -1, SDL_RENDERER_ACCELERATED)}
{
    if (!handle)
        throw std::runtime_error{::SDL_GetError()};
}

void Renderer::fill_rect(int x, int y, int w, int h) const noexcept
{
    const SDL_Rect dstrect{x, y, w, h};
    ::SDL_RenderFillRect(handle, &dstrect);
}

void Renderer::draw_rect(int x, int y, int w, int h) const noexcept
{
    const SDL_Rect dstrect{x, y, w, h};
    ::SDL_RenderDrawRect(handle, &dstrect);
}
