#pragma once
#include "Cell.h"
class ColorCell :
	public Cell
{
public:
	ColorCell() = default;
	void setColor()
	{
		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;
	}
};

