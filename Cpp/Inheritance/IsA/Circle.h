#pragma once
#include "Point.h"
class Circle : public Point
{
public:
	Circle(int x, int y, float radius);
	~Circle();
private:
	float radius;
};

