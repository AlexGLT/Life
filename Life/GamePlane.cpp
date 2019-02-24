#include "GamePlane.h"

#include "Renderer.h"

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
