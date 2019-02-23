#include <SDL_video.h> // SDL_Window

#include <stdexcept> // std::runtime_error

class Window
{
    SDL_Window* handle;

public:
    Window(const char* title, int x, int y, int width, int height, Uint32 flags = 0) :
        handle{::SDL_CreateWindow(title, x, y, width, height, flags)} // equals to handle = ::SDL_CreateWindow(...) in the constructor's body {...}
    {
        if (!handle) // if handle == null
            throw std::runtime_error{::SDL_GetError()};
    }
    ~Window() {::SDL_DestroyWindow(handle);}

    // Ми видаляємо конструктор копіювання для того, щоб уникнути повторного видалення handle в деструкторі під час створення копії в конструкторі копіювання.
    Window(const Window&) = delete; // Тепер ми не зможемо в Window win2 = win1;

    // Метод повертає копію вказівника на об'єкт типу const SDL_Window.
    // Чому const SDL_Window? Тому що ми не хочемо, щоб хтось міг змінювати значення handle зовні через даний вказівник.
    const SDL_Window* get_handle() const /*const з цієї сторони означає, що даний метод не модифікує змінні (поля) об'єкта Window.*/ noexcept {return handle;}
    // noexcept - означає, що даний метод не кидає виключень. Користуватися цим потрібно обережно - тоді, коли ми точно впевнені, що в майбутньому нам не доведеться змінювати думку.
};

