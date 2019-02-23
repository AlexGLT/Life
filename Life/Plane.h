#pragma once
#include <memory>

class Plane
{
	int count;
	std::unique_ptr<bool[]> cells;

public:
	Plane(int count)
	{
		this->count = count;

		cells = std::make_unique<bool[]>(64 * 64);
	}
	void change()
	{
		for (int pos = 0; pos < count*count; pos++)
		{
			int x = pos % count;
			int y = pos / count;
			int number = 0;

			int neighbours = 0;

			for (int Y = -1; Y < 2; Y++)
			{
				for (int X = -1; X < 2; X++)
				{
					if ((x + X) >= count || (y + Y) >= count || x < X || y < Y || (X == 0 && Y == 0))
					{
						continue;
					}
					if (cells[((y + Y) * count) + (x + X)] == 1)
					{
						neighbours++;
					}
				}
			}

			if (cells[pos] == 0)
			{
				if (neighbours == 3)
				{
					cells[pos] = 1;
				}
			}
			else
			{
				if ((neighbours == 2) || neighbours == 3)
				{
					continue;
				}
				else
				{
					cells[pos] = 0;
				}
			}
		}
	}
	void draw()
	{

	}
};