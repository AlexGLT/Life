#include <SDL_events.h>

#include <memory>

class GamePlane;
class Renderer;

class Game
{
    std::unique_ptr<GamePlane> game_plane;
    struct
    {
        int x = 0, y = 0, cell_size = 4;
    } plane;

    bool pause = false;

public:
    Game();
    ~Game();

    void process_event(const SDL_Event& event);
    void update();
    void render(const Renderer& renderer);
};
