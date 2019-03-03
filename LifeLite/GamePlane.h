#pragma once
#include <memory>
#include "ColorCell.h"
#include "Cell.h"

class Renderer;

class GamePlane
{
	int count;
	std::unique_ptr<ColorCell[]> cells;
	bool advanceMode = false;
	int r = 255;
	int g = 255;
	int b = 255;

public:
	GamePlane(int count)
	{
		this->count = count;

		cells = std::make_unique<ColorCell[]>(64 * 64);
	}

	void update();
    void render(Renderer& renderer, int x, int y, int cell_size);
	void changeColor();
	bool flipBool()
	{
		return advanceMode = !advanceMode;
	}
    void flip_cell(int x, int y)
	{
		cells[x + y * count].flipLife();
	}
	bool getCellLife(int x, int y)
	{
		return cells[x + y * count].getLife();
	}
    int get_size()
	{
		return count;
	}
	std::unique_ptr<ColorCell[]>& getCells()
	{
		return cells;
	}
};
