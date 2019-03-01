#pragma once
#include <memory>

class Renderer;

class GamePlane
{
	int count;
	std::unique_ptr<bool[]> cells;

public:
	GamePlane(int count)
	{
		this->count = count;

		cells = std::make_unique<bool[]>(64 * 64);
	}

	void update();
    void render(Renderer& renderer, int x, int y, int cell_size);

    void set_cell(int x, int y, bool live)
	{
		cells[x + y * count] = live;
	}
    void flip_cell(int x, int y)
	{
		cells[x + y * count] = !cells[x + y * count];
	}
    int get_size()
	{
		return count;
	}
};
