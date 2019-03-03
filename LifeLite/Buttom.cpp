#include "Buttom.h"
#include "Renderer.h"
void Buttom::draft(Renderer &a) {
	a.set_color(red, green, blue);
	a.fill_rect(x, y, weight, height);
}
