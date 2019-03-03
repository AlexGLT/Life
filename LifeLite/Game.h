#include <SDL_events.h>

#include <memory>

class GamePlane;
class Renderer;

class Game
{
    std::unique_ptr<GamePlane> game_plane;
    struct
    {
        int x = 0, y = 0, cell_size = 16;
    } plane;

    bool pause = true;
	bool advance = false;

public:
    Game();
    ~Game();

    void process_event(SDL_Event& event);
    void update();
    void render(Renderer& renderer);
};
