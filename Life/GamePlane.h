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
    void render(const Renderer& renderer, int x, int y, int cell_size) const;

    void set_cell(int x, int y, bool live) noexcept {cells[x + y * count] = live;}
    void flip_cell(int x, int y) noexcept {cells[x + y * count] = !cells[x + y * count];}
    int get_size() const noexcept {return count;}
};
