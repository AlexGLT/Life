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
	void update()
	{
        // Копіюємо масив з клітинками в інший масив.
        auto temp{std::make_unique<bool[]>(count * count)};
        for (int i = 0; i < count * count; ++i) temp[i] = cells[i];

        // Виконуємо алгоритм на новоствореному масиві.

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
					if ((x + X) >= count || (y + Y) >= count || (x + X) < 0 || (y + Y) < 0 || ((X == 0) && (Y == 0)))
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
					temp[pos] = 1;
				}
			}
			else
			{
				if (neighbours != 2 && neighbours != 3)
				{
					temp[pos] = 0;
				}
			}
		}

        cells = std::move(temp); // Переносимо всі зміни з масиву temp в масив cells
	}

    void render(const Renderer& renderer, int x, int y, int cell_size) const;

    void set_cell(int x, int y, bool live) noexcept {cells[x + y * count] = live;}
    void flip_cell(int x, int y) noexcept {cells[x + y * count] = !cells[x + y * count];}
    int get_size() const noexcept {return count;}
};
