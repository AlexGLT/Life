#pragma once
#include <iostream>
class Renderer;
class Buttom
{
	int x;
	int y;
	int weight;
	int height;
	int red;
	int blue;
	int green;
public:
	void setpos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setsize(int w, int h)
	{
		this->weight = w;
		this->height = h;
	}
	void setcolor(int red, int blue, int green)
	{
		this->red = red;
		this->blue = blue;
		this->green = green;
	}
	int getx() { return x; }
	int gety() { return y; }
	int getw() { return weight; }
	int geth() { return height; }
	int getred() { return red; }
	int getblue() { return blue; }
	int getgreen() { return green; }
	virtual void draft(Renderer&);
};

