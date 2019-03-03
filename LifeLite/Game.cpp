#include "Game.h"
#include "Buttom.h"
#include "GamePlane.h"
#include "Prebuilt.h"
Game::Game()
{
	game_plane = std::make_unique<GamePlane>(64);
}

Game::~Game() = default;

void Game::process_event(SDL_Event& event)
{
    static bool pause_triggered = false;
    switch (event.type)
    {
        case SDL_KEYDOWN:
			if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
			{
				pause_triggered = true;
			}
            break;
        case SDL_KEYUP:
            if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && pause_triggered)
			{
				pause = !pause; pause_triggered = false;
			}
            break;
        case SDL_MOUSEMOTION:
        {
            if (event.motion.state & SDL_BUTTON_MMASK)
            {
                plane.x += event.motion.xrel;
                plane.y += event.motion.yrel;
            }
			if (event.motion.state & SDL_BUTTON_LMASK)
			{
				if (event.button.x >= plane.x && event.button.y >= plane.y && event.button.x < plane.x + game_plane->get_size() * plane.cell_size && plane.y + game_plane->get_size() * plane.cell_size)
				{
					if (game_plane->getCellLife((event.button.x - plane.x) / plane.cell_size, (event.button.y - plane.y) / plane.cell_size) == 0)
					{
						game_plane->flip_cell((event.button.x - plane.x) / plane.cell_size, (event.button.y - plane.y) / plane.cell_size);
					}
				}
			}
			if (event.motion.state & SDL_BUTTON_RMASK)
			{
				if (event.button.x >= plane.x && event.button.y >= plane.y && event.button.x < plane.x + game_plane->get_size() * plane.cell_size && plane.y + game_plane->get_size() * plane.cell_size)
				{
					if (game_plane->getCellLife((event.button.x - plane.x) / plane.cell_size, (event.button.y - plane.y) / plane.cell_size) == 1)
					{
						game_plane->flip_cell((event.button.x - plane.x) / plane.cell_size, (event.button.y - plane.y) / plane.cell_size);
					}
				}
			}
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
				if (event.button.x >= plane.x && event.button.y >= plane.y && event.button.x < plane.x + game_plane->get_size() * plane.cell_size && plane.y + game_plane->get_size() * plane.cell_size)
				{
					game_plane->flip_cell((event.button.x - plane.x) / plane.cell_size, (event.button.y - plane.y) / plane.cell_size);
				}
				if (event.button.x >= 1049 && event.button.y >= 25 && event.button.x < 1100 && event.button.y <= 75)
				{
					game_plane->flipBool();
				}
				if (event.button.x >= 1049 && event.button.y >= 924 && event.button.x < 1100 && plane.y + 1000)
				{
					Prebuilt pattern;
					pattern.killCells(game_plane->getCells(), 64);
					pattern.setCells(game_plane->getCells());
				}
				if (event.button.x >= 1049 && event.button.y >= 487 && event.button.x < 1100 && event.button.y < 538)
				{
					game_plane->changeColor();
				}
            }
            break;
        }
        case SDL_MOUSEWHEEL:
        {
            plane.cell_size += event.wheel.y;
            if (plane.cell_size <= 0) plane.cell_size = 1;
            break;
        }
    }
}

void Game::update()
{
    if (pause) return;

    static int counter = 0;
    //if (counter++ >= 1) game_plane->update(), counter = 0;
	game_plane->update();
}

void Game::render(Renderer& renderer)
{
	static Buttom advanced;
	static Buttom pattern;
	static Buttom color;
	advanced.setpos(1049, 25);
	advanced.setsize(50, 50);
	advanced.setcolor(0, 255, 0);
	pattern.setpos(1049, 924);
	pattern.setsize(50, 50);
	pattern.setcolor(0, 0, 255);
	color.setcolor(255, 0, 0);
	color.setpos(1049, 487);
	color.setsize(50, 50);

	advanced.draft(renderer);
	pattern.draft(renderer);
	color.draft(renderer);
    game_plane->render(renderer, plane.x, plane.y, plane.cell_size);
}
