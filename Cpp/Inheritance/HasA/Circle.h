#pragma once
#include "Point.h"
class Circle
{
public:
	Circle(int x, int y, float radius);
	~Circle();
private:
	class Point point;
	float radius;
};

