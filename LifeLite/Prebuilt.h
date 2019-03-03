#pragma once
#include <memory>
#include "Cell.h"

class Prebuilt
{
	std::unique_ptr<Cell[]> cells;

public:
	Prebuilt() = default;
	~Prebuilt() = default;

	std::unique_ptr<Cell[]> killCells(std::unique_ptr<Cell[]>, int count)
	{
		for (int pos = 0; pos < count*count; pos++)
		{
			int x = pos % count;
			int y = pos / count;

			cells[y * count + x].setLife(false);
		}
	}

	std::unique_ptr<Cell[]> setCells(std::unique_ptr<Cell[]> pattern, int count)
	{
		for (int num = 0; num < count*count; num++)
		{
			cells[num].setLife(pattern[num].getLife());
		}
	}
};