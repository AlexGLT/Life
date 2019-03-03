#pragma once
#include "Patterns.h"
#include <memory>
#include "Cell.h"

class Prebuilt
{
public:
	Prebuilt() = default;
	~Prebuilt() = default;

	void killCells(std::unique_ptr<ColorCell[]> &cells, int count)
	{
		for (int pos = 0; pos < count*count; pos++)
		{
			int x = pos % count;
			int y = pos / count;

			cells[y * count + x].setLife(false);
		}
	}

	void setCells(std::unique_ptr<ColorCell[]> &cells)
	{
		switch (rand() % 2)
		{
		case 0:
			setInfinite(cells);
			break;
		case 1:
			setBird(cells);
			break;
		}
	}
};