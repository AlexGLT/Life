#include <SDL.h>

#include <stdexcept> // std::runtimer_error
#include <memory> // std::unique_ptr

// Це називається forward-declaration - декларація ідентифікатора, для якого на даний момент не знайдено визначення.
// Грубо кажучи, ми вказуємо, що існує такий тип Window (визначений десь у іншому місці, хоча і не обов'язково), який ми в цьому файлі використовуємо як тип класу Window.
// Чому не просто include "Window.h"? Тому що підключення інших заголовочних файлів в заголовочному файлі призводить до збільшення обсягу коду, який компілятор повинен опрацювати,
// що призводить до збільшення часу компіляції. Крім того, ми тягнемо за собою код з заголовочних файлів, який ми не використовуємо.
class Window;
class Renderer;
class Game;

class Application
{
    struct SDL
    {
        SDL()
        {
            if (::SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) // Якщо SDL_Init повертає значення < 0, то помилка виконання.
                throw std::runtime_error{::SDL_GetError()}; // Конструктор std::runtime_error приймає рядок символів - помилку.
        }
        ~SDL() {::SDL_Quit();} // Прибираємо після себе.
    } sdl; // sdl - член класу Application. Об'єкт створений для того, щоб полегшити життя:
           // бібліотека SDL2 ініціалізується та знищується разом з об'єктом Application.

    // Оскільки ми використовуємо forward-declaration, то просто Window window написати не вийде, тому що Window наразі - невизначений тип.
    // Але ми можемо написати у комбінації з вказівником (Window* window). Тому нам доводиться створити об'єкт типу Window через динамічне виділення пам'яті (new).
    // std::unique_ptr - розумний вказівник (smart pointer), який видаляє об'єкт автоматично. Якби ми використовували звичайний вказівник (Window* window), то нам б довелося його
    // видаляти вручну через delete. Розумні вказівники значно полегшують життя.
    std::unique_ptr<Window>     window;
    std::unique_ptr<Renderer>   renderer;
    std::unique_ptr<Game>       game;

    bool running = true;

public:
    // Мінусом використання unique_ptr разом із forward-declaration - необхідність явної декларації конструктора й деструктора з подальшим визначенням в файлі .cpp.
    Application();
    ~Application();

    void execute();
};

