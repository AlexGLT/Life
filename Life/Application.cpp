#include "Application.h"

// Тепер Window - визначений тип, і ми тепер маємо доступ до його членів.
#include "Window.h"

Application::Application()
    // std::make_unique - метод, який повертає об'єкт std::unique_ptr
    : window{std::make_unique<Window>("Game of Life", 0, 0, 800, 600)}
{
}

// Явно визначаємо деструктор за замовчуванням.
Application::~Application() = default;

void Application::execute()
{
    ::SDL_Delay(2000);
}

