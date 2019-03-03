#pragma once
#include <tuple>
class Cell
{
protected:
	bool life = false;
	int r = 0, g = 0, b = 0;
public:
	Cell() = default;
	Cell(const Cell& cell)
	{
		life = cell.life;
	}
	bool setLife(bool life)
	{
		return this->life = life;
	}
	bool getLife()
	{
		return life;
	}
	bool flipLife()
	{
		return life = !life;
	}
	virtual void setColor(int red, int green, int blue)
	{
		r = red;
		g = green;
		b = blue;
	}
	std::tuple<int, int, int> getColor()
	{
		return std::tuple<int, int, int>{r, g, b};
	}
};
