#include "Application.h"

// Тепер Window - визначений тип, і ми тепер маємо доступ до його членів.
#include "Window.h"
#include "Renderer.h"
#include "Game.h"

Application::Application() :
    // std::make_unique - метод, який повертає об'єкт std::unique_ptr
    window  {std::make_unique<Window>("Game of Life", 800, 600)},
    renderer{std::make_unique<Renderer>(*window)},
    game    {std::make_unique<Game>()}
{
}

// Явно визначаємо деструктор за замовчуванням.
Application::~Application() = default;

void Application::execute()
{
    SDL_Event event;
    while (running)
    {
        while (::SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) running = false;
            game->process_event(event);
        }
        game->update();
        renderer->clear();
        game->render(*renderer);
        renderer->present();
        ::SDL_Delay(1);
    }
}

