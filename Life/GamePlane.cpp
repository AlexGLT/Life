#include "GamePlane.h"

#include "Renderer.h"

void GamePlane::update()
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
            if ((neighbours == 2) || neighbours == 3)
            {
                continue;
            }
            else
            {
                temp[pos] = 0;
            }
        }
    }

    cells = std::move(temp); // Переносимо всі зміни з масиву temp в масив cells
}

void GamePlane::render(const Renderer& renderer, int x, int y, int cell_size) const
{
    for (int k = 0; k < count * count; ++k)
    {
        const int i = k / count;
        const int j = k % count;

        renderer.set_color(255, 255, 255);
        if (cells[j + i * count])
            renderer.fill_rect(x + j * cell_size, y + i * cell_size, cell_size, cell_size);

        renderer.set_color(30, 30, 30);
        renderer.draw_line(x, y + i * cell_size, x + count * cell_size, y + i * cell_size);
        renderer.draw_line(x + j * cell_size, y, x + j * cell_size, y + count * cell_size);
    }
    renderer.draw_rect(x, y, count * cell_size + 1, count * cell_size + 1);
    renderer.set_color(0, 0, 0);
}
